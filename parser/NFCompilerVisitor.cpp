


#include "NFCompilerVisitor.h"
#include "../symboltable.h"

// Generated from NFCompiler.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "NFCompilerParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by NFCompilerParser.
 */
  /**
   * Visit parse trees produced by NFCompilerParser.
   */
  

    antlrcpp::Any NFCompilerVisitor::visitProgram(NFCompilerParser::ProgramContext *context) {
      NFCompilerVisitor::ST.add(context->IDENT()->getText(), "program", "program", "NULL", "per-nf");
      NFCompilerVisitor::ST.add("f", "flow", "flow", "NULL", "per-nf");
      return visitChildren(context);
    }


    antlrcpp::Any NFCompilerVisitor::visitDeclare_entry(NFCompilerParser::Declare_entryContext *context) {
      std::string type = context->type()->getText();
      antlrcpp::Any a = NFCompilerVisitor::visit(context->expression(0));
      if (type == "rule") {
	try {
	map<string, string> m;
	m = a.as<map<string, string>>();
	NFCompilerVisitor::ST.add(context->IDENT()->getText(),type, type, m.begin()->second, m.begin()->first);
	//cout << m.begin()->first << " " << m.begin()->second << endl;
	} catch (bad_cast const& e) {
	}
      }
      return visitChildren(context);
    }

  antlrcpp::Any NFCompilerVisitor::visitEntries(NFCompilerParser::EntriesContext *ctx)  {
    return visitChildren(ctx);
  }

  antlrcpp::Any NFCompilerVisitor::visitEntry(NFCompilerParser::EntryContext *ctx)  {
    return visitChildren(ctx);
  }

  antlrcpp::Any NFCompilerVisitor::visitMatch_action(NFCompilerParser::Match_actionContext *ctx)  {
    return visitChildren(ctx);
  }

  antlrcpp::Any NFCompilerVisitor::visitAction_statements(NFCompilerParser::Action_statementsContext *ctx)  {
    return visitChildren(ctx);
  }

  antlrcpp::Any NFCompilerVisitor::visitMatch_flow(NFCompilerParser::Match_flowContext *ctx)  {
    return visitChildren(ctx);
  }

  antlrcpp::Any NFCompilerVisitor::visitMatch_state(NFCompilerParser::Match_stateContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitAction_flow(NFCompilerParser::Action_flowContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitAction_state(NFCompilerParser::Action_stateContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitDeclaration(NFCompilerParser::DeclarationContext *ctx)  {
    return visitChildren(ctx);
  }

   //antlrcpp::Any NFCompilerVisitor::visitDeclare_entry(NFCompilerParser::Declare_entryContext *ctx)  {
   // return visitChildren(ctx);
  //}

   antlrcpp::Any NFCompilerVisitor::visitDec_basic(NFCompilerParser::Dec_basicContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitDec_set(NFCompilerParser::Dec_setContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitDec_map(NFCompilerParser::Dec_mapContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitDec_rule(NFCompilerParser::Dec_ruleContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitCondition(NFCompilerParser::ConditionContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitStatement(NFCompilerParser::StatementContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitAssignment(NFCompilerParser::AssignmentContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitSingle(NFCompilerParser::SingleContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitDouble(NFCompilerParser::DoubleContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitAtom(NFCompilerParser::AtomContext *ctx)  {
      antlrcpp::Any a = visitChildren(ctx);
	try {
	map<string, string> m;
	m = a.as<map<string, string>>();
	//cout << m.begin()->first << " " << m.begin()->second << endl;
	} catch (bad_cast const& e) {
	}
    return a;
  }

   antlrcpp::Any NFCompilerVisitor::visitId(NFCompilerParser::IdContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitFunc(NFCompilerParser::FuncContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitRule_flow(NFCompilerParser::Rule_flowContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitConst(NFCompilerParser::ConstContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitSet(NFCompilerParser::SetContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitMap(NFCompilerParser::MapContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitLrexp(NFCompilerParser::LrexpContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitAction(NFCompilerParser::ActionContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitField(NFCompilerParser::FieldContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitContents(NFCompilerParser::ContentsContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitKey_pairs(NFCompilerParser::Key_pairsContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitKey_value(NFCompilerParser::Key_valueContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitFunction_call(NFCompilerParser::Function_callContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitFuncs(NFCompilerParser::FuncsContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitExpression_list(NFCompilerParser::Expression_listContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitConst_ip(NFCompilerParser::Const_ipContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitConst_int(NFCompilerParser::Const_intContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitFlow_or_rule_entry(NFCompilerParser::Flow_or_rule_entryContext *ctx)  {
     string field =  ctx->getStart()->getText();
     string c = ctx->getStop()->getText();
     map<string, string> m;
     m.insert(pair<string, string>(field, c));
     /*antlr4::atn::PredictionContext *p = ctx->getRuleContext<antlr4::atn::PredictionContext>(0);
    NFCompilerParser::AtomContext *nf_atom = p->getParent(0);
    NFCompilerParser::ExpressionContext *nf_expr = nf_atom->getParent(0);
    NFCompilerParser::Declare_entryContext *nf_d = nf_expr->getParent(0);
    NFCompilerVisitor::ST.add(nf_d->IDENT()->getText(),"rule", "rule", ctx->constant()->getText(), ctx->fields()->getText);*/
    return antlrcpp::Any(m);
  }

   antlrcpp::Any NFCompilerVisitor::visitOp(NFCompilerParser::OpContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitExpr_op(NFCompilerParser::Expr_opContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitRel_op(NFCompilerParser::Rel_opContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitFields(NFCompilerParser::FieldsContext *ctx)  {
    return visitChildren(ctx);
  }



