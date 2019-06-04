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

  //trace t;

  return 0;
}

