#include <iostream>

#include <symbol.h>

using namespace std;

Symbol::Symbol(string n, string t, string st, string v, vector<string> g) {
  name = n;
  type= t;
  subtype = st;
  value = v;
  granularity = g;
  next = NULL;
}

string Symbol::getName() {
  return name;
}

string Symbol::getValue() {
  return value;
}

string Symbol::getType() {
  return type;
}

string Symbol::getSubtype() {
  return subtype;
}

vector<string> Symbol::getGranularity() {
  return granularity;
}

