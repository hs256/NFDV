#include <iostream>

#ifndef SYMBOL_H
#define SYMBOL_H

using namespace std;

class Symbol {
  string name;
  string type;
  string subtype;
  string value;
  string granularity;
  Symbol *next;
public:
  Symbol(string n, string t, string st, string v, string g);
  string getName();
  string getType();
  string getSubtype();
  string getValue();
  string getGranularity();
  friend class SymbolTable;
};

#endif 
