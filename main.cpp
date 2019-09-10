#include <iostream>
#include <vector>
#include <map>
#include <chrono>

#include "antlr/antlr4-runtime.h"
#include "parser/NFCompilerLexer.h"
#include "parser/NFCompilerParser.h"
#include "parser/NFCompilerVisitor.h"
#include "symboltable.h"
#include "instructions.h"
#include "trace.h"
//#include "pkt.h"

using namespace std;

using namespace antlr4;

map<string, string> pkt_fields {
  {"sip", "L3+96"},
  {"dip", "L3+128"},
  {"proto", "L3+72"},
  {"sport", "L4+0"},
  {"dport", "L4+16"},
  {"flag_ack", "L4+107"},
  {"flag_rst", "L4+109"},
  {"flag_syn", "L4+110"},
  {"flag_fin", "L4+111"}
};

void create_trace(NFCompilerVisitor visitor, int index, int np) {
  trace t(index+1);
  vector<Symbol *> svt = visitor.ST.state_vars();
  vector<Symbol *>::iterator its;
  for (its = svt.begin(); its != svt.end(); its++) {
    string stvar = (*its)->getName();
    t.add_decl_node(stvar);
    string stval = (*its)->getValue();
    if(stval != "") {
      try {
	int stvalc = stoi(stval);
	t.add_assign_in(stvar, stvalc);
      } catch (const invalid_argument& ia) {
	t.add_ct_node(stvar, "", stval, "=", 0); 
      }
    }
  }

  vector<struct entry*>::iterator it;
  for (it = visitor.entries.begin(); it != visitor.entries.end(); it++) {
    vector<struct match_entry_flow*> mef = (*it)->m_f;
    vector<struct match_entry_flow*>::iterator it2;
    vector<struct match_entry_state*> mes = (*it)->m_s;
    vector<struct match_entry_state*>::iterator it3;
    vector<struct tracenode*> tmp1, tmp3;
    struct action_flow *af = (*it)->a_f;
    vector<struct action_state *> asv = ((*it)->a_s);
    vector<struct action_state *>::iterator itas;
    struct tracenode *t1, *t3;
    for (it2 = mef.begin(); it2 != mef.end(); it2++) {
      struct match_flow *mf_temp = (*it2)->mf;
      string v = mf_temp->var;
      if (visitor.ST.find(v) != NULL) {
	vector<string> g = visitor.ST.getGranularitybyName(v);
	string c = visitor.ST.getValuebyName(v);
	int val = stoi(c);
	if (mf_temp->match) {
	  t1 = t.new_assert_node(pkt_fields[g[0]], "==", val);
	} else {
	  t1 = t.new_assert_node(pkt_fields[g[0]], "!=", val);
	}
	  tmp1.push_back(t1);
      } else if (visitor.CT.find(v) != NULL) {
	if (mf_temp->match) {
	  t1 = t.new_ct_node(visitor.CT.getc1byName(v) + to_string(index+1), visitor.CT.getop1byName(v), visitor.CT.getc2byName(v), visitor.CT.getop2byName(v), visitor.CT.getcvalbyName(v));
	  tmp1.push_back(t1);
	} else if (!mf_temp->match && visitor.CT.getop2byName(v) == "<=") {
	  t1 = t.new_ct_node(visitor.CT.getc1byName(v) + to_string(index+1), visitor.CT.getop1byName(v), visitor.CT.getc2byName(v), ">", visitor.CT.getcvalbyName(v));
	  tmp1.push_back(t1);
	}
      }
    }

    for (itas = asv.begin(); itas != asv.end(); itas++) {
	  struct action_state *as = (*itas);
	  if(as != NULL && as->state_var != "") {
	    string astval = as->state_val;
	    if (visitor.ST.find(astval) != NULL) {
	      string astc = visitor.ST.getValuebyName(astval);
	      int astn = stoi(astc);
	      struct tracenode *astvar = t.new_assert_node(as->state_var, "=", astn);
	      tmp3.push_back(astvar);
	    } else if (astval != "") {
	      try {
		int astval_n = stoi(astval);
		string astval_n_str = to_string(astval_n);
		struct tracenode *astn = t.new_ct_node(as->state_var, "", astval_n_str, "=", 0);
		tmp3.push_back(astn);
	      } catch (...) {
		char plus = '+';
		char mul = '*';
		char minus = '-';
		size_t plus_found = astval.find(plus);
		size_t mul_found = astval.find(mul);
		size_t minus_found = astval.find(minus);
		if (plus_found != string::npos) {
		  int inc_val = 0;
		  auto start = 0U;
		  start = plus_found + 1;
		  plus_found = astval.find(plus, start);
		  inc_val = stoi(astval.substr(start, plus_found));
		  if(visitor.ST.find(as->state_var)) {
		    string astval_i = visitor.ST.getValuebyName(as->state_var);
		    try {
		      int astval_i1 = stoi(astval_i);
		      astval_i1 = astval_i1 + inc_val;
		      struct tracenode *astn = t.new_ct_node(as->state_var, "", to_string(astval_i1), "=", 0);
		      tmp3.push_back(astn);
		    } catch (...) {
		    }
		  }
		} else if (minus_found != string::npos) {
		  int dec_val = 0;
		  auto start = 0U;
		  start = minus_found + 1;
		  minus_found = astval.find(minus, start);
		  dec_val = stoi(astval.substr(start, minus_found));
		  if(visitor.ST.find(as->state_var)) {
		    string astval_i = visitor.ST.getValuebyName(as->state_var);
		    try {
		      int astval_i1 = stoi(astval_i);
		      astval_i1 = astval_i1 - dec_val;
		      struct tracenode *astn = t.new_ct_node(as->state_var, "", to_string(astval_i1), "=", 0);
		      tmp3.push_back(astn);
		    } catch (...) {
		    }
		  }
		} else if (mul_found != string::npos) {
		  string mul_val;
		  auto start = 0U;
		  start = mul_found + 1;
		  mul_found = astval.find(mul, start);
		  mul_val = astval.substr(start, mul_found);
		  if(visitor.ST.find(mul_val)) {
		    mul_val = visitor.ST.getValuebyName(mul_val);
		  }
		  if (visitor.ST.find(as->state_var)) {
		    string astval_i = visitor.ST.getValuebyName(as->state_var);
		    try {
		      double astval_i1 = (double)stoi(astval_i);
		      double mul_val_ = ::atof(mul_val.c_str());
		      astval_i1 = astval_i1 * mul_val_;
		      struct tracenode *astn = t.new_ct_node(as->state_var, "", to_string(astval_i1), "=", 0);
		      tmp3.push_back(astn);
		    } catch (...) {
		    }
		  }
		} else {
		  string astval_n = astval + to_string(index+1);
		  struct tracenode *astn = t.new_ct_node(as->state_var, "", astval_n, "=", 0);
		  tmp3.push_back(astn);
		}
	      }
	    }
	  }
    }

      if(af->action == "DROP")
	t3 = t.new_assert_node("DROP", "", 0);
      else if(af->action == "pass")
	t3 = t.new_assert_node("pass", "", 0);
      else
	t3 = NULL;
      
      tmp3.push_back(t3);
      for (it3 = mes.begin(); it3 != mes.end(); it3++) {
	struct match_state *ms_temp = (*it3)->ms;
	if(ms_temp != NULL && ms_temp->state_var != "") {
	  string stval = ms_temp->state_val;
	  if (visitor.ST.find(stval) != NULL) {
	    string stc = visitor.ST.getValuebyName(stval);
	    int stn = stoi(stc);
	    struct tracenode *tvar = t.new_assert_node(ms_temp->state_var, ms_temp->op, stn);
	    tmp1.push_back(tvar);
	  } else {
	    int stn = stoi(stval);
	    struct tracenode *tvar = t.new_assert_node(ms_temp->state_var, ms_temp->op, stn);
	    tmp1.push_back(tvar);
	  }  
      }
      }

      t.add_mlrite_nodes(tmp3, tmp1);
  }
  //auto total_start = chrono::high_resolution_clock::now();
  //t.print_all_paths();
  //auto start = chrono::high_resolution_clock::now();
  t.execute();
  //auto stop = chrono::high_resolution_clock::now();
  //t.print_all_paths();
  //auto total_stop = chrono::high_resolution_clock::now();
  //auto total_duration = chrono::duration_cast<chrono::microseconds>(total_stop - total_start);
  //auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
  //cout << "time taken in z3 : " << duration.count() << " out of total " << total_duration.count() << endl;
  vector<vector <struct tracenode *>> paths = t.return_all_paths();
  vector<vector<struct tracenode *>>::iterator it_path;
  for (it_path = paths.begin(); it_path != paths.end(); it_path++) {
    vector<struct tracenode *> path = (*it_path);
    cout << "PACKET: " << index+1 << endl;
    t.print_path(path);
    vector<struct tracenode *>::iterator it_node;
    for (it_node = path.begin(); it_node != path.end(); it_node++) {
      if((*it_node)->op == "=" || (*it_node)->decl == 2) {
	if (visitor.ST.find((*it_node)->a)) {
	  if ((*it_node)->b == "") {
	    visitor.ST.modify((*it_node)->a, to_string((*it_node)->value));
	  } else {
	    //string new_val = (*it_node)->b + to_string(index+1);
	    string new_val = (*it_node)->b;
	    visitor.ST.modify((*it_node)->a, new_val);
	  }
	}
      }
    }
    if (index < np-1) {
      create_trace(visitor, index+1, np);
    }
  }

}

int main(int argc, char *argv[]) {
  char *filename;
  if (argc > 1) {
    filename = argv[1];
  } else {
    cout << "input filename" << endl;
    return 0;
  }

  ifstream stream(filename, ios::in);

  ANTLRInputStream input(stream);
  NFCompilerLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  NFCompilerParser parser(&tokens);

  NFCompilerParser::ProgramContext *nf_name = parser.program();
  //cout << "program name " << nf_name->IDENT()->getText() << endl;
  NFCompilerVisitor visitor;
  antlrcpp::Any v = visitor.visitProgram(nf_name);
  //visitor.ST.printST();
  //visitor.print_entries();
  //visitor.CT.printCT();

  int np;
  cout << " No. of packets: ";
  cin >> np;
  auto start = chrono::high_resolution_clock::now();
  create_trace(visitor, 0, np);
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
  cout << "time taken " << duration.count() << endl; 

  return 0;
}
