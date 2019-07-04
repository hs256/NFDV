#include <iostream>
#include <vector>

#include "antlr/antlr4-runtime.h"
#include "parser/NFCompilerLexer.h"
#include "parser/NFCompilerParser.h"
#include "parser/NFCompilerVisitor.h"
#include "symboltable.h"
#include "instructions.h"
#include "trace.h"
#include "pkt.h"

using namespace std;

using namespace antlr4;

int main(int argc, const char *argv) {
  ifstream stream("model2.txt", ios::in);

  ANTLRInputStream input(stream);
  NFCompilerLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  NFCompilerParser parser(&tokens);

  NFCompilerParser::ProgramContext *nf_name = parser.program();
  cout << "program name " << nf_name->IDENT()->getText() << endl;
  NFCompilerVisitor visitor;
  antlrcpp::Any v = visitor.visitProgram(nf_name);
  visitor.ST.printST();
  visitor.print_entries();

  trace t;
  //map<struct match_flow*, struct action_flow*>::reverse_iterator it;
  vector<struct entry*>::iterator it;
  for (it = visitor.entries.begin(); it != visitor.entries.end(); it++) {
    if ((*it)->m_f.size() == 1) {
      struct match_entry_flow *mef = ((*it)->m_f)[0];
      struct match_flow *mf = mef->mf;
      struct action_flow *af = (*it)->a_f;
      string v = mf->var;
      vector<string> g = visitor.ST.getGranularitybyName(v);
      string c = visitor.ST.getValuebyName(v);
      int val = stoi(c);
      //cout << pkt_fields[g] << " " << val << endl;
      struct tracenode *t1, *t2, *t3;
      if (mf->match) {
	t1 = t.new_assert_node(pkt_fields[g[0]], "==", val);
	t2 = t.new_assert_node(pkt_fields[g[0]], "!=", val);
      } else {
	t1 = t.new_assert_node(pkt_fields[g[0]], "!=", val);
	t2 = t.new_assert_node(pkt_fields[g[0]], "==", val);
      }
      //t.add_assign_in(pkt_fields[g], val);
      if(af->action == "DROP")
	t3 = t.new_assert_node("DROP", "", 0);
      else if(af->action == "pass")
	t3 = t.new_assert_node("pass", "", 0);
      else
	t3 = NULL;
    
    t.add_ite_node(t1, t2, t3);
  } else {
      vector<struct match_entry_flow*> mef = (*it)->m_f;
      vector<struct match_entry_flow*>::iterator it2;
      vector<struct tracenode*> tmp1, tmp2;
      for (it2 = mef.begin(); it2 != mef.end(); it2++) {
	struct match_flow *mf_temp = (*it2)->mf;
	string v = mf_temp->var;
	vector<string> g = visitor.ST.getGranularitybyName(v);
	string c = visitor.ST.getValuebyName(v);
	int val = stoi(c);
	struct tracenode *t1, *t2;
	if (mf_temp->match) {
	  t1 = t.new_assert_node(pkt_fields[g[0]], "==", val);
	  t2 = t.new_assert_node(pkt_fields[g[0]], "!=", val);
	} else {
	  t1 = t.new_assert_node(pkt_fields[g[0]], "!=", val);
	  t2 = t.new_assert_node(pkt_fields[g[0]], "!=", val);
	}
	tmp1.push_back(t1);
	tmp2.push_back(t2);
      }
      struct action_flow *af = (*it)->a_f;
      struct tracenode *t3;
      if(af->action == "DROP")
	t3 = t.new_assert_node("DROP", "", 0);
      else if(af->action == "pass")
	t3 = t.new_assert_node("pass", "", 0);
      else
	t3 = NULL;
      t.add_mite_node(tmp1, tmp2, t3);
    }
  }
  //t.print_all_paths();
  t.execute();
  t.print_all_paths();

  return 0;
}

