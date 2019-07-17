#include <iostream>
#include <vector>
#include <map>
#include <z3++.h>

//#include "pkt.h"
#include "trace.h"
#include "instructions.h"

using namespace std;
using namespace z3;

map<string, string> negated_op {
  {"==", "!="},
  {"=", "!=" },
  {"<", ">="},
  {"<=", ">"},
  {">", "<="},
  {">=", "<"},
  {"!=", "=="}
};

vector<struct tracenode*> trace::leaf_nodes(struct tracenode *node, vector<struct tracenode*> leaves) {
  //cout << "in leaf nodes size of leaves " << leaves.size() << endl;
  if (node == NULL) {
    //cout << "empty root node " << endl;
    return leaves;
  }
  if (node->left == NULL && node->right == NULL) {
    //cout << "adding leaf node to list" << endl;
    leaves.push_back(node);
  }
  if (node->left != NULL) 
    leaves =  leaf_nodes(node->left, leaves);
  if (node->right != NULL) {
    leaves = leaf_nodes(node->right, leaves);
  }
  return leaves;
}

vector<vector<struct tracenode*>> trace::get_paths(struct tracenode *node, vector<vector<struct tracenode*>> paths, vector<struct tracenode *> path) {
  if (node == NULL) {
    return paths;
  }

  path.push_back(node);
  if (node->left == NULL && node->right == NULL) {
    //cout << "path length in get_path " << path.size() << endl;
    /*vector <struct tracenode *>::iterator it2;
    for (it2 = path.begin(); it2 != path.end(); it2++) {
      if ((*it2)->decl) {
	cout << "ID : " << (*it2)->id << " Allocate(" << (*it2)->a << ")" << endl;
      } else {
	cout << "ID : " << (*it2)->id << " Assert(" << (*it2)->a << " " << (*it2)->op << " " << (*it2)->value << ")" << endl;
      }
    }*/
    paths.push_back(path);
    path.clear();
  }
  if (node->left != NULL)
    paths = get_paths(node->left, paths, path);
  if (node->right != NULL)
    paths = get_paths(node->right, paths, path);
  //cout << "no of paths in  get_paths " << paths.size() << endl;
  return paths;
}

vector<vector <struct tracenode*>> trace::return_all_paths() {
  vector<vector <struct tracenode* >> paths;
  vector<struct tracenode *> path;
  paths = trace::get_paths(root, paths, path);
  return paths;
}

void trace::print_path(vector<struct tracenode *> path) {
  vector <struct tracenode *>::iterator it2;
  for (it2 = path.begin(); it2 != path.end(); it2++) {
    if ((*it2)->decl == 1) {
      cout << "Allocate(" << (*it2)->a << ")" << endl;
    } else if ((*it2)->decl == 3) {
      cout << "Assert(" << (*it2)->a << " " << (*it2)->op2 << " " << (*it2)->b << " " << (*it2)->op << " " << (*it2)->value << ")" << endl;
    } else if ((*it2)->op == "=") {
      cout << "Assign(" << (*it2)->a << " " << (*it2)->op << " " << (*it2)->value << ")" << endl;
    } else if ((*it2)->a == "DROP") {
      cout << "DROP pkt" << endl;
    } else if ((*it2)->a == "pass") {
      cout << "Pass pkt" << endl;
    } else {
      cout << "Assert(" << (*it2)->a << " " << (*it2)->op << " " << (*it2)->value << ")" << endl;
    }
  }
}

void trace::print_all_paths() {
  vector<vector <struct tracenode* >> paths;
  vector<struct tracenode *> path;
  paths = trace::get_paths(root, paths, path);
  vector<vector<struct tracenode* >> ::iterator it;
  int i = 1;
  for (it = paths.begin(); it != paths.end(); it++) {
    cout << "Trace " << i++ << " : " << endl;
    vector <struct tracenode *> path = (*it);
    //cout << "path len " << path.size() << endl;
    vector <struct tracenode *>::iterator it2;
    for (it2 = path.begin(); it2 != path.end(); it2++) {
      if ((*it2)->decl == 1) {
	cout << "Allocate(" << (*it2)->a << ")" << endl;
      } else if ((*it2)->op == "=") {
	cout << "Assign(" << (*it2)->a << " " << (*it2)->op << " " << (*it2)->value << ")" << endl;
      } else if ((*it2)->a == "DROP") {
	cout << "DROP pkt" << endl;
      } else if ((*it2)->a == "pass") {
	cout << "Pass pkt" << endl;
      } else {
	cout << "Assert(" << (*it2)->a << " " << (*it2)->op << " " << (*it2)->value << ")" << endl;
      }
    }
  }
}
    
