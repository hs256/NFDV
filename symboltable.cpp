#include "symboltable.h"
#include <iostream>

using namespace std;

SymbolTable::SymbolTable() {
  for(int i = 0; i <MAX; i++) {
    head[i] = NULL;
  }
}

int SymbolTable::hashf(string name) {
  int num = 0;
  for (int i = 0; i < name.length(); i++) {
    num = num + name[i];
  }

  return (num % 100);
}

bool SymbolTable::add(string name, string type, string subtype, string value, vector<string> granularity) {
  int index = hashf(name);
  Symbol *p = new Symbol(name, type, subtype, value, granularity);

  if(head[index] == NULL) {
    head[index] = p;
    return true;
  } else {
    Symbol *start = head[index];
    while (start->next != NULL) {
      start = start->next;
    }
    start->next = p;

    return true;
  }
  return false;
}

Symbol* SymbolTable::find(string name) {
  int i = hashf(name);
  Symbol *start = head[i];

  if(start == NULL) {
    //cout << "symbol " << name << " not find " << endl;
    return NULL;
  }

  while(start != NULL) {
    if (start->getName() == name) {
      //cout << "symbol with " << name << " is found " << endl;
      return head[i];
    }

    start = start->next;
  }

  return NULL;
}

string SymbolTable::getTypebyName(string name) {
  Symbol *s = find(name);
  return s->getType();
}

string SymbolTable::getSubtypebyName(string name) {
  Symbol *s = find(name);
  return s->getSubtype();
}

string SymbolTable::getValuebyName(string name) {
  Symbol *s = find(name);
  if (s != NULL) {
    return s->getValue();
  } else {
    return "";
  }
}

vector<string> SymbolTable::getGranularitybyName(string name) {
  Symbol *s = find(name);
  return s->getGranularity();
}

void SymbolTable::printST() {
  for(int i = 0; i < MAX; i++) {
    if (head[i] != NULL) {
      cout << head[i]->getName() << " " << head[i]->getType() << " " << head[i]->getSubtype() << " " <<  head[i]->getValue() << " ";
      vector<string> gr = head[i]->getGranularity();
      vector<string>::iterator it;
      for (it = gr.begin(); it != gr.end(); it++) {
	cout << (*it) << " " ;
      }
      cout << endl;
    }
  }
}
