#ifndef ENTRY_H
#define ENTRY_H

struct match_flow {
  int match;
  string var;
};

struct action_flow {
  string field;
  string action;
};

#endif