void trace::del_node(struct tracenode *node) {
    //cout << "deleting node in start " << node->id << " " << node->a << " " << node->op << " " << node->value << endl;
  if (node == NULL) {
    return;
  }
  if (node->left != NULL) {
    del_node(node->left);
  } 
  if (node->right != NULL) {
    del_node(node->right);
  }
  if (node->left == NULL && node->right == NULL) {
    struct tracenode *parent = trace::parent_node(root, node);
    struct tracenode *temp;
    if(compare_nodes(parent->left, node)) {
      parent->left = NULL;
    }
    else if(compare_nodes(parent->right, node)) {
      parent->right = NULL;
    }
    //cout << "deleting node " << node->id << " " << node->a << " " << node->op << " " << node->value << endl;
    temp = node;
    delete temp;
    temp = parent;
    return;
  }
}

struct tracenode* trace::parent_node(struct tracenode *tree, struct tracenode *node) {
  struct tracenode *temp;
  if (tree == NULL)
    return NULL;
  if (compare_nodes(tree->left, node) || compare_nodes(tree->right, node)) {
    //cout << "parent node " << tree->right->a << " " << tree->right->op << " " << tree->right->value << endl;
    return tree;
  }
  if (tree->left != NULL) {
    temp =  parent_node(tree->left, node);
    if (temp != NULL)
      return temp;
  }
  if (tree->right != NULL) {
    temp =  parent_node(tree->right, node);
    if (temp != NULL)
      return temp;
  }
  return NULL;
}

bool trace::compare_nodes(struct tracenode *t1, struct tracenode *t2) {
  if (t1 != NULL && t2 != NULL) {
    if(t1->id == t2->id && t1->a == t2->a && t1->op == t2->op && t1->value == t2->value)
      return true;
    else
      return false;
  }
  return false;
}

