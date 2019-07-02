


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
  
void NFCompilerVisitor::print_entries() {
  vector<struct entry*>::iterator it;
  for (it = NFCompilerVisitor::entries.begin(); it != NFCompilerVisitor::entries.end(); it++) {
    struct match_flow *mf = (*it)->m_f;
    struct action_flow *af = (*it)->a_f;
    struct match_state *ms = (*it)->m_s;
    cout << mf->match << "  " << mf->var << " && " << ms->state_var << " " << ms->op << " " << ms->state_val << "  " << af->field << "  " << af->action << endl ;
  }
}

    antlrcpp::Any NFCompilerVisitor::visitProgram(NFCompilerParser::ProgramContext *context) {
      vector<string> per_nf;
      per_nf.push_back("per-nf");
      NFCompilerVisitor::ST.add(context->IDENT()->getText(), "program", "program", "NULL", per_nf);
      NFCompilerVisitor::ST.add("f", "flow", "flow", "NULL", per_nf);
      return visitChildren(context);
    }


    antlrcpp::Any NFCompilerVisitor::visitDeclare_entry(NFCompilerParser::Declare_entryContext *context) {
      std::string type = context->type()->getText();
      if (type == "rule") {
	antlrcpp::Any a = NFCompilerVisitor::visit(context->expression(0));
	try {
	map<string, string> m;
	m = a.as<map<string, string>>();
	vector<string> v_f;
	v_f.push_back(m.begin()->first);
	NFCompilerVisitor::ST.add(context->IDENT()->getText(),type, type, m.begin()->second, v_f);
	//cout << context->IDENT()->getText() << " " << m.begin()->first << " " << m.begin()->second << endl;
	} catch (bad_cast const& e) {
	}
      } else if (type == "int") {
	if (context->ASSIGN() != NULL && context->expression().size() == 1) {
	  antlrcpp::Any a1 = NFCompilerVisitor::visit(context->expression(0));
	  try {
	    string int_c;
	    int_c = a1.as<string>();
	    if (NFCompilerVisitor::ST.find(int_c) == NULL) {
	      NFCompilerVisitor::ST.add(context->IDENT()->getText(), type, type, int_c, vector<string>());
	    } else {
	      string int_actual = NFCompilerVisitor::ST.getValuebyName(int_c);
	      NFCompilerVisitor::ST.add(context->IDENT()->getText(), type, type, int_actual, vector<string>());
	    }
	  } catch (bad_cast const& e) {
	  }
	} else if (context->ASSIGN() != NULL && context->expression().size() == 2) {
	  antlrcpp::Any a1 = NFCompilerVisitor::visit(context->expression(1));
	  try {
	    string int_c;
	    int_c = a1.as<string>();
	    if (NFCompilerVisitor::ST.find(int_c) == NULL) {
	      NFCompilerVisitor::ST.add(context->IDENT()->getText(), type, type, int_c, vector<string>());
	    } else {
	      string int_actual = NFCompilerVisitor::ST.getValuebyName(int_c);
	      NFCompilerVisitor::ST.add(context->IDENT()->getText(), type, type, int_actual, vector<string>());
	    }
	  } catch (bad_cast const& e) {
	  }
	}
      }

      return visitChildren(context);
    }

  antlrcpp::Any NFCompilerVisitor::visitEntries(NFCompilerParser::EntriesContext *ctx)  {
    return visitChildren(ctx);
  }

  antlrcpp::Any NFCompilerVisitor::visitEntry(NFCompilerParser::EntryContext *ctx)  {
    struct match_flow *mf = new match_flow;
    struct action_flow *af = new action_flow;
    struct match_state *ms = new match_state;
    struct action_state *as = new action_state;
    struct entry *en = new entry;
    antlrcpp::Any a_mf = NFCompilerVisitor::visit(ctx->match_action()->match_flow()->condition()->expression());
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

    if (ctx->match_action()->match_state()) {
      antlrcpp::Any a3 = NFCompilerVisitor::visit(ctx->match_action()->match_state()->condition()->expression());
      try {
	vector<string> t_m;
	t_m = a3.as<vector<string>>();
	ms->state_var = t_m[0];
	ms->op = t_m[1];
	ms->state_val = t_m[2];
	//cout << t_m[0] << " " << t_m[1] << " " << t_m[2] << " in visit entry " << endl; 
      } catch (bad_cast const& e) {
	cout << "can't parse match state" << endl;
      }
    }
	
    en->m_f = mf;
    en->a_f = af;
    en->m_s = ms;
    en->a_s = as;
    //NFCompilerVisitor::entry_flow.insert(pair<struct match_flow*, struct action_flow*>(mf, af));  
    NFCompilerVisitor::entries.push_back(en);
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
       bool match;
       if(m == "matches")
	 match = true;
       else if (m == "mismatches")
	 match = false;
       antlrcpp::Any a = NFCompilerVisitor::visit(ctx->expression(1));
	try {
	  string c;
	  map<bool, string> mf;
	  c = a.as<string>();
	  //mf->var = c;
	  mf.insert(pair<bool, string>(match, c));
	  antlrcpp::Any temp(mf);
	  return temp;
	} catch (bad_cast const& e) {
	}
    } else if (ctx->op()->getText() == "==") {
	antlrcpp::Any a1 = NFCompilerVisitor::visit(ctx->expression(0));
	antlrcpp::Any a2 = NFCompilerVisitor::visit(ctx->expression(1));
	try {
	  string c1, c2;
	  vector<string> eq_s;
	  c1 = a1.as<string>();
	  c2 = a2.as<string>();
	  //cout << "match state in double " << c1 << " " << ctx->op()->getText() << " "  << c2 << endl;
	  eq_s.push_back(c1);
	  eq_s.push_back("==");
	  eq_s.push_back(c2);
	  antlrcpp::Any temp1(eq_s);
	  return temp1;
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

  antlrcpp::Any NFCompilerVisitor::visitNew_packet(NFCompilerParser::New_packetContext *ctx) {
    return visitChildren(ctx);
  }



