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

struct match_state {
  string state_var;
  string op;
  string state_val;
};

struct action_state {
  string state_var;
  string op;
  string state_val;
};

struct match_entry_flow {
  bool op;
  struct match_flow *mf;
};

struct entry {
  vector<struct match_entry_flow *> m_f;
  struct action_flow *a_f;
  struct match_state *m_s;
  vector<struct action_state *> a_s;
};
#endif