struct tracenode* trace::new_ct_node(string a1, string op1, string a2, string op2, int val) {
  //cout << "new ct node " << a1 << " " << op1 << " " << a2 << endl;
  struct tracenode *temp = new tracenode;
  temp->id = assert_ins_count++;
  temp->a = a1;
  temp->op = op2;
  temp->decl = 3;
  temp->value = val;
  temp->b = a2;
  temp->op2 = op1;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

struct tracenode* trace::new_decl_node(string a) {
  struct tracenode *temp = new tracenode;
  temp->id = allocate_ins_count++;
  temp->a = a;
  temp->op = "";
  temp->decl = 1;
  temp->value = -1;
  temp->left = NULL;
  temp->right = NULL;
  temp->b = "";
  temp->op2 = "";
  return temp;
}
void trace::add_decl_node(string s) {
  vector<struct tracenode*> leaves;
  leaves = leaf_nodes(root, leaves);
  if (leaves.size() == 0) {
    //cout << "no leaf nodes in add decl node " << endl;
    //temp->id = allocate_ins_count++;
    root = new_decl_node(s);
  } else {
    //cout << "leaf nodes in add decl node " << leaves.size() << endl;
    vector<struct tracenode*>::iterator it;
    for (it = leaves.begin(); it != leaves.end(); it++) {
      //temp->id = allocate_ins_count++;
      if ((*it)->a != "DROP" && (*it)->a != "pass")
	(*it)->left = new_decl_node(s);
      //cout << "parent id " << (*it)->id << " " << "child id " << temp->id << endl;
    }
  }
  return;
}


void trace::add_assign_node(string s1, string op, int value) {
  vector<struct tracenode*> leaves;
  leaves = trace::leaf_nodes(root, leaves);
  vector<struct tracenode*>::iterator it;
  for (it = leaves.begin(); it != leaves.end(); it++) {
    if ((*it)->a != "DROP" && (*it)->a != "pass")
      (*it)->left = new_assign_node(s1, op, value);
  }
  return;
}

void trace::add_assert_node(string s1, string op, int value) {
  vector<struct tracenode*> leaves;
  leaves = trace::leaf_nodes(root, leaves);
  vector<struct tracenode*>::iterator it;
  for (it = leaves.begin(); it != leaves.end(); it++) {
    //temp->id = assert_ins_count++;
    if ((*it)->a != "DROP" && (*it)->a != "pass")
      (*it)->left = new_assert_node(s1, op, value);
    //cout << "parent id " << (*it)->id << " " << "child id " << temp->id << endl;
  }
  return;
}

void trace::add_ite_node(struct tracenode *t1, struct tracenode *t2, struct tracenode *t3) {
  vector<struct tracenode*> leaves;
  leaves = trace::leaf_nodes(root, leaves);
  //cout << "leaf nodes in ite " << leaves.size() << endl;
  vector<struct tracenode*>::iterator it;
  for (it = leaves.begin(); it != leaves.end(); it++) {
    if ((*it)->a != "DROP" && (*it)->a != "pass") {
      (*it)->left = new_assert_node(t1->a, t1->op, t1->value);
      (*it)->right = new_assert_node(t2->a, t2->op, t2->value);
      if (t3 != NULL)
	(*it)->left->left = new_assert_node(t3->a, t3->op, t3->value);
    }
  }
}

struct tracenode* trace::add_ltree_nodes(struct tracenode *r, vector<struct tracenode *> tmp) {
  //cout << "action size in ltree nodes " << tmp.size() << endl;
  vector<struct tracenode *>::iterator it;
  for (it = tmp.begin(); it != tmp.end(); it++) {
    //cout << (*it)->a << " " << (*it)->op << (*it)->value << " in add ltree nodes " << endl;
    r->left = new_assert_node((*it)->a, (*it)->op, (*it)->value);
    r = r->left;
  }
  return r;
}

void trace::add_lrtree_nodes(struct tracenode *r, vector<struct tracenode*> tmp, int index) {
  //cout << "in lrtree nodes with index "<< index  << endl;
  int n = tmp.size();
  if (tmp[index]->decl == 0) {
    r->left = new_assert_node(tmp[index]->a, tmp[index]->op, tmp[index]->value);
    r->right = new_assert_node(tmp[index]->a, negated_op[tmp[index]->op], tmp[index]->value);
  } else if (tmp[index]->decl == 3) {
    r->left = new_ct_node(tmp[index]->a, tmp[index]->op2, tmp[index]->b, tmp[index]->op, tmp[index]->value);
    r->right = new_ct_node(tmp[index]->a, tmp[index]->op2, tmp[index]->b, negated_op[tmp[index]->op], tmp[index]->value);
  }
  if (index < n-1) {
    add_lrtree_nodes(r->left, tmp, index + 1);
  }
  if (index < n-1)
     add_lrtree_nodes(r->right, tmp, index + 1);
  return;
}

struct tracenode* trace::lmost_node(struct tracenode *n) {
  if (n == NULL)
    return NULL;
  else if (n->left != NULL)
    return lmost_node(n->left);
  else 
    return n;
}

void trace::add_mlrite_nodes(vector<struct tracenode *> action, vector<struct tracenode* > tmp) {
  //cout << "in mlrite nodes action size " << action.size() << endl;
  vector<struct tracenode*> leaves;
  leaves = trace::leaf_nodes(root, leaves);
  //cout << " no of leaves in mlrite " << leaves.size() << endl;
  vector<struct tracenode *>::iterator it;
  for (it = leaves.begin(); it != leaves.end(); it++) {
    if ((*it)->a != "DROP" && (*it)->a != "pass") {
      add_lrtree_nodes((*it), tmp, 0);
      struct tracenode *ll = lmost_node((*it));
      if (action.size() > 0) {
	add_ltree_nodes(ll, action);
	//ll->left = new_assert_node(action[0]->a, action[0]->op, action[0]->value);
      }
    }
  }
}

void trace::add_mite_node(vector<struct tracenode *> tmp1, vector<struct tracenode *> tmp2, struct tracenode *action) {
  vector<struct tracenode*> leaves;
  leaves = trace::leaf_nodes(root, leaves);
  vector<struct tracenode *>::iterator it;
  for (it = leaves.begin(); it != leaves.end(); it++) {
    if ((*it)->a != "DROP" && (*it)->a != "pass") {
      (*it)->left = new_assert_node(tmp1[0]->a, tmp1[0]->op, tmp1[0]->value);
      (*it)->right = new_assert_node(tmp2[0]->a, tmp2[0]->op, tmp2[0]->value);
      tmp1.erase(tmp1.begin());
      tmp2.erase(tmp2.begin());
      struct tracenode *al = add_ltree_nodes((*it)->left, tmp1);
      struct tracenode *ar = add_ltree_nodes((*it)->right, tmp2);
      if (action != NULL) {
	al->left = new_assert_node(action->a, action->op, action->value);
      }
    }
  }
}
  
struct tracenode* trace::new_assign_node(string a, string op, int v) {
  struct tracenode *temp = new tracenode;
  temp->id = assert_ins_count++;
  temp->a = a;
  temp->op = op;
  temp->decl = 2;
  temp->value = v;
  temp->b = "";
  temp->op2 = "";
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

struct tracenode* trace::new_assert_node(string a, string op, int v) {
  struct tracenode *temp = new tracenode;
  temp->id = assert_ins_count++;
  temp->a = a;
  temp->op = op;
  temp->decl = 0;
  temp->value = v;
  temp->b = "";
  temp->op2 = "";
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

void trace::add_allocate_in(string a, int size) {
  trace::add_decl_node(a);
  //cout << "ID: " << t->id << ", allocate(" << a << ", " << size << ")" << endl;
}

/*bool trace::is_allocated(string a) {
  vector<struct allocate_in*>::iterator it;
  for (it = trace::allocate_ins.begin(); it != trace::allocate_ins.end(); it++) {
    if ((*it)->var == a)
      return true;
  }

  return false;
}

struct allocate_in* trace::allocated_sym(string a) {
  vector<struct allocate_in*>::iterator it;
  for (it = trace::allocate_ins.begin(); it != trace::allocate_ins.end(); it++) {
    if ((*it)->var == a)
      return (*it);
  }

  return NULL;
}*/


void trace::add_assign_in(string a, int value) {
  
  //cout << "ID: " << t->id << ", assign(" << a << ", " << value << ")" << endl;
  add_assign_node(a, "==", value);
}

void trace::add_assert_in(string a, string op, int value) {
  add_assert_node(a, op, value);
}

trace::trace() {
  allocate_ins_count = 0;
  assert_ins_count = 0;
  root = NULL;
  cout << "creating symbolic packet" << endl;
  trace::add_allocate_in("L3+0", 4);
  trace::add_allocate_in("L3+72", 8);
  /*trace::add_allocate_in("L3+96", 32);
  trace::add_assert_in("L3+96", ">=", 0);
  trace::add_assert_in("L3+96", "<=", 429496);
  trace::add_allocate_in("L3+128", 32);
  trace::add_assert_in("L3+128", ">=", 0);
  trace::add_assert_in("L3+128", "<=", 4294967296);
  trace::add_allocate_in("L3+64", 8);
  trace::add_assign_in("L3+64", 255);
  trace::add_allocate_in("L3+16", 16);
  trace::add_allocate_in("L3+4", 4);
  trace::add_allocate_in("L3+80", 16);
  trace::add_allocate_in("L3+32", 16);
  trace::add_allocate_in("L4+0", 16);
  trace::add_assert_in("L4+0", ">=", 0);
  trace::add_assert_in("L4+0", "<=", 65536);
  trace::add_allocate_in("L4+16", 16);
  trace::add_assert_in("L4+16", ">=", 0);
  trace::add_assert_in("L4+16", "<=", 65536);
  trace::add_allocate_in("L4+32", 32);
  trace::add_allocate_in("L4+64", 32);
  trace::add_allocate_in("L4+96", 4);
  trace::add_assign_in("L4+96", 160);
  trace::add_allocate_in("L4+100", 3);
  trace::add_allocate_in("L4+103", 1);
  trace::add_assign_in("L4+103", 0);
  trace::add_allocate_in("L4+104", 1);
  trace::add_assign_in("L4+104", 0);
  trace::add_allocate_in("L4+105", 1);
  trace::add_assign_in("L4+105", 0);
  trace::add_allocate_in("L4+106", 1);
  trace::add_assign_in("L4+106", 0);*/
  //trace::add_allocate_in("L4+107", 1);
  //trace::add_allocate_in("L4+108", 1);
  //trace::add_allocate_in("L4+109", 1);
  trace::add_allocate_in("L4+110", 1);
  trace::add_allocate_in("Tsval", 1);
  //trace::add_allocate_in("L4+111", 1);

}

int trace::execute() {
PATH:
  vector<vector<struct tracenode* >> paths;
  vector<struct tracenode*> path;
  paths = trace::get_paths(root, paths, path);
  vector<vector<struct tracenode* >>::iterator it;
  int path_i = 1;
  for (it = paths.begin(); it != paths.end(); it++) {
    //cout << "Trace " << path_i++ << " ";
    solver s(ctx);
    vector<expr> decl_exprs;
    vector<struct tracenode*> t_path = (*it);
    vector<struct tracenode*>::iterator it2;
    for (it2 = t_path.begin(); it2 != t_path.end(); it2++) {
      if ((*it2) == NULL) {
	//cout << "null node in path " << endl;
	goto PATH;
      }
      if((*it2)->decl == 1) {
	string unique_name = (*it2)->a;
	const char *name = unique_name.c_str();
	Z3_sort int_sort = Z3_mk_int_sort(ctx);
	Z3_symbol s = Z3_mk_string_symbol(ctx, const_cast<char *>(name));
	Z3_ast x = Z3_mk_const(ctx, s, int_sort);
	expr eq(ctx, x);
	decl_exprs.push_back(eq);
      } else {
	vector<expr>::iterator decl_it;
	for (decl_it = decl_exprs.begin(); decl_it != decl_exprs.end(); decl_it++) {
	  if ((*decl_it).decl().name().str() == (*it2)->a) {
	    if ((*it2)->op == ">=") {
	      expr eq2 = (*decl_it) >=  (*it2)->value;
	      s.add(eq2);
	      if (s.check() == unsat) {
		cout << "unsat" << endl;
		del_node((*it2));
		goto PATH;
	      }
	    } else if ((*it2)->op == ">") {
	      expr eq2 = (*decl_it) > (*it2)->value;
	      s.add(eq2);
	      if (s.check() == unsat) {
		del_node((*it2));
		goto PATH;
	      }
	    } else if ((*it2)->op == "<") {
	      expr eq2 = (*decl_it) < (*it2)->value;
	      s.add(eq2);
	      if (s.check() == unsat) {
		del_node((*it2));
		goto PATH;
	      }
	    } else if ((*it2)->op == "<=") {
	      expr eq2 = (*decl_it) <= (*it2)->value;
	      s.add(eq2);
	      if (s.check() == unsat) {
		del_node((*it2));
		goto PATH;
	      }
	    } else if ((*it2)->op == "==") {
	      expr eq2 = (*decl_it) == (*it2)->value;
	      s.add(eq2);
	      if (s.check() == unsat) {
		del_node((*it2));
		//cout << "deleted node unsat ==" << endl;
		goto PATH;
	      }
	    } else if ((*it2)->op == "!=") {
	      expr eq2 = (*decl_it) != (*it2)->value;
	      s.add(eq2);
	      if (s.check() == unsat) {
		del_node((*it2));
		//cout << "deleted node unsat !=" << endl;
		goto PATH;
	      }
	    }
	  }
	}
      }
    }
    //cout << s.check() << endl;
  }
}

trace::~trace() {
  destroy_recursive(root);
}

void trace::destroy_recursive(struct tracenode *node) {
  if (node) {
    destroy_recursive(node->left);
    destroy_recursive(node->right);
    delete node;
  }
}
