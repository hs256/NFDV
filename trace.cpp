#include <vector>
#include <z3.h>

#include "trace.h"
#include "instructions.h"


void trace::add_allocate_in(string a, int size) {
  struct allocate_in *t = new allocate_in;
  t->id = trace::allocate_ins.size() + 1;
  t->var = a;
  t->size = size;
  trace::allocate_ins.push_back(t);
}

bool trace::is_allocated(string a) {
  vector<struct allocate_in*>::iterator it;
  for (it = trace::allocate_ins.begin(); it != trace::allocate_ins.end(); it++) {
    if ((*it)->var == a)
      return true;
  }

  return false;
}

/*expr trace::allocated_expr(string a) {
  vector<struct allocate_in*>::iterator it;
  for (it = trace::allocate_ins.begin(); it != trace::allocate_ins.end(); it++) {
    if ((*it)->var == a)
      return (*it)->expr;
  }

  return NULL;
}*/


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
  }
}

void trace::add_assert_in(string a, string op, int value) {
  struct assert_in *t = new assert_in;
  t->id = assert_ins.size() + 1;
  t->var = a;
  t->op = op;
  t->d = value;
  trace::assert_ins.push_back(t);
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

}

int trace::execute() {

  /*vector<struct allocate_in*>::iterator it_alloc;
  for (it_alloc = allocate_ins.begin(); it_alloc != allocate_ins.end(); it_alloc++) {
    (*it_alloc)->e = c.int_const((*it_alloc)->a);
  }

  vector<struct assign_in*>::iterator it_assign;
  for (it_assign = assign_ins.begin(); it_assign != assign_ins.end(); it_assign++) {
    //s.add(trace::allocated_expr(it_assign->a) == it_assign->value);
  }

  vector<struct assert_in*>::iterator it_assert;
  for (it_assert = assert_ins.begin(); it_assert != assert_ins.end(); it_assert++) {
    //s.add(trace::allocated_expr(it_assert->a) it_assert->op it_assert->d);
  }

  std::cout << s << std::endl;
  std::cout << s.check() << std::endl;

  if (s.check() == "unsat")
    return -1;
  else
    return 0;*/
}

