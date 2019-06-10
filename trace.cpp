#include <vector>
#include <z3++.h>

#include "trace.h"
#include "instructions.h"

using namespace std;
using namespace z3;

vector<struct tracenode*> leaf_nodes(struct tracenode *node) {
  vector<struct tracenode*> leaves;
  if (node == NULL)
    return leaves;
  if (node->left == NULL && node->right == NULL) {
    leaves.push_back(node);
    return leaves;
  }
  return leaf_nodes(node->left);
  return leaf_nodes(node->right);
}


struct tracenode* trace::add_node(expr e, bool decl) {
  struct tracenode *temp = new tracenode;
  temp->Expr = e;
  temp->decl = decl;
  vector<struct tracenode*> leaves = leaf_nodes(root);
  vector<struct tracenode*>::iterator it;
  for (it = leaves.begin(); it != leaves.end(); it++) {
    (*it)->left = temp;
  }
  return temp;
}

expr trace::get_expr(string a, string op, int value) {
  vector<expr>::iterator it;
  expr eq2;
  for (it = trace::decl_Exprs.begin(); it != trace::decl_Exprs.end(); it++) {
    if ((*it).decl().name().str() == a) {
      if (op == ">=") {
	eq2 = (*it) >=  value;
      } else if (op == ">") {
	eq2 = (*it) > value;
      } else if (op == "<") {
	eq2 = (*it) < value;
      } else if (op == "<=") {
	eq2 = (*it) <= value;
      } else if (op == "==") {
	eq2 = (*it) == value;
      }
      return eq2;
    }
  }
}

struct tracenode* trace::add_ite_node(expr e1, expr e2, expr e3) {
  struct tracenode *temp1 = new tracenode;
  struct tracenode *temp2 = new tracenode;
  struct tracenode *temp3 = new tracenode;
  temp1->expr = e1;
  temp1->decl = false;
  temp2->expr = e2;
  temp2->decl = false;
  temp3->expr = e3;
  temp3->decl = false;
  vector<struct tracenode*> leaves = leaf_nodes(root);
  vector<struct tracenode*>::iterator it;
  for (it = leaves.begin(); it != leaves.end(); it++) {
    (*it)->left = temp1;
    (*it)->right = temp2;
    (*it)->left->left = temp3;
  }
  return temp;
}
void trace::add_allocate_in(string a, int size) {
  struct allocate_in *t = new allocate_in;
  t->id = trace::allocate_ins.size() + 1;
  t->var = a;
  t->size = size;
  trace::allocate_ins.push_back(t);
  string unique_name = a + to_string(t->id);
  const char *name = unique_name.c_str();
  Z3_sort int_sort = Z3_mk_int_sort(ctx);
  Z3_symbol s = Z3_mk_string_symbol(ctx, const_cast<char *>(name));
  Z3_ast x = Z3_mk_const(ctx, s, int_sort);
  expr eq(ctx, x);
  //trace::decl_Exprs.push_back(eq);
  trace::add_node(eq, true);
  cout << "ID: " << t->id << ", allocate(" << a << ", " << size << ")" << endl;
}

bool trace::is_allocated(string a) {
  vector<struct allocate_in*>::iterator it;
  for (it = trace::allocate_ins.begin(); it != trace::allocate_ins.end(); it++) {
    if ((*it)->var == a)
      return true;
  }

  return false;
}

struct allocate_in* trace::allocated_sym(string a) {
  vector<struct allocate_in*>::iterator it;
  for (it = trace::allocate_ins.begin(); it != trace::allocate_ins.end(); it++) {
    if ((*it)->var == a)
      return (*it);
  }

  return NULL;
}


void trace::add_assign_in(string a, int value) {
  
  if (!trace::is_allocated(a)) {
    cout << "allocate the symbol first" << endl;
    return;
  } else {
    struct assign_in *t = new assign_in;
    t->id = assign_ins.size() + 1;
    t->var = a;
    t->value = value;
    trace::assign_ins.push_back(t);
    //struct allocate_in *ain = allocated_sym(a);
    //int eid = ain->expr_id;
    vector<expr>::iterator it;
    for (it = trace::decl_Exprs.begin(); it != trace::decl_Exprs.end(); it++) {
      if ((*it).decl().name().str() == a) {
	expr eq2 = (*it) ==  value;
	//trace::Exprs.push_back(eq2);
	trace::add_node(eq2, false);
      }
    }
    cout << "ID: " << t->id << ", assign(" << a << ", " << value << ")" << endl;
  }
}

