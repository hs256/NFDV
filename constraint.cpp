#include <iostream>

#include <constraint.h>

using namespace std;

Constraint::Constraint(string n, string c01, string op01, string c02, string op02, string c03) {
  name = n;
  c1 = c01;
  op1 = op01;
  c2 = c02;
  op2 = op02;
  cval = c03;
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

