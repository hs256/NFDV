




// Generated from NFCompiler.g4 by ANTLR 4.7.2


#include "NFCompilerListener.h"
#include "NFCompilerVisitor.h"

#include "NFCompilerParser.h"


using namespace antlrcpp;
using namespace antlr4;

NFCompilerParser::NFCompilerParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

NFCompilerParser::~NFCompilerParser() {
  delete _interpreter;
}

std::string NFCompilerParser::getGrammarFileName() const {
  return "NFCompiler.g4";
}

const std::vector<std::string>& NFCompilerParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& NFCompilerParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

NFCompilerParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NFCompilerParser::ProgramContext::START() {
  return getToken(NFCompilerParser::START, 0);
}

tree::TerminalNode* NFCompilerParser::ProgramContext::IDENT() {
  return getToken(NFCompilerParser::IDENT, 0);
}

tree::TerminalNode* NFCompilerParser::ProgramContext::LCB() {
  return getToken(NFCompilerParser::LCB, 0);
}

NFCompilerParser::DeclarationContext* NFCompilerParser::ProgramContext::declaration() {
  return getRuleContext<NFCompilerParser::DeclarationContext>(0);
}

NFCompilerParser::EntriesContext* NFCompilerParser::ProgramContext::entries() {
  return getRuleContext<NFCompilerParser::EntriesContext>(0);
}

tree::TerminalNode* NFCompilerParser::ProgramContext::RCB() {
  return getToken(NFCompilerParser::RCB, 0);
}

tree::TerminalNode* NFCompilerParser::ProgramContext::EOF() {
  return getToken(NFCompilerParser::EOF, 0);
}


size_t NFCompilerParser::ProgramContext::getRuleIndex() const {
  return NFCompilerParser::RuleProgram;
}

void NFCompilerParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void NFCompilerParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any NFCompilerParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::ProgramContext* NFCompilerParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, NFCompilerParser::RuleProgram);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    match(NFCompilerParser::START);
    setState(59);
    match(NFCompilerParser::IDENT);
    setState(60);
    match(NFCompilerParser::LCB);
    setState(61);
    declaration();
    setState(62);
    entries();
    setState(63);
    match(NFCompilerParser::RCB);
    setState(64);
    match(NFCompilerParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EntriesContext ------------------------------------------------------------------

NFCompilerParser::EntriesContext::EntriesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<NFCompilerParser::EntryContext *> NFCompilerParser::EntriesContext::entry() {
  return getRuleContexts<NFCompilerParser::EntryContext>();
}

NFCompilerParser::EntryContext* NFCompilerParser::EntriesContext::entry(size_t i) {
  return getRuleContext<NFCompilerParser::EntryContext>(i);
}


size_t NFCompilerParser::EntriesContext::getRuleIndex() const {
  return NFCompilerParser::RuleEntries;
}

void NFCompilerParser::EntriesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntries(this);
}

void NFCompilerParser::EntriesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntries(this);
}


antlrcpp::Any NFCompilerParser::EntriesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitEntries(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::EntriesContext* NFCompilerParser::entries() {
  EntriesContext *_localctx = _tracker.createInstance<EntriesContext>(_ctx, getState());
  enterRule(_localctx, 2, NFCompilerParser::RuleEntries);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(66);
      entry();
      setState(69); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == NFCompilerParser::ENTRY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EntryContext ------------------------------------------------------------------

NFCompilerParser::EntryContext::EntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NFCompilerParser::EntryContext::ENTRY() {
  return getToken(NFCompilerParser::ENTRY, 0);
}

tree::TerminalNode* NFCompilerParser::EntryContext::LCB() {
  return getToken(NFCompilerParser::LCB, 0);
}

NFCompilerParser::Match_actionContext* NFCompilerParser::EntryContext::match_action() {
  return getRuleContext<NFCompilerParser::Match_actionContext>(0);
}

tree::TerminalNode* NFCompilerParser::EntryContext::RCB() {
  return getToken(NFCompilerParser::RCB, 0);
}


size_t NFCompilerParser::EntryContext::getRuleIndex() const {
  return NFCompilerParser::RuleEntry;
}

void NFCompilerParser::EntryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntry(this);
}

void NFCompilerParser::EntryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntry(this);
}


antlrcpp::Any NFCompilerParser::EntryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitEntry(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::EntryContext* NFCompilerParser::entry() {
  EntryContext *_localctx = _tracker.createInstance<EntryContext>(_ctx, getState());
  enterRule(_localctx, 4, NFCompilerParser::RuleEntry);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    match(NFCompilerParser::ENTRY);
    setState(72);
    match(NFCompilerParser::LCB);
    setState(73);
    match_action();
    setState(74);
    match(NFCompilerParser::RCB);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Match_actionContext ------------------------------------------------------------------

NFCompilerParser::Match_actionContext::Match_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

NFCompilerParser::Action_statementsContext* NFCompilerParser::Match_actionContext::action_statements() {
  return getRuleContext<NFCompilerParser::Action_statementsContext>(0);
}

NFCompilerParser::Match_flowContext* NFCompilerParser::Match_actionContext::match_flow() {
  return getRuleContext<NFCompilerParser::Match_flowContext>(0);
}

NFCompilerParser::Match_stateContext* NFCompilerParser::Match_actionContext::match_state() {
  return getRuleContext<NFCompilerParser::Match_stateContext>(0);
}


size_t NFCompilerParser::Match_actionContext::getRuleIndex() const {
  return NFCompilerParser::RuleMatch_action;
}

void NFCompilerParser::Match_actionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatch_action(this);
}

void NFCompilerParser::Match_actionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatch_action(this);
}


antlrcpp::Any NFCompilerParser::Match_actionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitMatch_action(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::Match_actionContext* NFCompilerParser::match_action() {
  Match_actionContext *_localctx = _tracker.createInstance<Match_actionContext>(_ctx, getState());
  enterRule(_localctx, 6, NFCompilerParser::RuleMatch_action);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == NFCompilerParser::MATCH_FLOW) {
      setState(76);
      match_flow();
    }
    setState(80);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == NFCompilerParser::MATCH_STATE) {
      setState(79);
      match_state();
    }
    setState(82);
    action_statements();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Action_statementsContext ------------------------------------------------------------------

NFCompilerParser::Action_statementsContext::Action_statementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

NFCompilerParser::Action_flowContext* NFCompilerParser::Action_statementsContext::action_flow() {
  return getRuleContext<NFCompilerParser::Action_flowContext>(0);
}

NFCompilerParser::Action_stateContext* NFCompilerParser::Action_statementsContext::action_state() {
  return getRuleContext<NFCompilerParser::Action_stateContext>(0);
}


size_t NFCompilerParser::Action_statementsContext::getRuleIndex() const {
  return NFCompilerParser::RuleAction_statements;
}

void NFCompilerParser::Action_statementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAction_statements(this);
}

void NFCompilerParser::Action_statementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAction_statements(this);
}


antlrcpp::Any NFCompilerParser::Action_statementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitAction_statements(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::Action_statementsContext* NFCompilerParser::action_statements() {
  Action_statementsContext *_localctx = _tracker.createInstance<Action_statementsContext>(_ctx, getState());
  enterRule(_localctx, 8, NFCompilerParser::RuleAction_statements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == NFCompilerParser::ACTION_FLOW) {
      setState(84);
      action_flow();
    }
    setState(88);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == NFCompilerParser::ACTION_STATE) {
      setState(87);
      action_state();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Match_flowContext ------------------------------------------------------------------

NFCompilerParser::Match_flowContext::Match_flowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NFCompilerParser::Match_flowContext::MATCH_FLOW() {
  return getToken(NFCompilerParser::MATCH_FLOW, 0);
}

tree::TerminalNode* NFCompilerParser::Match_flowContext::LCB() {
  return getToken(NFCompilerParser::LCB, 0);
}

NFCompilerParser::ConditionContext* NFCompilerParser::Match_flowContext::condition() {
  return getRuleContext<NFCompilerParser::ConditionContext>(0);
}

tree::TerminalNode* NFCompilerParser::Match_flowContext::RCB() {
  return getToken(NFCompilerParser::RCB, 0);
}


size_t NFCompilerParser::Match_flowContext::getRuleIndex() const {
  return NFCompilerParser::RuleMatch_flow;
}

void NFCompilerParser::Match_flowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatch_flow(this);
}

void NFCompilerParser::Match_flowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatch_flow(this);
}


antlrcpp::Any NFCompilerParser::Match_flowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitMatch_flow(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::Match_flowContext* NFCompilerParser::match_flow() {
  Match_flowContext *_localctx = _tracker.createInstance<Match_flowContext>(_ctx, getState());
  enterRule(_localctx, 10, NFCompilerParser::RuleMatch_flow);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    match(NFCompilerParser::MATCH_FLOW);
    setState(91);
    match(NFCompilerParser::LCB);
    setState(92);
    condition();
    setState(93);
    match(NFCompilerParser::RCB);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Match_stateContext ------------------------------------------------------------------

NFCompilerParser::Match_stateContext::Match_stateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NFCompilerParser::Match_stateContext::MATCH_STATE() {
  return getToken(NFCompilerParser::MATCH_STATE, 0);
}

tree::TerminalNode* NFCompilerParser::Match_stateContext::LCB() {
  return getToken(NFCompilerParser::LCB, 0);
}

NFCompilerParser::ConditionContext* NFCompilerParser::Match_stateContext::condition() {
  return getRuleContext<NFCompilerParser::ConditionContext>(0);
}

tree::TerminalNode* NFCompilerParser::Match_stateContext::RCB() {
  return getToken(NFCompilerParser::RCB, 0);
}


size_t NFCompilerParser::Match_stateContext::getRuleIndex() const {
  return NFCompilerParser::RuleMatch_state;
}

void NFCompilerParser::Match_stateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatch_state(this);
}

void NFCompilerParser::Match_stateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatch_state(this);
}


antlrcpp::Any NFCompilerParser::Match_stateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitMatch_state(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::Match_stateContext* NFCompilerParser::match_state() {
  Match_stateContext *_localctx = _tracker.createInstance<Match_stateContext>(_ctx, getState());
  enterRule(_localctx, 12, NFCompilerParser::RuleMatch_state);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    match(NFCompilerParser::MATCH_STATE);
    setState(96);
    match(NFCompilerParser::LCB);
    setState(97);
    condition();
    setState(98);
    match(NFCompilerParser::RCB);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Action_flowContext ------------------------------------------------------------------

NFCompilerParser::Action_flowContext::Action_flowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NFCompilerParser::Action_flowContext::ACTION_FLOW() {
  return getToken(NFCompilerParser::ACTION_FLOW, 0);
}

tree::TerminalNode* NFCompilerParser::Action_flowContext::LCB() {
  return getToken(NFCompilerParser::LCB, 0);
}

NFCompilerParser::StatementContext* NFCompilerParser::Action_flowContext::statement() {
  return getRuleContext<NFCompilerParser::StatementContext>(0);
}

tree::TerminalNode* NFCompilerParser::Action_flowContext::RCB() {
  return getToken(NFCompilerParser::RCB, 0);
}


size_t NFCompilerParser::Action_flowContext::getRuleIndex() const {
  return NFCompilerParser::RuleAction_flow;
}

void NFCompilerParser::Action_flowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAction_flow(this);
}

void NFCompilerParser::Action_flowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAction_flow(this);
}