void trace::add_assert_in(string a, string op, int value) {
  struct assert_in *t = new assert_in;
  t->id = assert_ins.size() + 1;
  t->var = a;
  t->op = op;
  t->d = value;
  trace::assert_ins.push_back(t);
  vector<expr>::iterator it;
  for (it = trace::decl_Exprs.begin(); it != trace::decl_Exprs.end(); it++) {
    if ((*it).decl().name().str() == a) {
      if (op == ">=") {
	expr eq2 = (*it) >=  value;
	//trace::Exprs.push_back(eq2);
	trace::add_node(eq2, false);
      } else if (op == ">") {
	expr eq2 = (*it) > value;
	//trace::Exprs.push_back(eq2);
	trace::add_node(eq2, false);
      } else if (op == "<") {
	expr eq2 = (*it) < value;
	//trace::Exprs.push_back(eq2);
	trace::add_node(eq2, false);
      } else if (op == "<=") {
	expr eq2 = (*it) <= value;
	//trace::Exprs.push_back(eq2);
	trace::add_node(eq2, false);
      } else if (op == "==") {
	expr eq2 = (*it) == value;
	//trace::Exprs.push_back(eq2);
	trace::add_node(eq2, false);
      }
    }
  }
  cout << "ID: " << t->id << ", assert(" << a << " " << op << " " << value << ")" << endl;
}

trace::trace() {
  trace::add_allocate_in("L3+0", 4);
  trace::add_allocate_in("L3+72", 8);
  trace::add_allocate_in("L3+96", 32);
  trace::add_assert_in("L3+96", ">=", 0);
  trace::add_assert_in("L3+96", "<=", 4294967296);
  trace::add_allocate_in("L3+128", 32);
  trace::add_assert_in("L3+128", ">=", 0);
  trace::add_assert_in("L3+128", "<=", 4294967296);
  trace::add_allocate_in("L3+64", 8);
  trace::add_assign_in("L3+64", 255);
  trace::add_allocate_in("L3+16", 16);
  trace::add_allocate_in("L3+4", 4);
  trace::add_allocate_in("L3+80", 16);
  trace::add_allocate_in("L3+32", 16);
  trace::add_allocate_in("L4+0", 16);
  trace::add_assert_in("L4+0", ">=", 0);
  trace::add_assert_in("L4+0", "<=", 65536);
  trace::add_allocate_in("L4+16", 16);
  trace::add_assert_in("L4+16", ">=", 0);
  trace::add_assert_in("L4+16", "<=", 65536);
  trace::add_allocate_in("L4+32", 32);
  trace::add_allocate_in("L4+64", 32);
  trace::add_allocate_in("L4+96", 4);
  trace::add_assign_in("L4+96", 160);
  trace::add_allocate_in("L4+100", 3);
  trace::add_allocate_in("L4+103", 1);
  trace::add_assign_in("L4+103", 0);
  trace::add_allocate_in("L4+104", 1);
  trace::add_assign_in("L4+104", 0);
  trace::add_allocate_in("L4+105", 1);
  trace::add_assign_in("L4+105", 0);
  trace::add_allocate_in("L4+106", 1);
  trace::add_assign_in("L4+106", 0);
  trace::add_allocate_in("L4+107", 1);
  trace::add_assign_in("L4+107", 0);
  trace::add_allocate_in("L4+108", 1);
  trace::add_assign_in("L4+108", 0);
  trace::add_allocate_in("L4+109", 1);
  trace::add_assign_in("L4+109", 0);
  trace::add_allocate_in("L4+110", 1);
  trace::add_allocate_in("L4+111", 1);

}

int trace::execute() {
  solver s(ctx);
  vector<expr>::iterator it;
  for (it = trace::Exprs.begin(); it != trace::Exprs.end(); it++) {
    s.add((*it));
  }
  cout << s.check() << endl;
  model m = s.get_model();
  cout << "Model:\n" << m << "\n";
}

  /*vector<struct allocate_in*>::iterator it_alloc;
  for (it_alloc = allocate_ins.begin(); it_alloc != allocate_ins.end(); it_alloc++) {
    string unique_name = (*it_alloc)->var + to_string((*it_alloc)->id);
    const char *name = unique_name.c_str();
    Z3_sort int_sort = Z3_mk_int_sort(ctx);
    Z3_symbol s = Z3_mk_string_symbol(ctx, const_cast<char *>(name));
    Z3_ast x = Z3_mk_const(ctx, s, int_sort);


  }

  vector<struct assign_in*>::iterator it_assign;
  for (it_assign = assign_ins.begin(); it_assign != assign_ins.end(); it_assign++) {
    string var_name = (*it_assign)->var;
    struct allocate_in *s = trace::allocated_sym(var_name);
    string unique_name = var_name + to_string(s->id);
  }

  vector<struct assert_in*>::iterator it_assert;
  for (it_assert = assert_ins.begin(); it_assert != assert_ins.end(); it_assert++) {
    //s.add(trace::allocated_expr(it_assert->a) it_assert->op it_assert->d);
  }

  std::cout << s << std::endl;
  std::cout << s->check() << std::endl;

  if (s->check() == "unsat")
    return -1;
  else
    return 0;
  return 0;
}*/

