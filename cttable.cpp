#include "cttable.h"
#include <iostream>

using namespace std;

CTTable::CTTable() {
  for(int i = 0; i <MAX2; i++) {
    head[i] = NULL;
  }
}

int CTTable::hashf(string name) {
  int num = 0;
  for (int i = 0; i < name.length(); i++) {
    num = num + name[i];
  }

  return (num % 100);
}

bool CTTable::add(string name, string c1, string op1, string c2, string op2, string cval) {
  int index = hashf(name);
  Constraint *p = new Constraint(name, c1, op1, c2, op2, cval);

  if(head[index] == NULL) {
    head[index] = p;
    return true;
  } else {
    Constraint *start = head[index];
    while (start->next != NULL) {
      start = start->next;
    }
    start->next = p;

    return true;
  }
  return false;
}

Constraint* CTTable::find(string name) {
  int i = hashf(name);
  Constraint *start = head[i];

  if(start == NULL) {
    //cout << "symbol " << name << " not find " << endl;
    return NULL;
  }

  while(start != NULL) {
    if (start->getname() == name) {
      //cout << "symbol with " << name << " and value " << start->getValue() << " is found " << endl;
      return start;
    }

    start = start->next;
  }
  return NULL;
}

string CTTable::getc1byName(string name) {
  Constraint *s = find(name);
  return s->getc1();
}

string CTTable::getc2byName(string name) {
  Constraint *s = find(name);
  return s->getc2();
}

int CTTable::getcvalbyName(string name) {
  Constraint *s = find(name);
  string val = s->getcval();
  int c = stoi(val);
  return c;
}

string CTTable::getop1byName(string name) {
  Constraint *s = find(name);
  return s->getop1();
}

string CTTable::getop2byName(string name) {
  Constraint *s = find(name);
  return s->getop2();
}

void CTTable::printCT() {
  for(int i = 0; i < MAX2; i++) {
    Constraint *start = head[i];
    //if (start != NULL) {
    while (start != NULL) {
      cout << start->getname() << " = " << start->getc1() << " " << start->getop1() << " " <<  start->getc2() << " " << start->getop2() << " " << start->getcval() << endl;
      if (start->next != NULL)
	start = start->next;
      else
	break;
    }
      //cout << endl;
  }
}