antlrcpp::Any NFCompilerParser::Action_flowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitAction_flow(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::Action_flowContext* NFCompilerParser::action_flow() {
  Action_flowContext *_localctx = _tracker.createInstance<Action_flowContext>(_ctx, getState());
  enterRule(_localctx, 14, NFCompilerParser::RuleAction_flow);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    match(NFCompilerParser::ACTION_FLOW);
    setState(101);
    match(NFCompilerParser::LCB);
    setState(102);
    statement();
    setState(103);
    match(NFCompilerParser::RCB);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Action_stateContext ------------------------------------------------------------------

NFCompilerParser::Action_stateContext::Action_stateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NFCompilerParser::Action_stateContext::ACTION_STATE() {
  return getToken(NFCompilerParser::ACTION_STATE, 0);
}

tree::TerminalNode* NFCompilerParser::Action_stateContext::LCB() {
  return getToken(NFCompilerParser::LCB, 0);
}

NFCompilerParser::StatementContext* NFCompilerParser::Action_stateContext::statement() {
  return getRuleContext<NFCompilerParser::StatementContext>(0);
}

tree::TerminalNode* NFCompilerParser::Action_stateContext::RCB() {
  return getToken(NFCompilerParser::RCB, 0);
}


size_t NFCompilerParser::Action_stateContext::getRuleIndex() const {
  return NFCompilerParser::RuleAction_state;
}

void NFCompilerParser::Action_stateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAction_state(this);
}

void NFCompilerParser::Action_stateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAction_state(this);
}


antlrcpp::Any NFCompilerParser::Action_stateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitAction_state(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::Action_stateContext* NFCompilerParser::action_state() {
  Action_stateContext *_localctx = _tracker.createInstance<Action_stateContext>(_ctx, getState());
  enterRule(_localctx, 16, NFCompilerParser::RuleAction_state);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(NFCompilerParser::ACTION_STATE);
    setState(106);
    match(NFCompilerParser::LCB);
    setState(107);
    statement();
    setState(108);
    match(NFCompilerParser::RCB);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

NFCompilerParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<NFCompilerParser::Declare_entryContext *> NFCompilerParser::DeclarationContext::declare_entry() {
  return getRuleContexts<NFCompilerParser::Declare_entryContext>();
}

NFCompilerParser::Declare_entryContext* NFCompilerParser::DeclarationContext::declare_entry(size_t i) {
  return getRuleContext<NFCompilerParser::Declare_entryContext>(i);
}


size_t NFCompilerParser::DeclarationContext::getRuleIndex() const {
  return NFCompilerParser::RuleDeclaration;
}

void NFCompilerParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void NFCompilerParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


antlrcpp::Any NFCompilerParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::DeclarationContext* NFCompilerParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 18, NFCompilerParser::RuleDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << NFCompilerParser::BASIC_TYPE)
      | (1ULL << NFCompilerParser::SET)
      | (1ULL << NFCompilerParser::MAP)
      | (1ULL << NFCompilerParser::RULE))) != 0)) {
      setState(110);
      declare_entry();
      setState(115);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declare_entryContext ------------------------------------------------------------------

NFCompilerParser::Declare_entryContext::Declare_entryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

NFCompilerParser::TypeContext* NFCompilerParser::Declare_entryContext::type() {
  return getRuleContext<NFCompilerParser::TypeContext>(0);
}

tree::TerminalNode* NFCompilerParser::Declare_entryContext::IDENT() {
  return getToken(NFCompilerParser::IDENT, 0);
}

tree::TerminalNode* NFCompilerParser::Declare_entryContext::SEMICOLON() {
  return getToken(NFCompilerParser::SEMICOLON, 0);
}

tree::TerminalNode* NFCompilerParser::Declare_entryContext::LB() {
  return getToken(NFCompilerParser::LB, 0);
}

tree::TerminalNode* NFCompilerParser::Declare_entryContext::RB() {
  return getToken(NFCompilerParser::RB, 0);
}

tree::TerminalNode* NFCompilerParser::Declare_entryContext::ASSIGN() {
  return getToken(NFCompilerParser::ASSIGN, 0);
}

std::vector<NFCompilerParser::ExpressionContext *> NFCompilerParser::Declare_entryContext::expression() {
  return getRuleContexts<NFCompilerParser::ExpressionContext>();
}

NFCompilerParser::ExpressionContext* NFCompilerParser::Declare_entryContext::expression(size_t i) {
  return getRuleContext<NFCompilerParser::ExpressionContext>(i);
}


size_t NFCompilerParser::Declare_entryContext::getRuleIndex() const {
  return NFCompilerParser::RuleDeclare_entry;
}

void NFCompilerParser::Declare_entryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclare_entry(this);
}

void NFCompilerParser::Declare_entryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclare_entry(this);
}


antlrcpp::Any NFCompilerParser::Declare_entryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitDeclare_entry(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::Declare_entryContext* NFCompilerParser::declare_entry() {
  Declare_entryContext *_localctx = _tracker.createInstance<Declare_entryContext>(_ctx, getState());
  enterRule(_localctx, 20, NFCompilerParser::RuleDeclare_entry);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    type();
    setState(117);
    match(NFCompilerParser::IDENT);
    setState(122);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == NFCompilerParser::LB) {
      setState(118);
      match(NFCompilerParser::LB);
      setState(119);
      dynamic_cast<Declare_entryContext *>(_localctx)->granu = expression(0);
      setState(120);
      match(NFCompilerParser::RB);
    }
    setState(126);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == NFCompilerParser::ASSIGN) {
      setState(124);
      match(NFCompilerParser::ASSIGN);
      setState(125);
      dynamic_cast<Declare_entryContext *>(_localctx)->value = expression(0);
    }
    setState(128);
    match(NFCompilerParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

NFCompilerParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t NFCompilerParser::TypeContext::getRuleIndex() const {
  return NFCompilerParser::RuleType;
}

void NFCompilerParser::TypeContext::copyFrom(TypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Dec_ruleContext ------------------------------------------------------------------

tree::TerminalNode* NFCompilerParser::Dec_ruleContext::RULE() {
  return getToken(NFCompilerParser::RULE, 0);
}

NFCompilerParser::Dec_ruleContext::Dec_ruleContext(TypeContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::Dec_ruleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDec_rule(this);
}
void NFCompilerParser::Dec_ruleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDec_rule(this);
}

antlrcpp::Any NFCompilerParser::Dec_ruleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitDec_rule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Dec_mapContext ------------------------------------------------------------------

tree::TerminalNode* NFCompilerParser::Dec_mapContext::MAP() {
  return getToken(NFCompilerParser::MAP, 0);
}

tree::TerminalNode* NFCompilerParser::Dec_mapContext::LT() {
  return getToken(NFCompilerParser::LT, 0);
}

std::vector<NFCompilerParser::TypeContext *> NFCompilerParser::Dec_mapContext::type() {
  return getRuleContexts<NFCompilerParser::TypeContext>();
}

NFCompilerParser::TypeContext* NFCompilerParser::Dec_mapContext::type(size_t i) {
  return getRuleContext<NFCompilerParser::TypeContext>(i);
}

tree::TerminalNode* NFCompilerParser::Dec_mapContext::COMMA() {
  return getToken(NFCompilerParser::COMMA, 0);
}

tree::TerminalNode* NFCompilerParser::Dec_mapContext::BT() {
  return getToken(NFCompilerParser::BT, 0);
}

NFCompilerParser::Dec_mapContext::Dec_mapContext(TypeContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::Dec_mapContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDec_map(this);
}
void NFCompilerParser::Dec_mapContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDec_map(this);
}

antlrcpp::Any NFCompilerParser::Dec_mapContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitDec_map(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Dec_basicContext ------------------------------------------------------------------

tree::TerminalNode* NFCompilerParser::Dec_basicContext::BASIC_TYPE() {
  return getToken(NFCompilerParser::BASIC_TYPE, 0);
}

NFCompilerParser::Dec_basicContext::Dec_basicContext(TypeContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::Dec_basicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDec_basic(this);
}
void NFCompilerParser::Dec_basicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDec_basic(this);
}

antlrcpp::Any NFCompilerParser::Dec_basicContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitDec_basic(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Dec_setContext ------------------------------------------------------------------

tree::TerminalNode* NFCompilerParser::Dec_setContext::SET() {
  return getToken(NFCompilerParser::SET, 0);
}

tree::TerminalNode* NFCompilerParser::Dec_setContext::LT() {
  return getToken(NFCompilerParser::LT, 0);
}

tree::TerminalNode* NFCompilerParser::Dec_setContext::BASIC_TYPE() {
  return getToken(NFCompilerParser::BASIC_TYPE, 0);
}

tree::TerminalNode* NFCompilerParser::Dec_setContext::BT() {
  return getToken(NFCompilerParser::BT, 0);
}

NFCompilerParser::Dec_setContext::Dec_setContext(TypeContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::Dec_setContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDec_set(this);
}
void NFCompilerParser::Dec_setContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDec_set(this);
}

antlrcpp::Any NFCompilerParser::Dec_setContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitDec_set(this);
  else
    return visitor->visitChildren(this);
}
NFCompilerParser::TypeContext* NFCompilerParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 22, NFCompilerParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(143);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case NFCompilerParser::BASIC_TYPE: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<NFCompilerParser::Dec_basicContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(130);
        match(NFCompilerParser::BASIC_TYPE);
        break;
      }

      case NFCompilerParser::SET: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<NFCompilerParser::Dec_setContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(131);
        match(NFCompilerParser::SET);
        setState(132);
        match(NFCompilerParser::LT);
        setState(133);
        match(NFCompilerParser::BASIC_TYPE);
        setState(134);
        match(NFCompilerParser::BT);
        break;
      }

      case NFCompilerParser::MAP: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<NFCompilerParser::Dec_mapContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(135);
        match(NFCompilerParser::MAP);
        setState(136);
        match(NFCompilerParser::LT);
        setState(137);
        type();
        setState(138);
        match(NFCompilerParser::COMMA);
        setState(139);
        type();
        setState(140);
        match(NFCompilerParser::BT);
        break;
      }

      case NFCompilerParser::RULE: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<NFCompilerParser::Dec_ruleContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(142);
        match(NFCompilerParser::RULE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

NFCompilerParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NFCompilerParser::ConditionContext::SEMICOLON() {
  return getToken(NFCompilerParser::SEMICOLON, 0);
}

std::vector<NFCompilerParser::ExpressionContext *> NFCompilerParser::ConditionContext::expression() {
  return getRuleContexts<NFCompilerParser::ExpressionContext>();
}

NFCompilerParser::ExpressionContext* NFCompilerParser::ConditionContext::expression(size_t i) {
  return getRuleContext<NFCompilerParser::ExpressionContext>(i);
}


size_t NFCompilerParser::ConditionContext::getRuleIndex() const {
  return NFCompilerParser::RuleCondition;
}

void NFCompilerParser::ConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondition(this);
}

