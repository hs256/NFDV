#include "z3++.h"
#include <vector>

#include "pkt.h"
#include "instructions.h"

using namespace z3;
using namespace std;


#ifndef TRACE_H
#define TRACE_H

class trace {
  context c;
  //solver s;
  struct packet *pkt;
  vector<struct allocate_in*> allocate_ins;
  vector<struct assign_in*> assign_ins;
  vector<struct assert_in*> assert_ins;

  public:

  trace();
  //void add_sym_pkt(char *name);
  void add_allocate_in(string a, int size);
  void add_assign_in(string a, int value);
  void add_assert_in(string a, string op, int d);
  int execute();
  bool is_allocated(string a);
  expr allocated_expr(string a);
};

#endif
