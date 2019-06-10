#include <z3++.h>
#include <vector>

//#include "pkt.h"
//#include "instructions.h"

using namespace z3;
using namespace std;


#ifndef TRACE_H
#define TRACE_H

struct tracenode {
  expr Expr;
  bool decl;
  struct tracenode *left, *right;
};

class trace {
  context ctx;
  struct tracenode *root;
  //solver s;
  //struct packet *pkt;
  vector<struct allocate_in*> allocate_ins;
  vector<struct assign_in*> assign_ins;
  vector<struct assert_in*> assert_ins;
  //vector<Z3_ast> ASTs;
  //vector<expr> decl_Exprs;
  //vector<expr> Exprs;

  public:

  trace();
  struct tracenode *add_node(expr e, bool decl);
  vector<struct tracenode*> leaf_nodes(struct tracenode *node); 
  expr get_expr(string a, string op, int value);
  //void add_sym_pkt(char *name);
  void add_allocate_in(string a, int size);
  void add_assign_in(string a, int value);
  void add_assert_in(string a, string op, int d);
  void add_ite_node(expr e1, expr e2, expr e3);
  int execute();
  bool is_allocated(string a);
  struct allocate_in *allocated_sym(string a);
  void print_trace();
};

#endif
