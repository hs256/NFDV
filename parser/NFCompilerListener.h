




// Generated from NFCompiler.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "NFCompilerParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by NFCompilerParser.
 */
class  NFCompilerListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(NFCompilerParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(NFCompilerParser::ProgramContext *ctx) = 0;

  virtual void enterEntries(NFCompilerParser::EntriesContext *ctx) = 0;
  virtual void exitEntries(NFCompilerParser::EntriesContext *ctx) = 0;

  virtual void enterEntry(NFCompilerParser::EntryContext *ctx) = 0;
  virtual void exitEntry(NFCompilerParser::EntryContext *ctx) = 0;

  virtual void enterMatch_action(NFCompilerParser::Match_actionContext *ctx) = 0;
  virtual void exitMatch_action(NFCompilerParser::Match_actionContext *ctx) = 0;

  virtual void enterAction_statements(NFCompilerParser::Action_statementsContext *ctx) = 0;
  virtual void exitAction_statements(NFCompilerParser::Action_statementsContext *ctx) = 0;

  virtual void enterMatch_flow(NFCompilerParser::Match_flowContext *ctx) = 0;
  virtual void exitMatch_flow(NFCompilerParser::Match_flowContext *ctx) = 0;

  virtual void enterMatch_state(NFCompilerParser::Match_stateContext *ctx) = 0;
  virtual void exitMatch_state(NFCompilerParser::Match_stateContext *ctx) = 0;

  virtual void enterAction_flow(NFCompilerParser::Action_flowContext *ctx) = 0;
  virtual void exitAction_flow(NFCompilerParser::Action_flowContext *ctx) = 0;

  virtual void enterAction_state(NFCompilerParser::Action_stateContext *ctx) = 0;
  virtual void exitAction_state(NFCompilerParser::Action_stateContext *ctx) = 0;

  virtual void enterDeclaration(NFCompilerParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(NFCompilerParser::DeclarationContext *ctx) = 0;

  virtual void enterDeclare_entry(NFCompilerParser::Declare_entryContext *ctx) = 0;
  virtual void exitDeclare_entry(NFCompilerParser::Declare_entryContext *ctx) = 0;

  virtual void enterDec_basic(NFCompilerParser::Dec_basicContext *ctx) = 0;
  virtual void exitDec_basic(NFCompilerParser::Dec_basicContext *ctx) = 0;

  virtual void enterDec_set(NFCompilerParser::Dec_setContext *ctx) = 0;
  virtual void exitDec_set(NFCompilerParser::Dec_setContext *ctx) = 0;

  virtual void enterDec_map(NFCompilerParser::Dec_mapContext *ctx) = 0;
  virtual void exitDec_map(NFCompilerParser::Dec_mapContext *ctx) = 0;

  virtual void enterDec_rule(NFCompilerParser::Dec_ruleContext *ctx) = 0;
  virtual void exitDec_rule(NFCompilerParser::Dec_ruleContext *ctx) = 0;

  virtual void enterCondition(NFCompilerParser::ConditionContext *ctx) = 0;
  virtual void exitCondition(NFCompilerParser::ConditionContext *ctx) = 0;

  virtual void enterStatement(NFCompilerParser::StatementContext *ctx) = 0;
  virtual void exitStatement(NFCompilerParser::StatementContext *ctx) = 0;

  virtual void enterAssignment(NFCompilerParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(NFCompilerParser::AssignmentContext *ctx) = 0;

  virtual void enterSingle(NFCompilerParser::SingleContext *ctx) = 0;
  virtual void exitSingle(NFCompilerParser::SingleContext *ctx) = 0;

  virtual void enterDouble(NFCompilerParser::DoubleContext *ctx) = 0;
  virtual void exitDouble(NFCompilerParser::DoubleContext *ctx) = 0;

  virtual void enterAtom(NFCompilerParser::AtomContext *ctx) = 0;
  virtual void exitAtom(NFCompilerParser::AtomContext *ctx) = 0;

  virtual void enterId(NFCompilerParser::IdContext *ctx) = 0;
  virtual void exitId(NFCompilerParser::IdContext *ctx) = 0;

  virtual void enterFunc(NFCompilerParser::FuncContext *ctx) = 0;
  virtual void exitFunc(NFCompilerParser::FuncContext *ctx) = 0;

  virtual void enterRule_flow(NFCompilerParser::Rule_flowContext *ctx) = 0;
  virtual void exitRule_flow(NFCompilerParser::Rule_flowContext *ctx) = 0;

  virtual void enterConst(NFCompilerParser::ConstContext *ctx) = 0;
  virtual void exitConst(NFCompilerParser::ConstContext *ctx) = 0;

  virtual void enterSet(NFCompilerParser::SetContext *ctx) = 0;
  virtual void exitSet(NFCompilerParser::SetContext *ctx) = 0;

  virtual void enterMap(NFCompilerParser::MapContext *ctx) = 0;
  virtual void exitMap(NFCompilerParser::MapContext *ctx) = 0;

  virtual void enterLrexp(NFCompilerParser::LrexpContext *ctx) = 0;
  virtual void exitLrexp(NFCompilerParser::LrexpContext *ctx) = 0;

  virtual void enterAction(NFCompilerParser::ActionContext *ctx) = 0;
  virtual void exitAction(NFCompilerParser::ActionContext *ctx) = 0;

  virtual void enterField(NFCompilerParser::FieldContext *ctx) = 0;
  virtual void exitField(NFCompilerParser::FieldContext *ctx) = 0;

  virtual void enterContents(NFCompilerParser::ContentsContext *ctx) = 0;
  virtual void exitContents(NFCompilerParser::ContentsContext *ctx) = 0;

  virtual void enterKey_pairs(NFCompilerParser::Key_pairsContext *ctx) = 0;
  virtual void exitKey_pairs(NFCompilerParser::Key_pairsContext *ctx) = 0;

  virtual void enterKey_value(NFCompilerParser::Key_valueContext *ctx) = 0;
  virtual void exitKey_value(NFCompilerParser::Key_valueContext *ctx) = 0;

  virtual void enterFunction_call(NFCompilerParser::Function_callContext *ctx) = 0;
  virtual void exitFunction_call(NFCompilerParser::Function_callContext *ctx) = 0;

  virtual void enterFuncs(NFCompilerParser::FuncsContext *ctx) = 0;
  virtual void exitFuncs(NFCompilerParser::FuncsContext *ctx) = 0;

  virtual void enterExpression_list(NFCompilerParser::Expression_listContext *ctx) = 0;
  virtual void exitExpression_list(NFCompilerParser::Expression_listContext *ctx) = 0;

  virtual void enterConst_ip(NFCompilerParser::Const_ipContext *ctx) = 0;
  virtual void exitConst_ip(NFCompilerParser::Const_ipContext *ctx) = 0;

  virtual void enterConst_int(NFCompilerParser::Const_intContext *ctx) = 0;
  virtual void exitConst_int(NFCompilerParser::Const_intContext *ctx) = 0;

  virtual void enterFlow_or_rule_entry(NFCompilerParser::Flow_or_rule_entryContext *ctx) = 0;
  virtual void exitFlow_or_rule_entry(NFCompilerParser::Flow_or_rule_entryContext *ctx) = 0;

  virtual void enterOp(NFCompilerParser::OpContext *ctx) = 0;
  virtual void exitOp(NFCompilerParser::OpContext *ctx) = 0;

  virtual void enterExpr_op(NFCompilerParser::Expr_opContext *ctx) = 0;
  virtual void exitExpr_op(NFCompilerParser::Expr_opContext *ctx) = 0;

  virtual void enterRel_op(NFCompilerParser::Rel_opContext *ctx) = 0;
  virtual void exitRel_op(NFCompilerParser::Rel_opContext *ctx) = 0;

  virtual void enterFields(NFCompilerParser::FieldsContext *ctx) = 0;
  virtual void exitFields(NFCompilerParser::FieldsContext *ctx) = 0;


};

