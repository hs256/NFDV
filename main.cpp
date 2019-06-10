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
  ifstream stream("model.txt", ios::in);

  ANTLRInputStream input(stream);
  NFCompilerLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  NFCompilerParser parser(&tokens);

  NFCompilerParser::ProgramContext *nf_name = parser.program();
  cout << "program name " << nf_name->IDENT()->getText() << endl;
  NFCompilerVisitor visitor;
  antlrcpp::Any v = visitor.visitProgram(nf_name);
  visitor.ST.printST();
  visitor.print_entry_flow();

  trace t;
  map<struct match_flow*, struct action_flow*>::iterator it;
  for (it = visitor.entry_flow.begin(); it != visitor.entry_flow.end(); it++) {
    struct match_flow *mf = it->first;
    struct action_flow *af = it->second;
    string v = mf->var;
    string g = visitor.ST.getGranularitybyName(v);
    string c = visitor.ST.getValuebyName(v);
    int val = stoi(c);
    t.add_assign_in(pkt_fields[g], val);
    if(af->action == "DROP") {
      cout << "DROP Packet" << endl;
      break;
    }
  }
  t.execute();

  return 0;
}

