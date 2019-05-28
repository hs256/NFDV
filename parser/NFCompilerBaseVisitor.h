




// Generated from NFCompiler.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "NFCompilerVisitor.h"


/**
 * This class provides an empty implementation of NFCompilerVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  NFCompilerBaseVisitor : public NFCompilerVisitor {
public:

  virtual antlrcpp::Any visitProgram(NFCompilerParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntries(NFCompilerParser::EntriesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntry(NFCompilerParser::EntryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatch_action(NFCompilerParser::Match_actionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAction_statements(NFCompilerParser::Action_statementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatch_flow(NFCompilerParser::Match_flowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatch_state(NFCompilerParser::Match_stateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAction_flow(NFCompilerParser::Action_flowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAction_state(NFCompilerParser::Action_stateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(NFCompilerParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclare_entry(NFCompilerParser::Declare_entryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDec_basic(NFCompilerParser::Dec_basicContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDec_set(NFCompilerParser::Dec_setContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDec_map(NFCompilerParser::Dec_mapContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDec_rule(NFCompilerParser::Dec_ruleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition(NFCompilerParser::ConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(NFCompilerParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(NFCompilerParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSingle(NFCompilerParser::SingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDouble(NFCompilerParser::DoubleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtom(NFCompilerParser::AtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitId(NFCompilerParser::IdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunc(NFCompilerParser::FuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRule_flow(NFCompilerParser::Rule_flowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConst(NFCompilerParser::ConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSet(NFCompilerParser::SetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMap(NFCompilerParser::MapContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLrexp(NFCompilerParser::LrexpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAction(NFCompilerParser::ActionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitField(NFCompilerParser::FieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitContents(NFCompilerParser::ContentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKey_pairs(NFCompilerParser::Key_pairsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKey_value(NFCompilerParser::Key_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_call(NFCompilerParser::Function_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncs(NFCompilerParser::FuncsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression_list(NFCompilerParser::Expression_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConst_ip(NFCompilerParser::Const_ipContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConst_int(NFCompilerParser::Const_intContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlow_or_rule_entry(NFCompilerParser::Flow_or_rule_entryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp(NFCompilerParser::OpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr_op(NFCompilerParser::Expr_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRel_op(NFCompilerParser::Rel_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFields(NFCompilerParser::FieldsContext *ctx) override {
    return visitChildren(ctx);
  }


};

