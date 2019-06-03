




// Generated from NFCompiler.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  NFCompilerParser : public antlr4::Parser {
public:
  enum {
    BASIC_TYPE = 1, SET = 2, MAP = 3, FLOW = 4, RULE = 5, FIELD = 6, ACTION = 7, 
    ENTRY = 8, PASS = 9, TIMER = 10, RESUBMIT = 11, ACCEPT = 12, SEND_TO = 13, 
    SEND_BACK = 14, CONNECT = 15, MAX = 16, RECV = 17, ADD = 18, SUB = 19, 
    MUL = 20, DIV = 21, MOD = 22, AND = 23, OR = 24, UNION = 25, INTERSECTION = 26, 
    DIFFER = 27, NOT = 28, EQUAL = 29, UNEQUAL = 30, LOE = 31, BOE = 32, 
    LT = 33, BT = 34, IN = 35, SUBSET = 36, MATCH = 37, CONNECTION = 38, 
    DATA = 39, COMMA = 40, LB = 41, RB = 42, LCB = 43, RCB = 44, LSB = 45, 
    RSB = 46, COLON = 47, START = 48, ASSIGN = 49, SEMICOLON = 50, MATCH_FLOW = 51, 
    MATCH_STATE = 52, ACTION_FLOW = 53, ACTION_STATE = 54, IP = 55, INT = 56, 
    IDENT = 57, BLOCK_COMMENT = 58, LINE_COMMENT = 59, WS = 60
  };

  enum {
    RuleProgram = 0, RuleEntries = 1, RuleEntry = 2, RuleMatch_action = 3, 
    RuleAction_statements = 4, RuleMatch_flow = 5, RuleMatch_state = 6, 
    RuleAction_flow = 7, RuleAction_state = 8, RuleDeclaration = 9, RuleDeclare_entry = 10, 
    RuleType = 11, RuleCondition = 12, RuleStatement = 13, RuleAssignment = 14, 
    RuleExpression = 15, RuleItem = 16, RuleContents = 17, RuleKey_pairs = 18, 
    RuleKey_value = 19, RuleFunction_call = 20, RuleFuncs = 21, RuleExpression_list = 22, 
    RuleConstant = 23, RuleFlow_or_rule_entry = 24, RuleOp = 25, RuleExpr_op = 26, 
    RuleRel_op = 27, RuleFields = 28
  };

  NFCompilerParser(antlr4::TokenStream *input);
  ~NFCompilerParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class EntriesContext;
  class EntryContext;
  class Match_actionContext;
  class Action_statementsContext;
  class Match_flowContext;
  class Match_stateContext;
  class Action_flowContext;
  class Action_stateContext;
  class DeclarationContext;
  class Declare_entryContext;
  class TypeContext;
  class ConditionContext;
  class StatementContext;
  class AssignmentContext;
  class ExpressionContext;
  class ItemContext;
  class ContentsContext;
  class Key_pairsContext;
  class Key_valueContext;
  class Function_callContext;
  class FuncsContext;
  class Expression_listContext;
  class ConstantContext;
  class Flow_or_rule_entryContext;
  class OpContext;
  class Expr_opContext;
  class Rel_opContext;
  class FieldsContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *START();
    antlr4::tree::TerminalNode *IDENT();
    antlr4::tree::TerminalNode *LCB();
    DeclarationContext *declaration();
    EntriesContext *entries();
    antlr4::tree::TerminalNode *RCB();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  EntriesContext : public antlr4::ParserRuleContext {
  public:
    EntriesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EntryContext *> entry();
    EntryContext* entry(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EntriesContext* entries();

  class  EntryContext : public antlr4::ParserRuleContext {
  public:
    EntryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENTRY();
    antlr4::tree::TerminalNode *LCB();
    Match_actionContext *match_action();
    antlr4::tree::TerminalNode *RCB();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EntryContext* entry();

  class  Match_actionContext : public antlr4::ParserRuleContext {
  public:
    Match_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Action_statementsContext *action_statements();
    Match_flowContext *match_flow();
    Match_stateContext *match_state();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Match_actionContext* match_action();

  class  Action_statementsContext : public antlr4::ParserRuleContext {
  public:
    Action_statementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Action_flowContext *action_flow();
    Action_stateContext *action_state();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Action_statementsContext* action_statements();

  class  Match_flowContext : public antlr4::ParserRuleContext {
  public:
    Match_flowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MATCH_FLOW();
    antlr4::tree::TerminalNode *LCB();
    ConditionContext *condition();
    antlr4::tree::TerminalNode *RCB();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Match_flowContext* match_flow();

  class  Match_stateContext : public antlr4::ParserRuleContext {
  public:
    Match_stateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MATCH_STATE();
    antlr4::tree::TerminalNode *LCB();
    ConditionContext *condition();
    antlr4::tree::TerminalNode *RCB();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Match_stateContext* match_state();

  class  Action_flowContext : public antlr4::ParserRuleContext {
  public:
    Action_flowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACTION_FLOW();
    antlr4::tree::TerminalNode *LCB();
    StatementContext *statement();
    antlr4::tree::TerminalNode *RCB();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Action_flowContext* action_flow();

  class  Action_stateContext : public antlr4::ParserRuleContext {
  public:
    Action_stateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACTION_STATE();
    antlr4::tree::TerminalNode *LCB();
    StatementContext *statement();
    antlr4::tree::TerminalNode *RCB();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Action_stateContext* action_state();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Declare_entryContext *> declare_entry();
    Declare_entryContext* declare_entry(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration();

  class  Declare_entryContext : public antlr4::ParserRuleContext {
  public:
    NFCompilerParser::ExpressionContext *granu = nullptr;;
    NFCompilerParser::ExpressionContext *value = nullptr;;
    Declare_entryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *IDENT();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LB();
    antlr4::tree::TerminalNode *RB();
    antlr4::tree::TerminalNode *ASSIGN();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Declare_entryContext* declare_entry();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypeContext() = default;
    void copyFrom(TypeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Dec_ruleContext : public TypeContext {
  public:
    Dec_ruleContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *RULE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Dec_mapContext : public TypeContext {
  public:
    Dec_mapContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *MAP();
    antlr4::tree::TerminalNode *LT();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *BT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Dec_basicContext : public TypeContext {
  public:
    Dec_basicContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *BASIC_TYPE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Dec_setContext : public TypeContext {
  public:
    Dec_setContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *BASIC_TYPE();
    antlr4::tree::TerminalNode *BT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeContext* type();

  class  ConditionContext : public antlr4::ParserRuleContext {
  public:
    ConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConditionContext* condition();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    AssignmentContext *assignment();
    Function_callContext *function_call();
    antlr4::tree::TerminalNode *PASS();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *BASIC_TYPE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SingleContext : public ExpressionContext {
  public:
    SingleContext(ExpressionContext *ctx);

    OpContext *op();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DoubleContext : public ExpressionContext {
  public:
    DoubleContext(ExpressionContext *ctx);

    NFCompilerParser::ExpressionContext *left = nullptr;
    NFCompilerParser::ExpressionContext *right = nullptr;
    OpContext *op();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AtomContext : public ExpressionContext {
  public:
    AtomContext(ExpressionContext *ctx);

    ItemContext *item();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  ItemContext : public antlr4::ParserRuleContext {
  public:
    ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ItemContext() = default;
    void copyFrom(ItemContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LrexpContext : public ItemContext {
  public:
    LrexpContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *LB();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RB();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SetContext : public ItemContext {
  public:
    SetContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *LCB();
    ContentsContext *contents();
    antlr4::tree::TerminalNode *RCB();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FuncContext : public ItemContext {
  public:
    FuncContext(ItemContext *ctx);

    Function_callContext *function_call();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConstContext : public ItemContext {
  public:
    ConstContext(ItemContext *ctx);

    ConstantContext *constant();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FieldContext : public ItemContext {
  public:
    FieldContext(ItemContext *ctx);

    FieldsContext *fields();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Rule_flowContext : public ItemContext {
  public:
    Rule_flowContext(ItemContext *ctx);

    Flow_or_rule_entryContext *flow_or_rule_entry();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ActionContext : public ItemContext {
  public:
    ActionContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *ACTION();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdContext : public ItemContext {
  public:
    IdContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *IDENT();
    std::vector<antlr4::tree::TerminalNode *> LSB();
    antlr4::tree::TerminalNode* LSB(size_t i);
    FieldsContext *fields();
    std::vector<antlr4::tree::TerminalNode *> RSB();
    antlr4::tree::TerminalNode* RSB(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MapContext : public ItemContext {
  public:
    MapContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *LCB();
    Key_pairsContext *key_pairs();
    antlr4::tree::TerminalNode *RCB();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ItemContext* item();

  class  ContentsContext : public antlr4::ParserRuleContext {
  public:
    ContentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ItemContext *> item();
    ItemContext* item(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ContentsContext* contents();

  class  Key_pairsContext : public antlr4::ParserRuleContext {
  public:
    Key_pairsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Key_valueContext *> key_value();
    Key_valueContext* key_value(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Key_pairsContext* key_pairs();

  class  Key_valueContext : public antlr4::ParserRuleContext {
  public:
    Key_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Key_valueContext* key_value();

  class  Function_callContext : public antlr4::ParserRuleContext {
  public:
    Function_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FuncsContext *funcs();
    antlr4::tree::TerminalNode *LB();
    antlr4::tree::TerminalNode *RB();
    Expression_listContext *expression_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_callContext* function_call();

  class  FuncsContext : public antlr4::ParserRuleContext {
  public:
    FuncsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TIMER();
    antlr4::tree::TerminalNode *RESUBMIT();
    antlr4::tree::TerminalNode *ACCEPT();
    antlr4::tree::TerminalNode *SEND_TO();
    antlr4::tree::TerminalNode *SEND_BACK();
    antlr4::tree::TerminalNode *CONNECT();
    antlr4::tree::TerminalNode *MAX();
    antlr4::tree::TerminalNode *RECV();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncsContext* funcs();

  class  Expression_listContext : public antlr4::ParserRuleContext {
  public:
    Expression_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expression_listContext* expression_list();

  class  ConstantContext : public antlr4::ParserRuleContext {
  public:
    ConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstantContext() = default;
    void copyFrom(ConstantContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Const_intContext : public ConstantContext {
  public:
    Const_intContext(ConstantContext *ctx);

    antlr4::tree::TerminalNode *INT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Const_ipContext : public ConstantContext {
  public:
    Const_ipContext(ConstantContext *ctx);

    antlr4::tree::TerminalNode *IP();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ConstantContext* constant();

  class  Flow_or_rule_entryContext : public antlr4::ParserRuleContext {
  public:
    Flow_or_rule_entryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FieldsContext *fields();
    antlr4::tree::TerminalNode *COLON();
    ConstantContext *constant();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Flow_or_rule_entryContext* flow_or_rule_entry();

  class  OpContext : public antlr4::ParserRuleContext {
  public:
    OpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr_opContext *expr_op();
    Rel_opContext *rel_op();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OpContext* op();

  class  Expr_opContext : public antlr4::ParserRuleContext {
  public:
    Expr_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *UNION();
    antlr4::tree::TerminalNode *INTERSECTION();
    antlr4::tree::TerminalNode *DIFFER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr_opContext* expr_op();

  class  Rel_opContext : public antlr4::ParserRuleContext {
  public:
    Rel_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *UNEQUAL();
    antlr4::tree::TerminalNode *LOE();
    antlr4::tree::TerminalNode *BOE();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *BT();
    antlr4::tree::TerminalNode *IN();
    antlr4::tree::TerminalNode *SUBSET();
    antlr4::tree::TerminalNode *MATCH();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *CONNECTION();
    antlr4::tree::TerminalNode *DATA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rel_opContext* rel_op();

  class  FieldsContext : public antlr4::ParserRuleContext {
  public:
    FieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FIELD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldsContext* fields();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

