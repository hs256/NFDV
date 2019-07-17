#include <iostream>
#include <vector>

#include "constraint.h"

#ifndef CTTABLE_H
#define CTTABLE_H

using namespace std;

const int MAX2 = 100;

class CTTable {
  Constraint *head[MAX2];

public:
  CTTable();
  int hashf(string name);
  bool add(string name, string c1, string op1, string c2, string op2, string cval);
  Constraint *find(string name);
  string getc1byName(string name);
  string getc2byName(string name);
  string getop1byName(string name);
  string getop2byName(string name);
  int getcvalbyName(string name);
  void printCT();
};
  

#endif
