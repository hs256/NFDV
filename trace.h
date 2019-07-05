#include <z3++.h>
#include <vector>

//#include "pkt.h"
//#include "instructions.h"

using namespace z3;
using namespace std;


#ifndef TRACE_H
#define TRACE_H

struct tracenode {
  int id;
  //expr Expr;
  string a;
  string op;
  int value;
  bool decl;
  struct tracenode *left, *right;
};

class trace {
  context ctx;
  struct tracenode *root;
  int allocate_ins_count;
  int assert_ins_count;
  //solver s;
  //struct packet *pkt;
  //vector<struct allocate_in*> allocate_ins;
  //vector<struct assign_in*> assign_ins;
  //vector<struct assert_in*> assert_ins;
  //vector<Z3_ast> ASTs;
  //vector<expr> decl_Exprs;
  //vector<expr> Exprs;

  public:

  trace();
  struct tracenode *add_node(expr e, bool decl);
  vector<struct tracenode*> leaf_nodes(struct tracenode *node, vector<struct tracenode*> leaves); 
  void del_node(struct tracenode *node);
  struct tracenode *parent_node(struct tracenode *tree, struct tracenode *node);
  bool compare_nodes(struct tracenode *t1, struct tracenode *t2);
  int count_allocate_ins();
  int count_assert_ins();
  struct tracenode *new_assert_node(string a, string op, int v);
  struct tracenode *new_decl_node(string s);
  void add_assert_node(string s1, string op, int v);
  void add_decl_node(string s);
  //expr get_expr(string a, string op, int value);
  //void add_sym_pkt(char *name);
  void add_allocate_in(string a, int size);
  void add_assign_in(string a, int value);
  void add_assert_in(string a, string op, int d);
  struct tracenode *add_ltree_nodes(struct tracenode *r, vector<struct tracenode*> tmp);
  void add_lrtree_nodes(struct tracenode *r, vector<struct tracenode*> tmp, int index, int index2);
  void add_ite_node(struct tracenode *t1, struct tracenode *t2, struct tracenode *t3);
  struct tracenode *lmost_node(struct tracenode *n);
  void add_mlrite_nodes(vector<struct tracenode *> action, vector<struct tracenode *> tmp);
  void add_mite_node(vector<struct tracenode *> tmp1, vector<struct tracenode *> tmp2, struct tracenode *action);
  int execute();
  bool is_allocated(string a);
  struct allocate_in *allocated_sym(string a);
  void print_trace();
  void print_all_paths();
  vector<vector<struct tracenode *>> get_paths(struct tracenode *node, vector<vector<struct tracenode*>> paths, vector<struct tracenode*> path);
};

#endif
