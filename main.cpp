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
    //cout << "visitor entries" << endl;
    struct match_flow *mf = (*it)->m_f;
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
    if(af->action == "DROP") {
      //cout << "DROP Packet" << endl;
      t3 = t.new_assert_node("DROP", "", 0);
//      t.add_ite_node(t1, t2, NULL);
      //break;
    } else if(af->action == "pass") {
	t3 = t.new_assert_node("pass", "", 0);
    } else
	t3 = NULL;
    
    t.add_ite_node(t1, t2, t3);
  }
  //t.print_all_paths();
  t.execute();
  t.print_all_paths();

  return 0;
}

