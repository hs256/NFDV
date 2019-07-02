#include <iostream>
#include <vector>

#include "symbol.h"

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

using namespace std;

const int MAX = 100;

class SymbolTable {
  Symbol *head[MAX];

public:
  SymbolTable();
  int hashf(string name);
  bool add(string name, string type, string subtype, string value, vector<string> granularity);
  void modify(string name, string new_value);
  Symbol* find(string name);
  string getTypebyName(string name);
  string getSubtypebyName(string name);
  string getValuebyName(string name);
  vector<string> getGranularitybyName(string name);
  void printST();
};

#endif