void NFCompilerParser::ConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondition(this);
}


antlrcpp::Any NFCompilerParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::ConditionContext* NFCompilerParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 24, NFCompilerParser::RuleCondition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    expression(0);
    setState(146);
    match(NFCompilerParser::SEMICOLON);
    setState(150);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << NFCompilerParser::FIELD)
      | (1ULL << NFCompilerParser::ACTION)
      | (1ULL << NFCompilerParser::TIMER)
      | (1ULL << NFCompilerParser::RESUBMIT)
      | (1ULL << NFCompilerParser::ACCEPT)
      | (1ULL << NFCompilerParser::SEND_TO)
      | (1ULL << NFCompilerParser::SEND_BACK)
      | (1ULL << NFCompilerParser::CONNECT)
      | (1ULL << NFCompilerParser::MAX)
      | (1ULL << NFCompilerParser::RECV)
      | (1ULL << NFCompilerParser::ADD)
      | (1ULL << NFCompilerParser::SUB)
      | (1ULL << NFCompilerParser::MUL)
      | (1ULL << NFCompilerParser::DIV)
      | (1ULL << NFCompilerParser::MOD)
      | (1ULL << NFCompilerParser::AND)
      | (1ULL << NFCompilerParser::OR)
      | (1ULL << NFCompilerParser::UNION)
      | (1ULL << NFCompilerParser::INTERSECTION)
      | (1ULL << NFCompilerParser::DIFFER)
      | (1ULL << NFCompilerParser::NOT)
      | (1ULL << NFCompilerParser::EQUAL)
      | (1ULL << NFCompilerParser::UNEQUAL)
      | (1ULL << NFCompilerParser::LOE)
      | (1ULL << NFCompilerParser::BOE)
      | (1ULL << NFCompilerParser::LT)
      | (1ULL << NFCompilerParser::BT)
      | (1ULL << NFCompilerParser::IN)
      | (1ULL << NFCompilerParser::SUBSET)
      | (1ULL << NFCompilerParser::MATCH)
      | (1ULL << NFCompilerParser::CONNECTION)
      | (1ULL << NFCompilerParser::DATA)
      | (1ULL << NFCompilerParser::LB)
      | (1ULL << NFCompilerParser::LCB)
      | (1ULL << NFCompilerParser::COLON)
      | (1ULL << NFCompilerParser::NEW_PACKET)
      | (1ULL << NFCompilerParser::IP)
      | (1ULL << NFCompilerParser::INT)
      | (1ULL << NFCompilerParser::FLOAT)
      | (1ULL << NFCompilerParser::IDENT))) != 0)) {
      setState(147);
      expression(0);
      setState(152);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

NFCompilerParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NFCompilerParser::StatementContext::SEMICOLON() {
  return getToken(NFCompilerParser::SEMICOLON, 0);
}

NFCompilerParser::AssignmentContext* NFCompilerParser::StatementContext::assignment() {
  return getRuleContext<NFCompilerParser::AssignmentContext>(0);
}

NFCompilerParser::Function_callContext* NFCompilerParser::StatementContext::function_call() {
  return getRuleContext<NFCompilerParser::Function_callContext>(0);
}

tree::TerminalNode* NFCompilerParser::StatementContext::PASS() {
  return getToken(NFCompilerParser::PASS, 0);
}

tree::TerminalNode* NFCompilerParser::StatementContext::RESUBMIT() {
  return getToken(NFCompilerParser::RESUBMIT, 0);
}

std::vector<NFCompilerParser::StatementContext *> NFCompilerParser::StatementContext::statement() {
  return getRuleContexts<NFCompilerParser::StatementContext>();
}

NFCompilerParser::StatementContext* NFCompilerParser::StatementContext::statement(size_t i) {
  return getRuleContext<NFCompilerParser::StatementContext>(i);
}


size_t NFCompilerParser::StatementContext::getRuleIndex() const {
  return NFCompilerParser::RuleStatement;
}

void NFCompilerParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void NFCompilerParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any NFCompilerParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::StatementContext* NFCompilerParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 26, NFCompilerParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(157);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(153);
      assignment();
      break;
    }

    case 2: {
      setState(154);
      function_call();
      break;
    }

    case 3: {
      setState(155);
      match(NFCompilerParser::PASS);
      break;
    }

    case 4: {
      setState(156);
      match(NFCompilerParser::RESUBMIT);
      break;
    }

    }
    setState(159);
    match(NFCompilerParser::SEMICOLON);
    setState(163);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(160);
        statement(); 
      }
      setState(165);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

NFCompilerParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<NFCompilerParser::ExpressionContext *> NFCompilerParser::AssignmentContext::expression() {
  return getRuleContexts<NFCompilerParser::ExpressionContext>();
}

NFCompilerParser::ExpressionContext* NFCompilerParser::AssignmentContext::expression(size_t i) {
  return getRuleContext<NFCompilerParser::ExpressionContext>(i);
}

tree::TerminalNode* NFCompilerParser::AssignmentContext::ASSIGN() {
  return getToken(NFCompilerParser::ASSIGN, 0);
}

tree::TerminalNode* NFCompilerParser::AssignmentContext::BASIC_TYPE() {
  return getToken(NFCompilerParser::BASIC_TYPE, 0);
}


size_t NFCompilerParser::AssignmentContext::getRuleIndex() const {
  return NFCompilerParser::RuleAssignment;
}

void NFCompilerParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void NFCompilerParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


antlrcpp::Any NFCompilerParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::AssignmentContext* NFCompilerParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 28, NFCompilerParser::RuleAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == NFCompilerParser::BASIC_TYPE) {
      setState(166);
      match(NFCompilerParser::BASIC_TYPE);
    }
    setState(169);
    expression(0);
    setState(170);
    match(NFCompilerParser::ASSIGN);
    setState(171);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

NFCompilerParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t NFCompilerParser::ExpressionContext::getRuleIndex() const {
  return NFCompilerParser::RuleExpression;
}

void NFCompilerParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SingleContext ------------------------------------------------------------------

NFCompilerParser::OpContext* NFCompilerParser::SingleContext::op() {
  return getRuleContext<NFCompilerParser::OpContext>(0);
}

NFCompilerParser::ExpressionContext* NFCompilerParser::SingleContext::expression() {
  return getRuleContext<NFCompilerParser::ExpressionContext>(0);
}

NFCompilerParser::SingleContext::SingleContext(ExpressionContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::SingleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingle(this);
}
void NFCompilerParser::SingleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingle(this);
}

antlrcpp::Any NFCompilerParser::SingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitSingle(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DoubleContext ------------------------------------------------------------------

NFCompilerParser::OpContext* NFCompilerParser::DoubleContext::op() {
  return getRuleContext<NFCompilerParser::OpContext>(0);
}

std::vector<NFCompilerParser::ExpressionContext *> NFCompilerParser::DoubleContext::expression() {
  return getRuleContexts<NFCompilerParser::ExpressionContext>();
}

NFCompilerParser::ExpressionContext* NFCompilerParser::DoubleContext::expression(size_t i) {
  return getRuleContext<NFCompilerParser::ExpressionContext>(i);
}

NFCompilerParser::DoubleContext::DoubleContext(ExpressionContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::DoubleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDouble(this);
}
void NFCompilerParser::DoubleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDouble(this);
}

antlrcpp::Any NFCompilerParser::DoubleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitDouble(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtomContext ------------------------------------------------------------------

NFCompilerParser::ItemContext* NFCompilerParser::AtomContext::item() {
  return getRuleContext<NFCompilerParser::ItemContext>(0);
}

NFCompilerParser::AtomContext::AtomContext(ExpressionContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}
void NFCompilerParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

antlrcpp::Any NFCompilerParser::AtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitAtom(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::ExpressionContext* NFCompilerParser::expression() {
   return expression(0);
}

NFCompilerParser::ExpressionContext* NFCompilerParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  NFCompilerParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  NFCompilerParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, NFCompilerParser::RuleExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(178);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case NFCompilerParser::FIELD:
      case NFCompilerParser::ACTION:
      case NFCompilerParser::TIMER:
      case NFCompilerParser::RESUBMIT:
      case NFCompilerParser::ACCEPT:
      case NFCompilerParser::SEND_TO:
      case NFCompilerParser::SEND_BACK:
      case NFCompilerParser::CONNECT:
      case NFCompilerParser::MAX:
      case NFCompilerParser::RECV:
      case NFCompilerParser::LB:
      case NFCompilerParser::LCB:
      case NFCompilerParser::NEW_PACKET:
      case NFCompilerParser::IP:
      case NFCompilerParser::INT:
      case NFCompilerParser::FLOAT:
      case NFCompilerParser::IDENT: {
        _localctx = _tracker.createInstance<AtomContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(174);
        item();
        break;
      }

      case NFCompilerParser::ADD:
      case NFCompilerParser::SUB:
      case NFCompilerParser::MUL:
      case NFCompilerParser::DIV:
      case NFCompilerParser::MOD:
      case NFCompilerParser::AND:
      case NFCompilerParser::OR:
      case NFCompilerParser::UNION:
      case NFCompilerParser::INTERSECTION:
      case NFCompilerParser::DIFFER:
      case NFCompilerParser::NOT:
      case NFCompilerParser::EQUAL:
      case NFCompilerParser::UNEQUAL:
      case NFCompilerParser::LOE:
      case NFCompilerParser::BOE:
      case NFCompilerParser::LT:
      case NFCompilerParser::BT:
      case NFCompilerParser::IN:
      case NFCompilerParser::SUBSET:
      case NFCompilerParser::MATCH:
      case NFCompilerParser::CONNECTION:
      case NFCompilerParser::DATA:
      case NFCompilerParser::COLON: {
        _localctx = _tracker.createInstance<SingleContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(175);
        op();
        setState(176);
        expression(2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(186);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<DoubleContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->left = previousContext;
        pushNewRecursionContext(newContext, startState, RuleExpression);
        setState(180);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(181);
        op();
        setState(182);
        dynamic_cast<DoubleContext *>(_localctx)->right = expression(2); 
      }
      setState(188);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ItemContext ------------------------------------------------------------------

NFCompilerParser::ItemContext::ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t NFCompilerParser::ItemContext::getRuleIndex() const {
  return NFCompilerParser::RuleItem;
}

void NFCompilerParser::ItemContext::copyFrom(ItemContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LrexpContext ------------------------------------------------------------------

tree::TerminalNode* NFCompilerParser::LrexpContext::LB() {
  return getToken(NFCompilerParser::LB, 0);
}

NFCompilerParser::ExpressionContext* NFCompilerParser::LrexpContext::expression() {
  return getRuleContext<NFCompilerParser::ExpressionContext>(0);
}

tree::TerminalNode* NFCompilerParser::LrexpContext::RB() {
  return getToken(NFCompilerParser::RB, 0);
}

NFCompilerParser::LrexpContext::LrexpContext(ItemContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::LrexpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLrexp(this);
}
void NFCompilerParser::LrexpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLrexp(this);
}

antlrcpp::Any NFCompilerParser::LrexpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitLrexp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SetContext ------------------------------------------------------------------

tree::TerminalNode* NFCompilerParser::SetContext::LCB() {
  return getToken(NFCompilerParser::LCB, 0);
}

NFCompilerParser::ContentsContext* NFCompilerParser::SetContext::contents() {
  return getRuleContext<NFCompilerParser::ContentsContext>(0);
}

tree::TerminalNode* NFCompilerParser::SetContext::RCB() {
  return getToken(NFCompilerParser::RCB, 0);
}

NFCompilerParser::SetContext::SetContext(ItemContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::SetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSet(this);
}
void NFCompilerParser::SetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSet(this);
}

antlrcpp::Any NFCompilerParser::SetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitSet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncContext ------------------------------------------------------------------

NFCompilerParser::Function_callContext* NFCompilerParser::FuncContext::function_call() {
  return getRuleContext<NFCompilerParser::Function_callContext>(0);
}

NFCompilerParser::FuncContext::FuncContext(ItemContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::FuncContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc(this);
}
void NFCompilerParser::FuncContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc(this);
}

antlrcpp::Any NFCompilerParser::FuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstContext ------------------------------------------------------------------

NFCompilerParser::ConstantContext* NFCompilerParser::ConstContext::constant() {
  return getRuleContext<NFCompilerParser::ConstantContext>(0);
}

NFCompilerParser::ConstContext::ConstContext(ItemContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::ConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConst(this);
}
void NFCompilerParser::ConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConst(this);
}

