#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <z3++.h>

using namespace z3;
using namespace std;

struct allocate_in {
  int id;
  string var;
  int size;
  //int expr_id;
  //expr e;
};

struct assign_in {
  int id;
  string var;
  int value;
  //expr e;
};

struct assert_in {
  int id;
  string var;
  string op;
  int d;
  //expr e;
};

//int allocate(char *a, int b);
//int assign(char *a, int c);
//int assert(char *a, char *op, int d);

#endif
