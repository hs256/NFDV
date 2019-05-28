




// Generated from NFCompiler.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  NFCompilerLexer : public antlr4::Lexer {
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

  NFCompilerLexer(antlr4::CharStream *input);
  ~NFCompilerLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