antlrcpp::Any NFCompilerParser::ConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitConst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FieldContext ------------------------------------------------------------------

NFCompilerParser::FieldsContext* NFCompilerParser::FieldContext::fields() {
  return getRuleContext<NFCompilerParser::FieldsContext>(0);
}

NFCompilerParser::FieldContext::FieldContext(ItemContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::FieldContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterField(this);
}
void NFCompilerParser::FieldContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitField(this);
}

antlrcpp::Any NFCompilerParser::FieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitField(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Rule_flowContext ------------------------------------------------------------------

NFCompilerParser::Flow_or_rule_entryContext* NFCompilerParser::Rule_flowContext::flow_or_rule_entry() {
  return getRuleContext<NFCompilerParser::Flow_or_rule_entryContext>(0);
}

NFCompilerParser::Rule_flowContext::Rule_flowContext(ItemContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::Rule_flowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRule_flow(this);
}
void NFCompilerParser::Rule_flowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRule_flow(this);
}

antlrcpp::Any NFCompilerParser::Rule_flowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitRule_flow(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ActionContext ------------------------------------------------------------------

tree::TerminalNode* NFCompilerParser::ActionContext::ACTION() {
  return getToken(NFCompilerParser::ACTION, 0);
}

NFCompilerParser::ActionContext::ActionContext(ItemContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::ActionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAction(this);
}
void NFCompilerParser::ActionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAction(this);
}

antlrcpp::Any NFCompilerParser::ActionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitAction(this);
  else
    return visitor->visitChildren(this);
}
//----------------- New_packetContext ------------------------------------------------------------------

tree::TerminalNode* NFCompilerParser::New_packetContext::NEW_PACKET() {
  return getToken(NFCompilerParser::NEW_PACKET, 0);
}

tree::TerminalNode* NFCompilerParser::New_packetContext::LB() {
  return getToken(NFCompilerParser::LB, 0);
}

tree::TerminalNode* NFCompilerParser::New_packetContext::RB() {
  return getToken(NFCompilerParser::RB, 0);
}

NFCompilerParser::New_packetContext::New_packetContext(ItemContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::New_packetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNew_packet(this);
}
void NFCompilerParser::New_packetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNew_packet(this);
}

antlrcpp::Any NFCompilerParser::New_packetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitNew_packet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdContext ------------------------------------------------------------------

tree::TerminalNode* NFCompilerParser::IdContext::IDENT() {
  return getToken(NFCompilerParser::IDENT, 0);
}

std::vector<tree::TerminalNode *> NFCompilerParser::IdContext::LSB() {
  return getTokens(NFCompilerParser::LSB);
}

tree::TerminalNode* NFCompilerParser::IdContext::LSB(size_t i) {
  return getToken(NFCompilerParser::LSB, i);
}

NFCompilerParser::FieldsContext* NFCompilerParser::IdContext::fields() {
  return getRuleContext<NFCompilerParser::FieldsContext>(0);
}

std::vector<tree::TerminalNode *> NFCompilerParser::IdContext::RSB() {
  return getTokens(NFCompilerParser::RSB);
}

tree::TerminalNode* NFCompilerParser::IdContext::RSB(size_t i) {
  return getToken(NFCompilerParser::RSB, i);
}

std::vector<NFCompilerParser::ExpressionContext *> NFCompilerParser::IdContext::expression() {
  return getRuleContexts<NFCompilerParser::ExpressionContext>();
}

NFCompilerParser::ExpressionContext* NFCompilerParser::IdContext::expression(size_t i) {
  return getRuleContext<NFCompilerParser::ExpressionContext>(i);
}

NFCompilerParser::IdContext::IdContext(ItemContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::IdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterId(this);
}
void NFCompilerParser::IdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitId(this);
}

antlrcpp::Any NFCompilerParser::IdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MapContext ------------------------------------------------------------------

tree::TerminalNode* NFCompilerParser::MapContext::LCB() {
  return getToken(NFCompilerParser::LCB, 0);
}

NFCompilerParser::Key_pairsContext* NFCompilerParser::MapContext::key_pairs() {
  return getRuleContext<NFCompilerParser::Key_pairsContext>(0);
}

tree::TerminalNode* NFCompilerParser::MapContext::RCB() {
  return getToken(NFCompilerParser::RCB, 0);
}

NFCompilerParser::MapContext::MapContext(ItemContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::MapContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMap(this);
}
void NFCompilerParser::MapContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMap(this);
}

