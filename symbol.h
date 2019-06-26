#include <iostream>
#include <vector>

#ifndef SYMBOL_H
#define SYMBOL_H

using namespace std;

class Symbol {
  string name;
  string type;
  string subtype;
  string value;
  vector<string> granularity;
  Symbol *next;
public:
  Symbol(string n, string t, string st, string v, vector<string> g);
  string getName();
  string getType();
  string getSubtype();
  string getValue();
  vector<string> getGranularity();
  friend class SymbolTable;
};

#endif 
