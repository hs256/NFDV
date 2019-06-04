


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
  
void NFCompilerVisitor::print_entry_flow() {
  map<struct match_flow*, struct action_flow*>::iterator it;
  for (it = NFCompilerVisitor::entry_flow.begin(); it != NFCompilerVisitor::entry_flow.end(); it++) {
    struct match_flow *mf = it->first;
    struct action_flow *af = it->second;
    cout << mf->match << "  " << mf->var << "  " << af->field << "  " << af->action << endl ;
  }
}

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
    antlrcpp::Any a_mf = NFCompilerVisitor::visit(ctx->match_action()->match_flow()->condition()->expression());
    struct match_flow *mf = new match_flow;
    struct action_flow *af = new action_flow;
    try {
      map<bool, string> m;
      m = a_mf.as<map<bool, string>>();
      mf->match = m.begin()->first;
      mf->var = m.begin()->second;
    } catch (bad_cast const& e) {
      //cout << "unable to get map match flow " << endl;
    }

    if (ctx->match_action()->action_statements()->action_flow()) {
      antlrcpp::Any a_af = NFCompilerVisitor::visit(ctx->match_action()->action_statements()->action_flow()->statement());
      try {
	string action = a_af.as<string>();
	af->field = "";
	af->action = action;
      } catch(bad_cast const& e) {
	  if (ctx->match_action()->action_statements()->action_flow()->statement()->assignment()) {
	    try {
	      antlrcpp::Any a_af2 = NFCompilerVisitor::visit(ctx->match_action()->action_statements()->action_flow()->statement()->assignment());
	      map<string, string> m;
	      m = a_af2.as<map<string, string>>();
	      af->field = m.begin()->first;
	      af->action = m.begin()->second;
	    } catch (bad_cast const& e) {
	      //cout << "can't convert to map " << endl;
	    }
	  }
      }
    } else {
      af->field = "";
      af->action = "pass";
    }
    NFCompilerVisitor::entry_flow.insert(pair<struct match_flow*, struct action_flow*>(mf, af));  
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
     if (ctx->PASS()) {
       //cout << ctx->PASS()->getText() << " in visit statement " << endl;
       return antlrcpp::Any(ctx->PASS()->getText());
    } else
       return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitAssignment(NFCompilerParser::AssignmentContext *ctx)  {
     if (ctx->expression(0) && ctx->expression(1)) { 
      antlrcpp::Any a1 = NFCompilerVisitor::visit(ctx->expression(0));
      antlrcpp::Any a2 = NFCompilerVisitor::visit(ctx->expression(1));
      string s1, s2;
      map<string, string> m;
      try {
	s1 = a1.as<string>();
	s2 = a2.as<string>();
	m.insert(pair<string, string>(s1, s2));
	antlrcpp::Any t(m);
	return t;
      } catch (bad_cast const& e) {
	  //cout << "can't convert any to map in assignment" << endl;
      }
    }
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitSingle(NFCompilerParser::SingleContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitDouble(NFCompilerParser::DoubleContext *ctx)  {
     if (ctx->op()->getText() == "matches" || ctx->op()->getText() == "mismatches") {
       string m = ctx->op()->getText();
       //struct match_flow *mf = new match_flow;
       map<bool, string> mf;
       bool match;
       if(m == "matches")
	 match = true;
       else if (m == "mismatches")
	 match = false;
       antlrcpp::Any a = NFCompilerVisitor::visit(ctx->expression(1));
	try {
	string c;
	c = a.as<string>();
	//mf->var = c;
	mf.insert(pair<bool, string>(match, c));
	antlrcpp::Any temp(mf);
	return temp;
	} catch (bad_cast const& e) {
	}
    }
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitAtom(NFCompilerParser::AtomContext *ctx)  {
      antlrcpp::Any a = visitChildren(ctx);
	try {
	string c;
	c = a.as<string>();
	//cout << c << " in visit atom" << endl;
	//NFCompilerVisitor::ST.add(context->IDENT()->getText(),type, type, m.begin()->second, m.begin()->first);
	} catch (bad_cast const& e) {
	}
    return a;
  }

   antlrcpp::Any NFCompilerVisitor::visitId(NFCompilerParser::IdContext *ctx)  {
    string c = ctx->IDENT()->getText();
    if (ctx->expression().empty() && ctx->fields() == NULL) {
      //cout << "returning c in visit ID" << endl;
      return antlrcpp::Any(c);
    } else if (ctx->expression().empty() && ctx->fields() != NULL) {
	antlrcpp::Any a1 = NFCompilerVisitor::visit(ctx->fields());
	try {
	  string s1 = a1.as<string>();
	  //cout << s1  << " in visit id" << endl;
	  return antlrcpp::Any(s1);
	} catch (bad_cast const& e) {
	}
      }
      return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitFunc(NFCompilerParser::FuncContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitRule_flow(NFCompilerParser::Rule_flowContext *ctx)  {
    return visitChildren(ctx);
  }

   antlrcpp::Any NFCompilerVisitor::visitConst(NFCompilerParser::ConstContext *ctx)  {
    string c = ctx->constant()->getText();
    //cout << c << " in const visitor" << endl;
    return antlrcpp::Any(c);
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
    string c = ctx->ACTION()->getText();
     //cout << c << " in action visitor" << endl;
    return antlrcpp::Any(c);
  }

   antlrcpp::Any NFCompilerVisitor::visitField(NFCompilerParser::FieldContext *ctx)  {
     antlrcpp::Any a = visitChildren(ctx);
    try {
      string action = a.as<string>();
      //cout << action << " in visit field" << endl;
    } catch(bad_cast const& e) {
      //cout << "not pass string in visit field" << endl;
    }
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
    string c = ctx->FIELD()->getText();
     //cout << c << " in field visitor " << endl;
    return antlrcpp::Any(c);;
  }