antlrcpp::Any NFCompilerParser::MapContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitMap(this);
  else
    return visitor->visitChildren(this);
}
NFCompilerParser::ItemContext* NFCompilerParser::item() {
  ItemContext *_localctx = _tracker.createInstance<ItemContext>(_ctx, getState());
  enterRule(_localctx, 32, NFCompilerParser::RuleItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(227);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ItemContext *>(_tracker.createInstance<NFCompilerParser::IdContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(189);
      match(NFCompilerParser::IDENT);
      setState(205);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
      case 1: {
        setState(194);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          setState(190);
          match(NFCompilerParser::LSB);
          setState(191);
          fields();
          setState(192);
          match(NFCompilerParser::RSB);
          break;
        }

        }
        break;
      }

      case 2: {
        setState(202);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(196);
            match(NFCompilerParser::LSB);
            setState(197);
            expression(0);
            setState(198);
            match(NFCompilerParser::RSB); 
          }
          setState(204);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
        }
        break;
      }

      }
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ItemContext *>(_tracker.createInstance<NFCompilerParser::FuncContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(207);
      function_call();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<ItemContext *>(_tracker.createInstance<NFCompilerParser::Rule_flowContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(208);
      flow_or_rule_entry();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<ItemContext *>(_tracker.createInstance<NFCompilerParser::ConstContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(209);
      constant();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<ItemContext *>(_tracker.createInstance<NFCompilerParser::SetContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(210);
      match(NFCompilerParser::LCB);
      setState(211);
      contents();
      setState(212);
      match(NFCompilerParser::RCB);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<ItemContext *>(_tracker.createInstance<NFCompilerParser::MapContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(214);
      match(NFCompilerParser::LCB);
      setState(215);
      key_pairs();
      setState(216);
      match(NFCompilerParser::RCB);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<ItemContext *>(_tracker.createInstance<NFCompilerParser::LrexpContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(218);
      match(NFCompilerParser::LB);
      setState(219);
      expression(0);
      setState(220);
      match(NFCompilerParser::RB);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<ItemContext *>(_tracker.createInstance<NFCompilerParser::ActionContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(222);
      match(NFCompilerParser::ACTION);
      break;
    }

    case 9: {
      _localctx = dynamic_cast<ItemContext *>(_tracker.createInstance<NFCompilerParser::FieldContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(223);
      fields();
      break;
    }

    case 10: {
      _localctx = dynamic_cast<ItemContext *>(_tracker.createInstance<NFCompilerParser::New_packetContext>(_localctx));
      enterOuterAlt(_localctx, 10);
      setState(224);
      match(NFCompilerParser::NEW_PACKET);
      setState(225);
      match(NFCompilerParser::LB);
      setState(226);
      match(NFCompilerParser::RB);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContentsContext ------------------------------------------------------------------

NFCompilerParser::ContentsContext::ContentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<NFCompilerParser::ItemContext *> NFCompilerParser::ContentsContext::item() {
  return getRuleContexts<NFCompilerParser::ItemContext>();
}

NFCompilerParser::ItemContext* NFCompilerParser::ContentsContext::item(size_t i) {
  return getRuleContext<NFCompilerParser::ItemContext>(i);
}

std::vector<tree::TerminalNode *> NFCompilerParser::ContentsContext::COMMA() {
  return getTokens(NFCompilerParser::COMMA);
}

tree::TerminalNode* NFCompilerParser::ContentsContext::COMMA(size_t i) {
  return getToken(NFCompilerParser::COMMA, i);
}


size_t NFCompilerParser::ContentsContext::getRuleIndex() const {
  return NFCompilerParser::RuleContents;
}

void NFCompilerParser::ContentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContents(this);
}

void NFCompilerParser::ContentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContents(this);
}


antlrcpp::Any NFCompilerParser::ContentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitContents(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::ContentsContext* NFCompilerParser::contents() {
  ContentsContext *_localctx = _tracker.createInstance<ContentsContext>(_ctx, getState());
  enterRule(_localctx, 34, NFCompilerParser::RuleContents);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    item();
    setState(234);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == NFCompilerParser::COMMA) {
      setState(230);
      match(NFCompilerParser::COMMA);
      setState(231);
      item();
      setState(236);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Key_pairsContext ------------------------------------------------------------------

NFCompilerParser::Key_pairsContext::Key_pairsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<NFCompilerParser::Key_valueContext *> NFCompilerParser::Key_pairsContext::key_value() {
  return getRuleContexts<NFCompilerParser::Key_valueContext>();
}

NFCompilerParser::Key_valueContext* NFCompilerParser::Key_pairsContext::key_value(size_t i) {
  return getRuleContext<NFCompilerParser::Key_valueContext>(i);
}

std::vector<tree::TerminalNode *> NFCompilerParser::Key_pairsContext::COMMA() {
  return getTokens(NFCompilerParser::COMMA);
}

tree::TerminalNode* NFCompilerParser::Key_pairsContext::COMMA(size_t i) {
  return getToken(NFCompilerParser::COMMA, i);
}


size_t NFCompilerParser::Key_pairsContext::getRuleIndex() const {
  return NFCompilerParser::RuleKey_pairs;
}

void NFCompilerParser::Key_pairsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKey_pairs(this);
}

void NFCompilerParser::Key_pairsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKey_pairs(this);
}


antlrcpp::Any NFCompilerParser::Key_pairsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitKey_pairs(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::Key_pairsContext* NFCompilerParser::key_pairs() {
  Key_pairsContext *_localctx = _tracker.createInstance<Key_pairsContext>(_ctx, getState());
  enterRule(_localctx, 36, NFCompilerParser::RuleKey_pairs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
    key_value();
    setState(242);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == NFCompilerParser::COMMA) {
      setState(238);
      match(NFCompilerParser::COMMA);
      setState(239);
      key_value();
      setState(244);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Key_valueContext ------------------------------------------------------------------

NFCompilerParser::Key_valueContext::Key_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<NFCompilerParser::ConstantContext *> NFCompilerParser::Key_valueContext::constant() {
  return getRuleContexts<NFCompilerParser::ConstantContext>();
}

NFCompilerParser::ConstantContext* NFCompilerParser::Key_valueContext::constant(size_t i) {
  return getRuleContext<NFCompilerParser::ConstantContext>(i);
}

tree::TerminalNode* NFCompilerParser::Key_valueContext::COLON() {
  return getToken(NFCompilerParser::COLON, 0);
}


size_t NFCompilerParser::Key_valueContext::getRuleIndex() const {
  return NFCompilerParser::RuleKey_value;
}

void NFCompilerParser::Key_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKey_value(this);
}

void NFCompilerParser::Key_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKey_value(this);
}


antlrcpp::Any NFCompilerParser::Key_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitKey_value(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::Key_valueContext* NFCompilerParser::key_value() {
  Key_valueContext *_localctx = _tracker.createInstance<Key_valueContext>(_ctx, getState());
  enterRule(_localctx, 38, NFCompilerParser::RuleKey_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    constant();
    setState(246);
    match(NFCompilerParser::COLON);
    setState(247);
    constant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_callContext ------------------------------------------------------------------

NFCompilerParser::Function_callContext::Function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

NFCompilerParser::FuncsContext* NFCompilerParser::Function_callContext::funcs() {
  return getRuleContext<NFCompilerParser::FuncsContext>(0);
}

tree::TerminalNode* NFCompilerParser::Function_callContext::LB() {
  return getToken(NFCompilerParser::LB, 0);
}

tree::TerminalNode* NFCompilerParser::Function_callContext::RB() {
  return getToken(NFCompilerParser::RB, 0);
}

NFCompilerParser::Expression_listContext* NFCompilerParser::Function_callContext::expression_list() {
  return getRuleContext<NFCompilerParser::Expression_listContext>(0);
}


size_t NFCompilerParser::Function_callContext::getRuleIndex() const {
  return NFCompilerParser::RuleFunction_call;
}

void NFCompilerParser::Function_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_call(this);
}

void NFCompilerParser::Function_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_call(this);
}


antlrcpp::Any NFCompilerParser::Function_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitFunction_call(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::Function_callContext* NFCompilerParser::function_call() {
  Function_callContext *_localctx = _tracker.createInstance<Function_callContext>(_ctx, getState());
  enterRule(_localctx, 40, NFCompilerParser::RuleFunction_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    funcs();
    setState(250);
    match(NFCompilerParser::LB);
    setState(252);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << NFCompilerParser::FIELD)
      | (1ULL << NFCompilerParser::ACTION)
      | (1ULL << NFCompilerParser::TIMER)
      | (1ULL << NFCompilerParser::RESUBMIT)
      | (1ULL << NFCompilerParser::ACCEPT)
      | (1ULL << NFCompilerParser::SEND_TO)
      | (1ULL << NFCompilerParser::SEND_BACK)
      | (1ULL << NFCompilerParser::CONNECT)
      | (1ULL << NFCompilerParser::MAX)
      | (1ULL << NFCompilerParser::RECV)
      | (1ULL << NFCompilerParser::ADD)
      | (1ULL << NFCompilerParser::SUB)
      | (1ULL << NFCompilerParser::MUL)
      | (1ULL << NFCompilerParser::DIV)
      | (1ULL << NFCompilerParser::MOD)
      | (1ULL << NFCompilerParser::AND)
      | (1ULL << NFCompilerParser::OR)
      | (1ULL << NFCompilerParser::UNION)
      | (1ULL << NFCompilerParser::INTERSECTION)
      | (1ULL << NFCompilerParser::DIFFER)
      | (1ULL << NFCompilerParser::NOT)
      | (1ULL << NFCompilerParser::EQUAL)
      | (1ULL << NFCompilerParser::UNEQUAL)
      | (1ULL << NFCompilerParser::LOE)
      | (1ULL << NFCompilerParser::BOE)
      | (1ULL << NFCompilerParser::LT)
      | (1ULL << NFCompilerParser::BT)
      | (1ULL << NFCompilerParser::IN)
      | (1ULL << NFCompilerParser::SUBSET)
      | (1ULL << NFCompilerParser::MATCH)
      | (1ULL << NFCompilerParser::CONNECTION)
      | (1ULL << NFCompilerParser::DATA)
      | (1ULL << NFCompilerParser::LB)
      | (1ULL << NFCompilerParser::LCB)
      | (1ULL << NFCompilerParser::COLON)
      | (1ULL << NFCompilerParser::NEW_PACKET)
      | (1ULL << NFCompilerParser::IP)
      | (1ULL << NFCompilerParser::INT)
      | (1ULL << NFCompilerParser::FLOAT)
      | (1ULL << NFCompilerParser::IDENT))) != 0)) {
      setState(251);
      expression_list();
    }
    setState(254);
    match(NFCompilerParser::RB);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncsContext ------------------------------------------------------------------

NFCompilerParser::FuncsContext::FuncsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NFCompilerParser::FuncsContext::TIMER() {
  return getToken(NFCompilerParser::TIMER, 0);
}

tree::TerminalNode* NFCompilerParser::FuncsContext::RESUBMIT() {
  return getToken(NFCompilerParser::RESUBMIT, 0);
}

tree::TerminalNode* NFCompilerParser::FuncsContext::ACCEPT() {
  return getToken(NFCompilerParser::ACCEPT, 0);
}

tree::TerminalNode* NFCompilerParser::FuncsContext::SEND_TO() {
  return getToken(NFCompilerParser::SEND_TO, 0);
}

tree::TerminalNode* NFCompilerParser::FuncsContext::SEND_BACK() {
  return getToken(NFCompilerParser::SEND_BACK, 0);
}

tree::TerminalNode* NFCompilerParser::FuncsContext::CONNECT() {
  return getToken(NFCompilerParser::CONNECT, 0);
}

tree::TerminalNode* NFCompilerParser::FuncsContext::MAX() {
  return getToken(NFCompilerParser::MAX, 0);
}

tree::TerminalNode* NFCompilerParser::FuncsContext::RECV() {
  return getToken(NFCompilerParser::RECV, 0);
}


size_t NFCompilerParser::FuncsContext::getRuleIndex() const {
  return NFCompilerParser::RuleFuncs;
}

void NFCompilerParser::FuncsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncs(this);
}

void NFCompilerParser::FuncsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncs(this);
}


antlrcpp::Any NFCompilerParser::FuncsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitFuncs(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::FuncsContext* NFCompilerParser::funcs() {
  FuncsContext *_localctx = _tracker.createInstance<FuncsContext>(_ctx, getState());
  enterRule(_localctx, 42, NFCompilerParser::RuleFuncs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(256);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << NFCompilerParser::TIMER)
      | (1ULL << NFCompilerParser::RESUBMIT)
      | (1ULL << NFCompilerParser::ACCEPT)
      | (1ULL << NFCompilerParser::SEND_TO)
      | (1ULL << NFCompilerParser::SEND_BACK)
      | (1ULL << NFCompilerParser::CONNECT)
      | (1ULL << NFCompilerParser::MAX)
      | (1ULL << NFCompilerParser::RECV))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_listContext ------------------------------------------------------------------

NFCompilerParser::Expression_listContext::Expression_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<NFCompilerParser::ExpressionContext *> NFCompilerParser::Expression_listContext::expression() {
  return getRuleContexts<NFCompilerParser::ExpressionContext>();
}

NFCompilerParser::ExpressionContext* NFCompilerParser::Expression_listContext::expression(size_t i) {
  return getRuleContext<NFCompilerParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> NFCompilerParser::Expression_listContext::COMMA() {
  return getTokens(NFCompilerParser::COMMA);
}

tree::TerminalNode* NFCompilerParser::Expression_listContext::COMMA(size_t i) {
  return getToken(NFCompilerParser::COMMA, i);
}


size_t NFCompilerParser::Expression_listContext::getRuleIndex() const {
  return NFCompilerParser::RuleExpression_list;
}

void NFCompilerParser::Expression_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_list(this);
}

void NFCompilerParser::Expression_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_list(this);
}


antlrcpp::Any NFCompilerParser::Expression_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitExpression_list(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::Expression_listContext* NFCompilerParser::expression_list() {
  Expression_listContext *_localctx = _tracker.createInstance<Expression_listContext>(_ctx, getState());
  enterRule(_localctx, 44, NFCompilerParser::RuleExpression_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(258);
    expression(0);
    setState(263);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == NFCompilerParser::COMMA) {
      setState(259);
      match(NFCompilerParser::COMMA);
      setState(260);
      expression(0);
      setState(265);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

NFCompilerParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t NFCompilerParser::ConstantContext::getRuleIndex() const {
  return NFCompilerParser::RuleConstant;
}

void NFCompilerParser::ConstantContext::copyFrom(ConstantContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Const_intContext ------------------------------------------------------------------

tree::TerminalNode* NFCompilerParser::Const_intContext::INT() {
  return getToken(NFCompilerParser::INT, 0);
}

NFCompilerParser::Const_intContext::Const_intContext(ConstantContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::Const_intContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConst_int(this);
}
void NFCompilerParser::Const_intContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConst_int(this);
}

antlrcpp::Any NFCompilerParser::Const_intContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitConst_int(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Const_ipContext ------------------------------------------------------------------

tree::TerminalNode* NFCompilerParser::Const_ipContext::IP() {
  return getToken(NFCompilerParser::IP, 0);
}

NFCompilerParser::Const_ipContext::Const_ipContext(ConstantContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::Const_ipContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConst_ip(this);
}
void NFCompilerParser::Const_ipContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConst_ip(this);
}
//----------------- Const_floatContext ------------------------------------------------------------------

tree::TerminalNode* NFCompilerParser::Const_floatContext::FLOAT() {
  return getToken(NFCompilerParser::FLOAT, 0);
}

NFCompilerParser::Const_floatContext::Const_floatContext(ConstantContext *ctx) { copyFrom(ctx); }

void NFCompilerParser::Const_floatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConst_float(this);
}
void NFCompilerParser::Const_floatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConst_float(this);
}
NFCompilerParser::ConstantContext* NFCompilerParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 46, NFCompilerParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(269);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case NFCompilerParser::IP: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<NFCompilerParser::Const_ipContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(266);
        match(NFCompilerParser::IP);
        break;
      }

      case NFCompilerParser::INT: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<NFCompilerParser::Const_intContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(267);
        match(NFCompilerParser::INT);
        break;
      }

      case NFCompilerParser::FLOAT: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<NFCompilerParser::Const_floatContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(268);
        match(NFCompilerParser::FLOAT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Flow_or_rule_entryContext ------------------------------------------------------------------

NFCompilerParser::Flow_or_rule_entryContext::Flow_or_rule_entryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

NFCompilerParser::FieldsContext* NFCompilerParser::Flow_or_rule_entryContext::fields() {
  return getRuleContext<NFCompilerParser::FieldsContext>(0);
}

tree::TerminalNode* NFCompilerParser::Flow_or_rule_entryContext::COLON() {
  return getToken(NFCompilerParser::COLON, 0);
}

NFCompilerParser::ConstantContext* NFCompilerParser::Flow_or_rule_entryContext::constant() {
  return getRuleContext<NFCompilerParser::ConstantContext>(0);
}


size_t NFCompilerParser::Flow_or_rule_entryContext::getRuleIndex() const {
  return NFCompilerParser::RuleFlow_or_rule_entry;
}

void NFCompilerParser::Flow_or_rule_entryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFlow_or_rule_entry(this);
}

void NFCompilerParser::Flow_or_rule_entryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFlow_or_rule_entry(this);
}


antlrcpp::Any NFCompilerParser::Flow_or_rule_entryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitFlow_or_rule_entry(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::Flow_or_rule_entryContext* NFCompilerParser::flow_or_rule_entry() {
  Flow_or_rule_entryContext *_localctx = _tracker.createInstance<Flow_or_rule_entryContext>(_ctx, getState());
  enterRule(_localctx, 48, NFCompilerParser::RuleFlow_or_rule_entry);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(271);
    fields();
    setState(272);
    match(NFCompilerParser::COLON);
    setState(273);
    constant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpContext ------------------------------------------------------------------

NFCompilerParser::OpContext::OpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

NFCompilerParser::Expr_opContext* NFCompilerParser::OpContext::expr_op() {
  return getRuleContext<NFCompilerParser::Expr_opContext>(0);
}

NFCompilerParser::Rel_opContext* NFCompilerParser::OpContext::rel_op() {
  return getRuleContext<NFCompilerParser::Rel_opContext>(0);
}


size_t NFCompilerParser::OpContext::getRuleIndex() const {
  return NFCompilerParser::RuleOp;
}

void NFCompilerParser::OpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp(this);
}

void NFCompilerParser::OpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp(this);
}


antlrcpp::Any NFCompilerParser::OpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitOp(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::OpContext* NFCompilerParser::op() {
  OpContext *_localctx = _tracker.createInstance<OpContext>(_ctx, getState());
  enterRule(_localctx, 50, NFCompilerParser::RuleOp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(277);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case NFCompilerParser::ADD:
      case NFCompilerParser::SUB:
      case NFCompilerParser::MUL:
      case NFCompilerParser::DIV:
      case NFCompilerParser::MOD:
      case NFCompilerParser::AND:
      case NFCompilerParser::OR:
      case NFCompilerParser::UNION:
      case NFCompilerParser::INTERSECTION:
      case NFCompilerParser::DIFFER:
      case NFCompilerParser::NOT: {
        enterOuterAlt(_localctx, 1);
        setState(275);
        expr_op();
        break;
      }

      case NFCompilerParser::EQUAL:
      case NFCompilerParser::UNEQUAL:
      case NFCompilerParser::LOE:
      case NFCompilerParser::BOE:
      case NFCompilerParser::LT:
      case NFCompilerParser::BT:
      case NFCompilerParser::IN:
      case NFCompilerParser::SUBSET:
      case NFCompilerParser::MATCH:
      case NFCompilerParser::CONNECTION:
      case NFCompilerParser::DATA:
      case NFCompilerParser::COLON: {
        enterOuterAlt(_localctx, 2);
        setState(276);
        rel_op();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr_opContext ------------------------------------------------------------------

NFCompilerParser::Expr_opContext::Expr_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NFCompilerParser::Expr_opContext::ADD() {
  return getToken(NFCompilerParser::ADD, 0);
}

tree::TerminalNode* NFCompilerParser::Expr_opContext::SUB() {
  return getToken(NFCompilerParser::SUB, 0);
}

tree::TerminalNode* NFCompilerParser::Expr_opContext::MUL() {
  return getToken(NFCompilerParser::MUL, 0);
}

tree::TerminalNode* NFCompilerParser::Expr_opContext::DIV() {
  return getToken(NFCompilerParser::DIV, 0);
}

tree::TerminalNode* NFCompilerParser::Expr_opContext::MOD() {
  return getToken(NFCompilerParser::MOD, 0);
}

tree::TerminalNode* NFCompilerParser::Expr_opContext::OR() {
  return getToken(NFCompilerParser::OR, 0);
}

tree::TerminalNode* NFCompilerParser::Expr_opContext::AND() {
  return getToken(NFCompilerParser::AND, 0);
}

tree::TerminalNode* NFCompilerParser::Expr_opContext::NOT() {
  return getToken(NFCompilerParser::NOT, 0);
}

tree::TerminalNode* NFCompilerParser::Expr_opContext::UNION() {
  return getToken(NFCompilerParser::UNION, 0);
}

tree::TerminalNode* NFCompilerParser::Expr_opContext::INTERSECTION() {
  return getToken(NFCompilerParser::INTERSECTION, 0);
}

tree::TerminalNode* NFCompilerParser::Expr_opContext::DIFFER() {
  return getToken(NFCompilerParser::DIFFER, 0);
}


size_t NFCompilerParser::Expr_opContext::getRuleIndex() const {
  return NFCompilerParser::RuleExpr_op;
}

void NFCompilerParser::Expr_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_op(this);
}

void NFCompilerParser::Expr_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_op(this);
}


antlrcpp::Any NFCompilerParser::Expr_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitExpr_op(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::Expr_opContext* NFCompilerParser::expr_op() {
  Expr_opContext *_localctx = _tracker.createInstance<Expr_opContext>(_ctx, getState());
  enterRule(_localctx, 52, NFCompilerParser::RuleExpr_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << NFCompilerParser::ADD)
      | (1ULL << NFCompilerParser::SUB)
      | (1ULL << NFCompilerParser::MUL)
      | (1ULL << NFCompilerParser::DIV)
      | (1ULL << NFCompilerParser::MOD)
      | (1ULL << NFCompilerParser::AND)
      | (1ULL << NFCompilerParser::OR)
      | (1ULL << NFCompilerParser::UNION)
      | (1ULL << NFCompilerParser::INTERSECTION)
      | (1ULL << NFCompilerParser::DIFFER)
      | (1ULL << NFCompilerParser::NOT))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_opContext ------------------------------------------------------------------

NFCompilerParser::Rel_opContext::Rel_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NFCompilerParser::Rel_opContext::EQUAL() {
  return getToken(NFCompilerParser::EQUAL, 0);
}

tree::TerminalNode* NFCompilerParser::Rel_opContext::UNEQUAL() {
  return getToken(NFCompilerParser::UNEQUAL, 0);
}

tree::TerminalNode* NFCompilerParser::Rel_opContext::LOE() {
  return getToken(NFCompilerParser::LOE, 0);
}

tree::TerminalNode* NFCompilerParser::Rel_opContext::BOE() {
  return getToken(NFCompilerParser::BOE, 0);
}

tree::TerminalNode* NFCompilerParser::Rel_opContext::LT() {
  return getToken(NFCompilerParser::LT, 0);
}

tree::TerminalNode* NFCompilerParser::Rel_opContext::BT() {
  return getToken(NFCompilerParser::BT, 0);
}

tree::TerminalNode* NFCompilerParser::Rel_opContext::IN() {
  return getToken(NFCompilerParser::IN, 0);
}

tree::TerminalNode* NFCompilerParser::Rel_opContext::SUBSET() {
  return getToken(NFCompilerParser::SUBSET, 0);
}

tree::TerminalNode* NFCompilerParser::Rel_opContext::MATCH() {
  return getToken(NFCompilerParser::MATCH, 0);
}

tree::TerminalNode* NFCompilerParser::Rel_opContext::COLON() {
  return getToken(NFCompilerParser::COLON, 0);
}

tree::TerminalNode* NFCompilerParser::Rel_opContext::CONNECTION() {
  return getToken(NFCompilerParser::CONNECTION, 0);
}

tree::TerminalNode* NFCompilerParser::Rel_opContext::DATA() {
  return getToken(NFCompilerParser::DATA, 0);
}


size_t NFCompilerParser::Rel_opContext::getRuleIndex() const {
  return NFCompilerParser::RuleRel_op;
}

void NFCompilerParser::Rel_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_op(this);
}

void NFCompilerParser::Rel_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_op(this);
}


antlrcpp::Any NFCompilerParser::Rel_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitRel_op(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::Rel_opContext* NFCompilerParser::rel_op() {
  Rel_opContext *_localctx = _tracker.createInstance<Rel_opContext>(_ctx, getState());
  enterRule(_localctx, 54, NFCompilerParser::RuleRel_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << NFCompilerParser::EQUAL)
      | (1ULL << NFCompilerParser::UNEQUAL)
      | (1ULL << NFCompilerParser::LOE)
      | (1ULL << NFCompilerParser::BOE)
      | (1ULL << NFCompilerParser::LT)
      | (1ULL << NFCompilerParser::BT)
      | (1ULL << NFCompilerParser::IN)
      | (1ULL << NFCompilerParser::SUBSET)
      | (1ULL << NFCompilerParser::MATCH)
      | (1ULL << NFCompilerParser::CONNECTION)
      | (1ULL << NFCompilerParser::DATA)
      | (1ULL << NFCompilerParser::COLON))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldsContext ------------------------------------------------------------------

NFCompilerParser::FieldsContext::FieldsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NFCompilerParser::FieldsContext::FIELD() {
  return getToken(NFCompilerParser::FIELD, 0);
}


size_t NFCompilerParser::FieldsContext::getRuleIndex() const {
  return NFCompilerParser::RuleFields;
}

void NFCompilerParser::FieldsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFields(this);
}

void NFCompilerParser::FieldsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NFCompilerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFields(this);
}


antlrcpp::Any NFCompilerParser::FieldsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NFCompilerVisitor*>(visitor))
    return parserVisitor->visitFields(this);
  else
    return visitor->visitChildren(this);
}

