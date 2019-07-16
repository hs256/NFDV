#include <iostream>

#include <constraint.h>

using namespace std;

Constraint::Constraint(string n, string c1, string op1, string c2, string op2, string c3) {
  name = n;
  c1 = c1;
  op1 = op1;
  c2 = c2;
  op2 = op2;
  cval = c3;
  next = NULL;
}

string Constraint::getname() {
  return name;
}

string Constraint::getc1() {
  return c1;
}

string Constraint::getc2() {
  return c2;
}

string Constraint::getcval() {
  return cval;
}

string Constraint::getop1() {
  return op1;
}

string Constraint::getop2() {
  return op2;
}

