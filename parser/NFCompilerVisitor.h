




// Generated from NFCompiler.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "NFCompilerParser.h"
#include "../symboltable.h"
#include "../entry.h"


/**
 * This class defines an abstract visitor for a parse tree
 * produced by NFCompilerParser.
 */
class  NFCompilerVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:
  SymbolTable ST;
  map<struct match_flow*, struct action_flow*> entry_flow; 
  void print_entry_flow();

  /**
   * Visit parse trees produced by NFCompilerParser.
   */
    antlrcpp::Any visitProgram(NFCompilerParser::ProgramContext *context);

/*     antlrcpp::Any visitEntries(NFCompilerParser::EntriesContext *context) = 0;

     antlrcpp::Any visitEntry(NFCompilerParser::EntryContext *context) = 0;

     antlrcpp::Any visitMatch_action(NFCompilerParser::Match_actionContext *context) = 0;

     antlrcpp::Any visitAction_statements(NFCompilerParser::Action_statementsContext *context) = 0;

     antlrcpp::Any visitMatch_flow(NFCompilerParser::Match_flowContext *context) = 0;

     antlrcpp::Any visitMatch_state(NFCompilerParser::Match_stateContext *context) = 0;

     antlrcpp::Any visitAction_flow(NFCompilerParser::Action_flowContext *context) = 0;

     antlrcpp::Any visitAction_state(NFCompilerParser::Action_stateContext *context) = 0;

     antlrcpp::Any visitDeclaration(NFCompilerParser::DeclarationContext *context) = 0;*/

    antlrcpp::Any visitDeclare_entry(NFCompilerParser::Declare_entryContext *context); /*

     antlrcpp::Any visitDec_basic(NFCompilerParser::Dec_basicContext *context) = 0;

     antlrcpp::Any visitDec_set(NFCompilerParser::Dec_setContext *context) = 0;

     antlrcpp::Any visitDec_map(NFCompilerParser::Dec_mapContext *context) = 0;

     antlrcpp::Any visitDec_rule(NFCompilerParser::Dec_ruleContext *context) = 0;

     antlrcpp::Any visitCondition(NFCompilerParser::ConditionContext *context) = 0;

     antlrcpp::Any visitStatement(NFCompilerParser::StatementContext *context) = 0;

     antlrcpp::Any visitAssignment(NFCompilerParser::AssignmentContext *context) = 0;

     antlrcpp::Any visitSingle(NFCompilerParser::SingleContext *context) = 0;

     antlrcpp::Any visitDouble(NFCompilerParser::DoubleContext *context) = 0;

     antlrcpp::Any visitAtom(NFCompilerParser::AtomContext *context) = 0;

     antlrcpp::Any visitId(NFCompilerParser::IdContext *context) = 0;

     antlrcpp::Any visitFunc(NFCompilerParser::FuncContext *context) = 0;

     antlrcpp::Any visitRule_flow(NFCompilerParser::Rule_flowContext *context) = 0;

     antlrcpp::Any visitConst(NFCompilerParser::ConstContext *context) = 0;

     antlrcpp::Any visitSet(NFCompilerParser::SetContext *context) = 0;

     antlrcpp::Any visitMap(NFCompilerParser::MapContext *context) = 0;

     antlrcpp::Any visitLrexp(NFCompilerParser::LrexpContext *context) = 0;

     antlrcpp::Any visitAction(NFCompilerParser::ActionContext *context) = 0;

     antlrcpp::Any visitField(NFCompilerParser::FieldContext *context) = 0;

     antlrcpp::Any visitContents(NFCompilerParser::ContentsContext *context) = 0;

     antlrcpp::Any visitKey_pairs(NFCompilerParser::Key_pairsContext *context) = 0;

     antlrcpp::Any visitKey_value(NFCompilerParser::Key_valueContext *context) = 0;

     antlrcpp::Any visitFunction_call(NFCompilerParser::Function_callContext *context) = 0;

     antlrcpp::Any visitFuncs(NFCompilerParser::FuncsContext *context) = 0;

     antlrcpp::Any visitExpression_list(NFCompilerParser::Expression_listContext *context) = 0;

     antlrcpp::Any visitConst_ip(NFCompilerParser::Const_ipContext *context) = 0;

     antlrcpp::Any visitConst_int(NFCompilerParser::Const_intContext *context) = 0;

     antlrcpp::Any visitFlow_or_rule_entry(NFCompilerParser::Flow_or_rule_entryContext *context) = 0;

     antlrcpp::Any visitOp(NFCompilerParser::OpContext *context) = 0;

     antlrcpp::Any visitExpr_op(NFCompilerParser::Expr_opContext *context) = 0;

     antlrcpp::Any visitRel_op(NFCompilerParser::Rel_opContext *context) = 0;

     antlrcpp::Any visitFields(NFCompilerParser::FieldsContext *context) = 0;
*/

  antlrcpp::Any visitEntries(NFCompilerParser::EntriesContext *ctx);

  antlrcpp::Any visitEntry(NFCompilerParser::EntryContext *ctx);

  antlrcpp::Any visitMatch_action(NFCompilerParser::Match_actionContext *ctx);
  antlrcpp::Any visitAction_statements(NFCompilerParser::Action_statementsContext *ctx);

  antlrcpp::Any visitMatch_flow(NFCompilerParser::Match_flowContext *ctx);

  antlrcpp::Any visitMatch_state(NFCompilerParser::Match_stateContext *ctx);

   antlrcpp::Any visitAction_flow(NFCompilerParser::Action_flowContext *ctx);

   antlrcpp::Any visitAction_state(NFCompilerParser::Action_stateContext *ctx);

   antlrcpp::Any visitDeclaration(NFCompilerParser::DeclarationContext *ctx);

   //antlrcpp::Any visitDeclare_entry(NFCompilerParser::Declare_entryContext *ctx)  {
   // 
  //}

   antlrcpp::Any visitDec_basic(NFCompilerParser::Dec_basicContext *ctx);
   antlrcpp::Any visitDec_set(NFCompilerParser::Dec_setContext *ctx);
   antlrcpp::Any visitDec_map(NFCompilerParser::Dec_mapContext *ctx);
   antlrcpp::Any visitDec_rule(NFCompilerParser::Dec_ruleContext *ctx);
   antlrcpp::Any visitCondition(NFCompilerParser::ConditionContext *ctx);
   antlrcpp::Any visitStatement(NFCompilerParser::StatementContext *ctx);
   antlrcpp::Any visitAssignment(NFCompilerParser::AssignmentContext *ctx);
   antlrcpp::Any visitSingle(NFCompilerParser::SingleContext *ctx);
   antlrcpp::Any visitDouble(NFCompilerParser::DoubleContext *ctx);
   antlrcpp::Any visitAtom(NFCompilerParser::AtomContext *ctx);
   antlrcpp::Any visitId(NFCompilerParser::IdContext *ctx);
   antlrcpp::Any visitFunc(NFCompilerParser::FuncContext *ctx);
   antlrcpp::Any visitRule_flow(NFCompilerParser::Rule_flowContext *ctx);
   antlrcpp::Any visitConst(NFCompilerParser::ConstContext *ctx);
   antlrcpp::Any visitSet(NFCompilerParser::SetContext *ctx);
   antlrcpp::Any visitMap(NFCompilerParser::MapContext *ctx);
   antlrcpp::Any visitLrexp(NFCompilerParser::LrexpContext *ctx);
   antlrcpp::Any visitAction(NFCompilerParser::ActionContext *ctx);
   antlrcpp::Any visitField(NFCompilerParser::FieldContext *ctx);

   antlrcpp::Any visitContents(NFCompilerParser::ContentsContext *ctx);

   antlrcpp::Any visitKey_pairs(NFCompilerParser::Key_pairsContext *ctx);
 
   antlrcpp::Any visitKey_value(NFCompilerParser::Key_valueContext *ctx);

   antlrcpp::Any visitFunction_call(NFCompilerParser::Function_callContext *ctx);

   antlrcpp::Any visitFuncs(NFCompilerParser::FuncsContext *ctx);

   antlrcpp::Any visitExpression_list(NFCompilerParser::Expression_listContext *ctx);
  
   antlrcpp::Any visitConst_ip(NFCompilerParser::Const_ipContext *ctx);

   antlrcpp::Any visitConst_int(NFCompilerParser::Const_intContext *ctx);

   antlrcpp::Any visitFlow_or_rule_entry(NFCompilerParser::Flow_or_rule_entryContext *ctx);
    
   antlrcpp::Any visitOp(NFCompilerParser::OpContext *ctx);
    
   antlrcpp::Any visitExpr_op(NFCompilerParser::Expr_opContext *ctx);
    
   antlrcpp::Any visitRel_op(NFCompilerParser::Rel_opContext *ctx);
    
   antlrcpp::Any visitFields(NFCompilerParser::FieldsContext *ctx);
  
};