NFCompilerParser::FieldsContext* NFCompilerParser::fields() {
  FieldsContext *_localctx = _tracker.createInstance<FieldsContext>(_ctx, getState());
  enterRule(_localctx, 56, NFCompilerParser::RuleFields);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    match(NFCompilerParser::FIELD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool NFCompilerParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 15: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool NFCompilerParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> NFCompilerParser::_decisionToDFA;
atn::PredictionContextCache NFCompilerParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN NFCompilerParser::_atn;
std::vector<uint16_t> NFCompilerParser::_serializedATN;

std::vector<std::string> NFCompilerParser::_ruleNames = {
  "program", "entries", "entry", "match_action", "action_statements", "match_flow", 
  "match_state", "action_flow", "action_state", "declaration", "declare_entry", 
  "type", "condition", "statement", "assignment", "expression", "item", 
  "contents", "key_pairs", "key_value", "function_call", "funcs", "expression_list", 
  "constant", "flow_or_rule_entry", "op", "expr_op", "rel_op", "fields"
};

std::vector<std::string> NFCompilerParser::_literalNames = {
  "", "", "'set'", "'map'", "'flow'", "'rule'", "", "'DROP'", "'entry'", 
  "'pass'", "'timer'", "'resubmit'", "'accept'", "'send_to'", "'send_back'", 
  "'connect'", "'max'", "'recv'", "'+'", "'-'", "'*'", "'/'", "'%'", "'&&'", 
  "'||'", "'|'", "'&'", "'\\'", "", "'=='", "'!='", "'<='", "'>='", "'<'", 
  "'>'", "'in'", "'subset of'", "", "'connection'", "'data'", "','", "'('", 
  "')'", "'{'", "'}'", "'['", "']'", "':'", "'program'", "'='", "';'", "'match_flow'", 
  "'match_state'", "'action_flow'", "'action_state'", "'new_packet'"
};

std::vector<std::string> NFCompilerParser::_symbolicNames = {
  "", "BASIC_TYPE", "SET", "MAP", "FLOW", "RULE", "FIELD", "ACTION", "ENTRY", 
  "PASS", "TIMER", "RESUBMIT", "ACCEPT", "SEND_TO", "SEND_BACK", "CONNECT", 
  "MAX", "RECV", "ADD", "SUB", "MUL", "DIV", "MOD", "AND", "OR", "UNION", 
  "INTERSECTION", "DIFFER", "NOT", "EQUAL", "UNEQUAL", "LOE", "BOE", "LT", 
  "BT", "IN", "SUBSET", "MATCH", "CONNECTION", "DATA", "COMMA", "LB", "RB", 
  "LCB", "RCB", "LSB", "RSB", "COLON", "START", "ASSIGN", "SEMICOLON", "MATCH_FLOW", 
  "MATCH_STATE", "ACTION_FLOW", "ACTION_STATE", "NEW_PACKET", "IP", "INT", 
  "FLOAT", "IDENT", "BLOCK_COMMENT", "LINE_COMMENT", "WS"
};

dfa::Vocabulary NFCompilerParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> NFCompilerParser::_tokenNames;

NFCompilerParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x40, 0x120, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x6, 0x3, 0x46, 0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 0x47, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x5, 0x5, 0x50, 
    0xa, 0x5, 0x3, 0x5, 0x5, 0x5, 0x53, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x6, 0x5, 0x6, 0x58, 0xa, 0x6, 0x3, 0x6, 0x5, 0x6, 0x5b, 0xa, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x7, 
    0xb, 0x72, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x75, 0xb, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x7d, 0xa, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x81, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x92, 
    0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x97, 0xa, 0xe, 0xc, 
    0xe, 0xe, 0xe, 0x9a, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x5, 0xf, 0xa0, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xa4, 0xa, 0xf, 
    0xc, 0xf, 0xe, 0xf, 0xa7, 0xb, 0xf, 0x3, 0x10, 0x5, 0x10, 0xaa, 0xa, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xb5, 0xa, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0xbb, 0xa, 0x11, 0xc, 0x11, 
    0xe, 0x11, 0xbe, 0xb, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x5, 0x12, 0xc5, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x7, 0x12, 0xcb, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xce, 0xb, 
    0x12, 0x5, 0x12, 0xd0, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xe6, 0xa, 0x12, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0xeb, 0xa, 0x13, 0xc, 0x13, 0xe, 
    0x13, 0xee, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0xf3, 
    0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0xf6, 0xb, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0xff, 
    0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x7, 0x18, 0x108, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 
    0x10b, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x110, 
    0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 
    0x1b, 0x5, 0x1b, 0x118, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x2, 0x3, 0x20, 0x1f, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 
    0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 
    0x36, 0x38, 0x3a, 0x2, 0x5, 0x3, 0x2, 0xc, 0x13, 0x3, 0x2, 0x14, 0x1e, 
    0x4, 0x2, 0x1f, 0x29, 0x31, 0x31, 0x2, 0x128, 0x2, 0x3c, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x45, 0x3, 0x2, 0x2, 0x2, 0x6, 0x49, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0xa, 0x57, 0x3, 0x2, 0x2, 0x2, 0xc, 0x5c, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x61, 0x3, 0x2, 0x2, 0x2, 0x10, 0x66, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x14, 0x73, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x76, 0x3, 0x2, 0x2, 0x2, 0x18, 0x91, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x93, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x9f, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x20, 0xb4, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0xe5, 0x3, 0x2, 0x2, 0x2, 0x24, 0xe7, 0x3, 0x2, 0x2, 0x2, 0x26, 0xef, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xfb, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x102, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x104, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x32, 0x111, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x117, 0x3, 0x2, 0x2, 0x2, 0x36, 0x119, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x3d, 0x7, 0x32, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0x3d, 0x2, 0x2, 0x3e, 0x3f, 
    0x7, 0x2d, 0x2, 0x2, 0x3f, 0x40, 0x5, 0x14, 0xb, 0x2, 0x40, 0x41, 0x5, 
    0x4, 0x3, 0x2, 0x41, 0x42, 0x7, 0x2e, 0x2, 0x2, 0x42, 0x43, 0x7, 0x2, 
    0x2, 0x3, 0x43, 0x3, 0x3, 0x2, 0x2, 0x2, 0x44, 0x46, 0x5, 0x6, 0x4, 
    0x2, 0x45, 0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x7, 0xa, 0x2, 0x2, 0x4a, 0x4b, 
    0x7, 0x2d, 0x2, 0x2, 0x4b, 0x4c, 0x5, 0x8, 0x5, 0x2, 0x4c, 0x4d, 0x7, 
    0x2e, 0x2, 0x2, 0x4d, 0x7, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x50, 0x5, 0xc, 
    0x7, 0x2, 0x4f, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x52, 0x3, 0x2, 0x2, 0x2, 0x51, 0x53, 0x5, 0xe, 0x8, 0x2, 
    0x52, 0x51, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 
    0x54, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x5, 0xa, 0x6, 0x2, 0x55, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x56, 0x58, 0x5, 0x10, 0x9, 0x2, 0x57, 0x56, 0x3, 
    0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5a, 0x3, 0x2, 
    0x2, 0x2, 0x59, 0x5b, 0x5, 0x12, 0xa, 0x2, 0x5a, 0x59, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x5d, 0x7, 0x35, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0x2d, 0x2, 0x2, 0x5e, 
    0x5f, 0x5, 0x1a, 0xe, 0x2, 0x5f, 0x60, 0x7, 0x2e, 0x2, 0x2, 0x60, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x7, 0x36, 0x2, 0x2, 0x62, 0x63, 0x7, 
    0x2d, 0x2, 0x2, 0x63, 0x64, 0x5, 0x1a, 0xe, 0x2, 0x64, 0x65, 0x7, 0x2e, 
    0x2, 0x2, 0x65, 0xf, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x7, 0x37, 0x2, 
    0x2, 0x67, 0x68, 0x7, 0x2d, 0x2, 0x2, 0x68, 0x69, 0x5, 0x1c, 0xf, 0x2, 
    0x69, 0x6a, 0x7, 0x2e, 0x2, 0x2, 0x6a, 0x11, 0x3, 0x2, 0x2, 0x2, 0x6b, 
    0x6c, 0x7, 0x38, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x2d, 0x2, 0x2, 0x6d, 0x6e, 
    0x5, 0x1c, 0xf, 0x2, 0x6e, 0x6f, 0x7, 0x2e, 0x2, 0x2, 0x6f, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0x70, 0x72, 0x5, 0x16, 0xc, 0x2, 0x71, 0x70, 0x3, 0x2, 
    0x2, 0x2, 0x72, 0x75, 0x3, 0x2, 0x2, 0x2, 0x73, 0x71, 0x3, 0x2, 0x2, 
    0x2, 0x73, 0x74, 0x3, 0x2, 0x2, 0x2, 0x74, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x5, 0x18, 0xd, 0x2, 0x77, 
    0x7c, 0x7, 0x3d, 0x2, 0x2, 0x78, 0x79, 0x7, 0x2b, 0x2, 0x2, 0x79, 0x7a, 
    0x5, 0x20, 0x11, 0x2, 0x7a, 0x7b, 0x7, 0x2c, 0x2, 0x2, 0x7b, 0x7d, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x3, 0x2, 
    0x2, 0x2, 0x7d, 0x80, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x33, 0x2, 
    0x2, 0x7f, 0x81, 0x5, 0x20, 0x11, 0x2, 0x80, 0x7e, 0x3, 0x2, 0x2, 0x2, 
    0x80, 0x81, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 0x2, 0x82, 
    0x83, 0x7, 0x34, 0x2, 0x2, 0x83, 0x17, 0x3, 0x2, 0x2, 0x2, 0x84, 0x92, 
    0x7, 0x3, 0x2, 0x2, 0x85, 0x86, 0x7, 0x4, 0x2, 0x2, 0x86, 0x87, 0x7, 
    0x23, 0x2, 0x2, 0x87, 0x88, 0x7, 0x3, 0x2, 0x2, 0x88, 0x92, 0x7, 0x24, 
    0x2, 0x2, 0x89, 0x8a, 0x7, 0x5, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0x23, 0x2, 
    0x2, 0x8b, 0x8c, 0x5, 0x18, 0xd, 0x2, 0x8c, 0x8d, 0x7, 0x2a, 0x2, 0x2, 
    0x8d, 0x8e, 0x5, 0x18, 0xd, 0x2, 0x8e, 0x8f, 0x7, 0x24, 0x2, 0x2, 0x8f, 
    0x92, 0x3, 0x2, 0x2, 0x2, 0x90, 0x92, 0x7, 0x7, 0x2, 0x2, 0x91, 0x84, 
    0x3, 0x2, 0x2, 0x2, 0x91, 0x85, 0x3, 0x2, 0x2, 0x2, 0x91, 0x89, 0x3, 
    0x2, 0x2, 0x2, 0x91, 0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x93, 0x94, 0x5, 0x20, 0x11, 0x2, 0x94, 0x98, 0x7, 0x34, 0x2, 
    0x2, 0x95, 0x97, 0x5, 0x20, 0x11, 0x2, 0x96, 0x95, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x98, 0x96, 0x3, 0x2, 0x2, 0x2, 0x98, 
    0x99, 0x3, 0x2, 0x2, 0x2, 0x99, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x98, 
    0x3, 0x2, 0x2, 0x2, 0x9b, 0xa0, 0x5, 0x1e, 0x10, 0x2, 0x9c, 0xa0, 0x5, 
    0x2a, 0x16, 0x2, 0x9d, 0xa0, 0x7, 0xb, 0x2, 0x2, 0x9e, 0xa0, 0x7, 0xd, 
    0x2, 0x2, 0x9f, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9c, 0x3, 0x2, 0x2, 
    0x2, 0x9f, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9e, 0x3, 0x2, 0x2, 0x2, 
    0xa0, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa5, 0x7, 0x34, 0x2, 0x2, 0xa2, 
    0xa4, 0x5, 0x1c, 0xf, 0x2, 0xa3, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa7, 
    0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x3, 
    0x2, 0x2, 0x2, 0xa6, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa5, 0x3, 0x2, 
    0x2, 0x2, 0xa8, 0xaa, 0x7, 0x3, 0x2, 0x2, 0xa9, 0xa8, 0x3, 0x2, 0x2, 
    0x2, 0xa9, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x3, 0x2, 0x2, 0x2, 
    0xab, 0xac, 0x5, 0x20, 0x11, 0x2, 0xac, 0xad, 0x7, 0x33, 0x2, 0x2, 0xad, 
    0xae, 0x5, 0x20, 0x11, 0x2, 0xae, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 
    0x8, 0x11, 0x1, 0x2, 0xb0, 0xb5, 0x5, 0x22, 0x12, 0x2, 0xb1, 0xb2, 0x5, 
    0x34, 0x1b, 0x2, 0xb2, 0xb3, 0x5, 0x20, 0x11, 0x4, 0xb3, 0xb5, 0x3, 
    0x2, 0x2, 0x2, 0xb4, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb1, 0x3, 0x2, 
    0x2, 0x2, 0xb5, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0xc, 0x3, 0x2, 
    0x2, 0xb7, 0xb8, 0x5, 0x34, 0x1b, 0x2, 0xb8, 0xb9, 0x5, 0x20, 0x11, 
    0x4, 0xb9, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb6, 0x3, 0x2, 0x2, 0x2, 
    0xbb, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbc, 
    0xbd, 0x3, 0x2, 0x2, 0x2, 0xbd, 0x21, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbc, 
    0x3, 0x2, 0x2, 0x2, 0xbf, 0xcf, 0x7, 0x3d, 0x2, 0x2, 0xc0, 0xc1, 0x7, 
    0x2f, 0x2, 0x2, 0xc1, 0xc2, 0x5, 0x3a, 0x1e, 0x2, 0xc2, 0xc3, 0x7, 0x30, 
    0x2, 0x2, 0xc3, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc0, 0x3, 0x2, 0x2, 
    0x2, 0xc4, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xd0, 0x3, 0x2, 0x2, 0x2, 
    0xc6, 0xc7, 0x7, 0x2f, 0x2, 0x2, 0xc7, 0xc8, 0x5, 0x20, 0x11, 0x2, 0xc8, 
    0xc9, 0x7, 0x30, 0x2, 0x2, 0xc9, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc6, 
    0x3, 0x2, 0x2, 0x2, 0xcb, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xca, 0x3, 
    0x2, 0x2, 0x2, 0xcc, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xd0, 0x3, 0x2, 
    0x2, 0x2, 0xce, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xc4, 0x3, 0x2, 0x2, 
    0x2, 0xcf, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xe6, 0x3, 0x2, 0x2, 0x2, 
    0xd1, 0xe6, 0x5, 0x2a, 0x16, 0x2, 0xd2, 0xe6, 0x5, 0x32, 0x1a, 0x2, 
    0xd3, 0xe6, 0x5, 0x30, 0x19, 0x2, 0xd4, 0xd5, 0x7, 0x2d, 0x2, 0x2, 0xd5, 
    0xd6, 0x5, 0x24, 0x13, 0x2, 0xd6, 0xd7, 0x7, 0x2e, 0x2, 0x2, 0xd7, 0xe6, 
    0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x7, 0x2d, 0x2, 0x2, 0xd9, 0xda, 0x5, 
    0x26, 0x14, 0x2, 0xda, 0xdb, 0x7, 0x2e, 0x2, 0x2, 0xdb, 0xe6, 0x3, 0x2, 
    0x2, 0x2, 0xdc, 0xdd, 0x7, 0x2b, 0x2, 0x2, 0xdd, 0xde, 0x5, 0x20, 0x11, 
    0x2, 0xde, 0xdf, 0x7, 0x2c, 0x2, 0x2, 0xdf, 0xe6, 0x3, 0x2, 0x2, 0x2, 
    0xe0, 0xe6, 0x7, 0x9, 0x2, 0x2, 0xe1, 0xe6, 0x5, 0x3a, 0x1e, 0x2, 0xe2, 
    0xe3, 0x7, 0x39, 0x2, 0x2, 0xe3, 0xe4, 0x7, 0x2b, 0x2, 0x2, 0xe4, 0xe6, 
    0x7, 0x2c, 0x2, 0x2, 0xe5, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xd1, 0x3, 
    0x2, 0x2, 0x2, 0xe5, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xd3, 0x3, 0x2, 
    0x2, 0x2, 0xe5, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xd8, 0x3, 0x2, 0x2, 
    0x2, 0xe5, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe0, 0x3, 0x2, 0x2, 0x2, 
    0xe5, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe6, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xec, 0x5, 0x22, 0x12, 0x2, 0xe8, 0xe9, 
    0x7, 0x2a, 0x2, 0x2, 0xe9, 0xeb, 0x5, 0x22, 0x12, 0x2, 0xea, 0xe8, 0x3, 
    0x2, 0x2, 0x2, 0xeb, 0xee, 0x3, 0x2, 0x2, 0x2, 0xec, 0xea, 0x3, 0x2, 
    0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 0x2, 0x2, 0xed, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0xee, 0xec, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf4, 0x5, 0x28, 0x15, 0x2, 
    0xf0, 0xf1, 0x7, 0x2a, 0x2, 0x2, 0xf1, 0xf3, 0x5, 0x28, 0x15, 0x2, 0xf2, 
    0xf0, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf2, 
    0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf5, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0xf6, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x5, 0x30, 
    0x19, 0x2, 0xf8, 0xf9, 0x7, 0x31, 0x2, 0x2, 0xf9, 0xfa, 0x5, 0x30, 0x19, 
    0x2, 0xfa, 0x29, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x5, 0x2c, 0x17, 0x2, 
    0xfc, 0xfe, 0x7, 0x2b, 0x2, 0x2, 0xfd, 0xff, 0x5, 0x2e, 0x18, 0x2, 0xfe, 
    0xfd, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 
    0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x7, 0x2c, 0x2, 0x2, 0x101, 0x2b, 
    0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x9, 0x2, 0x2, 0x2, 0x103, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x104, 0x109, 0x5, 0x20, 0x11, 0x2, 0x105, 0x106, 0x7, 
    0x2a, 0x2, 0x2, 0x106, 0x108, 0x5, 0x20, 0x11, 0x2, 0x107, 0x105, 0x3, 
    0x2, 0x2, 0x2, 0x108, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x109, 0x107, 0x3, 
    0x2, 0x2, 0x2, 0x109, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x10b, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x110, 0x7, 0x3a, 
    0x2, 0x2, 0x10d, 0x110, 0x7, 0x3b, 0x2, 0x2, 0x10e, 0x110, 0x7, 0x3c, 
    0x2, 0x2, 0x10f, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x10d, 0x3, 0x2, 
    0x2, 0x2, 0x10f, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x110, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x111, 0x112, 0x5, 0x3a, 0x1e, 0x2, 0x112, 0x113, 0x7, 0x31, 0x2, 
    0x2, 0x113, 0x114, 0x5, 0x30, 0x19, 0x2, 0x114, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x115, 0x118, 0x5, 0x36, 0x1c, 0x2, 0x116, 0x118, 0x5, 0x38, 0x1d, 
    0x2, 0x117, 0x115, 0x3, 0x2, 0x2, 0x2, 0x117, 0x116, 0x3, 0x2, 0x2, 
    0x2, 0x118, 0x35, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x9, 0x3, 0x2, 0x2, 
    0x11a, 0x37, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x9, 0x4, 0x2, 0x2, 0x11c, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 0x7, 0x8, 0x2, 0x2, 0x11e, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0x1b, 0x47, 0x4f, 0x52, 0x57, 0x5a, 0x73, 0x7c, 
    0x80, 0x91, 0x98, 0x9f, 0xa5, 0xa9, 0xb4, 0xbc, 0xc4, 0xcc, 0xcf, 0xe5, 
    0xec, 0xf4, 0xfe, 0x109, 0x10f, 0x117, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

NFCompilerParser::Initializer NFCompilerParser::_init;
