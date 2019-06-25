




// Generated from NFCompiler.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "NFCompilerListener.h"


/**
 * This class provides an empty implementation of NFCompilerListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  NFCompilerBaseListener : public NFCompilerListener {
public:

  virtual void enterProgram(NFCompilerParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(NFCompilerParser::ProgramContext * /*ctx*/) override { }

  virtual void enterEntries(NFCompilerParser::EntriesContext * /*ctx*/) override { }
  virtual void exitEntries(NFCompilerParser::EntriesContext * /*ctx*/) override { }

  virtual void enterEntry(NFCompilerParser::EntryContext * /*ctx*/) override { }
  virtual void exitEntry(NFCompilerParser::EntryContext * /*ctx*/) override { }

  virtual void enterMatch_action(NFCompilerParser::Match_actionContext * /*ctx*/) override { }
  virtual void exitMatch_action(NFCompilerParser::Match_actionContext * /*ctx*/) override { }

  virtual void enterAction_statements(NFCompilerParser::Action_statementsContext * /*ctx*/) override { }
  virtual void exitAction_statements(NFCompilerParser::Action_statementsContext * /*ctx*/) override { }

  virtual void enterMatch_flow(NFCompilerParser::Match_flowContext * /*ctx*/) override { }
  virtual void exitMatch_flow(NFCompilerParser::Match_flowContext * /*ctx*/) override { }

  virtual void enterMatch_state(NFCompilerParser::Match_stateContext * /*ctx*/) override { }
  virtual void exitMatch_state(NFCompilerParser::Match_stateContext * /*ctx*/) override { }

  virtual void enterAction_flow(NFCompilerParser::Action_flowContext * /*ctx*/) override { }
  virtual void exitAction_flow(NFCompilerParser::Action_flowContext * /*ctx*/) override { }

  virtual void enterAction_state(NFCompilerParser::Action_stateContext * /*ctx*/) override { }
  virtual void exitAction_state(NFCompilerParser::Action_stateContext * /*ctx*/) override { }

  virtual void enterDeclaration(NFCompilerParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(NFCompilerParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterDeclare_entry(NFCompilerParser::Declare_entryContext * /*ctx*/) override { }
  virtual void exitDeclare_entry(NFCompilerParser::Declare_entryContext * /*ctx*/) override { }

  virtual void enterDec_basic(NFCompilerParser::Dec_basicContext * /*ctx*/) override { }
  virtual void exitDec_basic(NFCompilerParser::Dec_basicContext * /*ctx*/) override { }

  virtual void enterDec_set(NFCompilerParser::Dec_setContext * /*ctx*/) override { }
  virtual void exitDec_set(NFCompilerParser::Dec_setContext * /*ctx*/) override { }

  virtual void enterDec_map(NFCompilerParser::Dec_mapContext * /*ctx*/) override { }
  virtual void exitDec_map(NFCompilerParser::Dec_mapContext * /*ctx*/) override { }

  virtual void enterDec_rule(NFCompilerParser::Dec_ruleContext * /*ctx*/) override { }
  virtual void exitDec_rule(NFCompilerParser::Dec_ruleContext * /*ctx*/) override { }

  virtual void enterCondition(NFCompilerParser::ConditionContext * /*ctx*/) override { }
  virtual void exitCondition(NFCompilerParser::ConditionContext * /*ctx*/) override { }

  virtual void enterStatement(NFCompilerParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(NFCompilerParser::StatementContext * /*ctx*/) override { }

  virtual void enterAssignment(NFCompilerParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(NFCompilerParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterSingle(NFCompilerParser::SingleContext * /*ctx*/) override { }
  virtual void exitSingle(NFCompilerParser::SingleContext * /*ctx*/) override { }

  virtual void enterDouble(NFCompilerParser::DoubleContext * /*ctx*/) override { }
  virtual void exitDouble(NFCompilerParser::DoubleContext * /*ctx*/) override { }

  virtual void enterAtom(NFCompilerParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(NFCompilerParser::AtomContext * /*ctx*/) override { }

  virtual void enterId(NFCompilerParser::IdContext * /*ctx*/) override { }
  virtual void exitId(NFCompilerParser::IdContext * /*ctx*/) override { }

  virtual void enterFunc(NFCompilerParser::FuncContext * /*ctx*/) override { }
  virtual void exitFunc(NFCompilerParser::FuncContext * /*ctx*/) override { }

  virtual void enterRule_flow(NFCompilerParser::Rule_flowContext * /*ctx*/) override { }
  virtual void exitRule_flow(NFCompilerParser::Rule_flowContext * /*ctx*/) override { }

  virtual void enterConst(NFCompilerParser::ConstContext * /*ctx*/) override { }
  virtual void exitConst(NFCompilerParser::ConstContext * /*ctx*/) override { }

  virtual void enterSet(NFCompilerParser::SetContext * /*ctx*/) override { }
  virtual void exitSet(NFCompilerParser::SetContext * /*ctx*/) override { }

  virtual void enterMap(NFCompilerParser::MapContext * /*ctx*/) override { }
  virtual void exitMap(NFCompilerParser::MapContext * /*ctx*/) override { }

  virtual void enterLrexp(NFCompilerParser::LrexpContext * /*ctx*/) override { }
  virtual void exitLrexp(NFCompilerParser::LrexpContext * /*ctx*/) override { }

  virtual void enterAction(NFCompilerParser::ActionContext * /*ctx*/) override { }
  virtual void exitAction(NFCompilerParser::ActionContext * /*ctx*/) override { }

  virtual void enterField(NFCompilerParser::FieldContext * /*ctx*/) override { }
  virtual void exitField(NFCompilerParser::FieldContext * /*ctx*/) override { }

  virtual void enterNew_packet(NFCompilerParser::New_packetContext * /*ctx*/) override { }
  virtual void exitNew_packet(NFCompilerParser::New_packetContext * /*ctx*/) override { }

  virtual void enterContents(NFCompilerParser::ContentsContext * /*ctx*/) override { }
  virtual void exitContents(NFCompilerParser::ContentsContext * /*ctx*/) override { }

  virtual void enterKey_pairs(NFCompilerParser::Key_pairsContext * /*ctx*/) override { }
  virtual void exitKey_pairs(NFCompilerParser::Key_pairsContext * /*ctx*/) override { }

  virtual void enterKey_value(NFCompilerParser::Key_valueContext * /*ctx*/) override { }
  virtual void exitKey_value(NFCompilerParser::Key_valueContext * /*ctx*/) override { }

  virtual void enterFunction_call(NFCompilerParser::Function_callContext * /*ctx*/) override { }
  virtual void exitFunction_call(NFCompilerParser::Function_callContext * /*ctx*/) override { }

  virtual void enterFuncs(NFCompilerParser::FuncsContext * /*ctx*/) override { }
  virtual void exitFuncs(NFCompilerParser::FuncsContext * /*ctx*/) override { }

  virtual void enterExpression_list(NFCompilerParser::Expression_listContext * /*ctx*/) override { }
  virtual void exitExpression_list(NFCompilerParser::Expression_listContext * /*ctx*/) override { }

  virtual void enterConst_ip(NFCompilerParser::Const_ipContext * /*ctx*/) override { }
  virtual void exitConst_ip(NFCompilerParser::Const_ipContext * /*ctx*/) override { }

  virtual void enterConst_int(NFCompilerParser::Const_intContext * /*ctx*/) override { }
  virtual void exitConst_int(NFCompilerParser::Const_intContext * /*ctx*/) override { }

  virtual void enterFlow_or_rule_entry(NFCompilerParser::Flow_or_rule_entryContext * /*ctx*/) override { }
  virtual void exitFlow_or_rule_entry(NFCompilerParser::Flow_or_rule_entryContext * /*ctx*/) override { }

  virtual void enterOp(NFCompilerParser::OpContext * /*ctx*/) override { }
  virtual void exitOp(NFCompilerParser::OpContext * /*ctx*/) override { }

  virtual void enterExpr_op(NFCompilerParser::Expr_opContext * /*ctx*/) override { }
  virtual void exitExpr_op(NFCompilerParser::Expr_opContext * /*ctx*/) override { }

  virtual void enterRel_op(NFCompilerParser::Rel_opContext * /*ctx*/) override { }
  virtual void exitRel_op(NFCompilerParser::Rel_opContext * /*ctx*/) override { }

  virtual void enterFields(NFCompilerParser::FieldsContext * /*ctx*/) override { }
  virtual void exitFields(NFCompilerParser::FieldsContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

