




// Generated from NFCompiler.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "NFCompilerParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by NFCompilerParser.
 */
class  NFCompilerVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by NFCompilerParser.
   */
    virtual antlrcpp::Any visitProgram(NFCompilerParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitEntries(NFCompilerParser::EntriesContext *context) = 0;

    virtual antlrcpp::Any visitEntry(NFCompilerParser::EntryContext *context) = 0;

    virtual antlrcpp::Any visitMatch_action(NFCompilerParser::Match_actionContext *context) = 0;

    virtual antlrcpp::Any visitAction_statements(NFCompilerParser::Action_statementsContext *context) = 0;

    virtual antlrcpp::Any visitMatch_flow(NFCompilerParser::Match_flowContext *context) = 0;

    virtual antlrcpp::Any visitMatch_state(NFCompilerParser::Match_stateContext *context) = 0;

    virtual antlrcpp::Any visitAction_flow(NFCompilerParser::Action_flowContext *context) = 0;

    virtual antlrcpp::Any visitAction_state(NFCompilerParser::Action_stateContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(NFCompilerParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitDeclare_entry(NFCompilerParser::Declare_entryContext *context) = 0;

    virtual antlrcpp::Any visitDec_basic(NFCompilerParser::Dec_basicContext *context) = 0;

    virtual antlrcpp::Any visitDec_set(NFCompilerParser::Dec_setContext *context) = 0;

    virtual antlrcpp::Any visitDec_map(NFCompilerParser::Dec_mapContext *context) = 0;

    virtual antlrcpp::Any visitDec_rule(NFCompilerParser::Dec_ruleContext *context) = 0;

    virtual antlrcpp::Any visitCondition(NFCompilerParser::ConditionContext *context) = 0;

    virtual antlrcpp::Any visitStatement(NFCompilerParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(NFCompilerParser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitSingle(NFCompilerParser::SingleContext *context) = 0;

    virtual antlrcpp::Any visitDouble(NFCompilerParser::DoubleContext *context) = 0;

    virtual antlrcpp::Any visitAtom(NFCompilerParser::AtomContext *context) = 0;

    virtual antlrcpp::Any visitId(NFCompilerParser::IdContext *context) = 0;

    virtual antlrcpp::Any visitFunc(NFCompilerParser::FuncContext *context) = 0;

    virtual antlrcpp::Any visitRule_flow(NFCompilerParser::Rule_flowContext *context) = 0;

    virtual antlrcpp::Any visitConst(NFCompilerParser::ConstContext *context) = 0;

    virtual antlrcpp::Any visitSet(NFCompilerParser::SetContext *context) = 0;

    virtual antlrcpp::Any visitMap(NFCompilerParser::MapContext *context) = 0;

    virtual antlrcpp::Any visitLrexp(NFCompilerParser::LrexpContext *context) = 0;

    virtual antlrcpp::Any visitAction(NFCompilerParser::ActionContext *context) = 0;

    virtual antlrcpp::Any visitField(NFCompilerParser::FieldContext *context) = 0;

    virtual antlrcpp::Any visitContents(NFCompilerParser::ContentsContext *context) = 0;

    virtual antlrcpp::Any visitKey_pairs(NFCompilerParser::Key_pairsContext *context) = 0;

    virtual antlrcpp::Any visitKey_value(NFCompilerParser::Key_valueContext *context) = 0;

    virtual antlrcpp::Any visitFunction_call(NFCompilerParser::Function_callContext *context) = 0;

    virtual antlrcpp::Any visitFuncs(NFCompilerParser::FuncsContext *context) = 0;

    virtual antlrcpp::Any visitExpression_list(NFCompilerParser::Expression_listContext *context) = 0;

    virtual antlrcpp::Any visitConst_ip(NFCompilerParser::Const_ipContext *context) = 0;

    virtual antlrcpp::Any visitConst_int(NFCompilerParser::Const_intContext *context) = 0;

    virtual antlrcpp::Any visitFlow_or_rule_entry(NFCompilerParser::Flow_or_rule_entryContext *context) = 0;

    virtual antlrcpp::Any visitOp(NFCompilerParser::OpContext *context) = 0;

    virtual antlrcpp::Any visitExpr_op(NFCompilerParser::Expr_opContext *context) = 0;

    virtual antlrcpp::Any visitRel_op(NFCompilerParser::Rel_opContext *context) = 0;

    virtual antlrcpp::Any visitFields(NFCompilerParser::FieldsContext *context) = 0;


};

