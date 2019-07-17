#include <iostream>
#include <vector>
#include <map>

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
  trace t;
  vector<Symbol *> svt = visitor.ST.state_vars();
  vector<Symbol *>::iterator its;
  for (its = svt.begin(); its != svt.end(); its++) {
    string stvar = (*its)->getName();
    t.add_decl_node(stvar);
    string stval = (*its)->getValue();
    t.add_assign_in(stvar, stoi(stval));
  }

  vector<struct entry*>::iterator it;
  for (it = visitor.entries.begin(); it != visitor.entries.end(); it++) {
    vector<struct match_entry_flow*> mef = (*it)->m_f;
    vector<struct match_entry_flow*>::iterator it2;
    vector<struct tracenode*> tmp1, tmp3;
    struct action_flow *af = (*it)->a_f;
    struct match_state *ms = (*it)->m_s;
    struct action_state *as = (*it)->a_s;
    struct tracenode *t3;
    for (it2 = mef.begin(); it2 != mef.end(); it2++) {
      struct match_flow *mf_temp = (*it2)->mf;
      string v = mf_temp->var;
      vector<string> g = visitor.ST.getGranularitybyName(v);
      string c = visitor.ST.getValuebyName(v);
      int val = stoi(c);
      struct tracenode *t1;
      if (mf_temp->match) {
	t1 = t.new_assert_node(pkt_fields[g[0]], "==", val);
      } else {
	t1 = t.new_assert_node(pkt_fields[g[0]], "!=", val);
      }
	tmp1.push_back(t1);
    }
      if(as != NULL && as->state_var != "") {
	string astval = as->state_val;
	string astc = visitor.ST.getValuebyName(astval);
	int astn = stoi(astc);
	struct tracenode *astvar = t.new_assert_node(as->state_var, "=", astn);
	tmp3.push_back(astvar);
      }

      if(af->action == "DROP")
	t3 = t.new_assert_node("DROP", "", 0);
      else if(af->action == "pass")
	t3 = t.new_assert_node("pass", "", 0);
      else
	t3 = NULL;
      
      tmp3.push_back(t3);
      if(ms != NULL && ms->state_var != "") {
	string stval = ms->state_val;
	string stc = visitor.ST.getValuebyName(stval);
	int stn = stoi(stc);
	struct tracenode *tvar = t.new_assert_node(ms->state_var, "==", stn);
	tmp1.push_back(tvar);
      }

      t.add_mlrite_nodes(tmp3, tmp1);
  }
  //t.print_all_paths();
  t.execute();
  //t.print_all_paths();
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
	  visitor.ST.modify((*it_node)->a, to_string((*it_node)->value));
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
  cout << "program name " << nf_name->IDENT()->getText() << endl;
  NFCompilerVisitor visitor;
  antlrcpp::Any v = visitor.visitProgram(nf_name);
  //visitor.ST.printST();
  //visitor.print_entries();
  visitor.CT.printCT();

  int np;
  cout << " No. of packets: ";
  cin >> np;
  create_trace(visitor, 0, np);

  return 0;
}
