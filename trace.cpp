#include <vector>
#include <z3++.h>

#include "trace.h"
#include "instructions.h"

using namespace std;
using namespace z3;

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
      if ((*it2)->decl) {
	cout << "Allocate(" << (*it2)->a << ")" << endl;
      //} else if ((*it2)->op == "==") {
	//cout << "Assign(" << (*it2)->a << ", " << (*it2)->value << ")" << endl;
      } else {
	cout << "Assert(" << (*it2)->a << " " << (*it2)->op << " " << (*it2)->value << ")" << endl;
      }
    }
  }
}
    


struct tracenode* trace::add_decl_node(string s) {
  struct tracenode *temp = new tracenode;
  temp->a = s;
  temp->decl = true;
  temp->left = temp->right = NULL;
  vector<struct tracenode*> leaves;
  leaves = leaf_nodes(root, leaves);
  if (leaves.size() == 0) {
    //cout << "no leaf nodes in add decl node " << endl;
    root = temp;
    root->left = NULL;
    root->right = NULL;
  } else {
    //cout << "leaf nodes in add decl node " << leaves.size() << endl;
    vector<struct tracenode*>::iterator it;
    for (it = leaves.begin(); it != leaves.end(); it++) {
      (*it)->left = temp;
    }
  }
  return temp;
}

struct tracenode* trace::add_assert_node(string s1, string op, int value) {
  //cout << "in assert node" << endl;
  struct tracenode *temp = new tracenode;
  temp->a = s1;
  temp->decl = false;
  temp->op = op;
  temp->value = value;
  temp->left = temp->right = NULL;
  vector<struct tracenode*> leaves;
  leaves = trace::leaf_nodes(root, leaves);
  vector<struct tracenode*>::iterator it;
  for (it = leaves.begin(); it != leaves.end(); it++) {
    (*it)->left = temp;
  }
  return temp;
}

void trace::add_ite_node(struct tracenode *t1, struct tracenode *t2, struct tracenode *t3) {
  vector<struct tracenode*> leaves;
  leaves = trace::leaf_nodes(root, leaves);
  //cout << "leaf nodes in ite " << leaves.size() << endl;
  vector<struct tracenode*>::iterator it;
  for (it = leaves.begin(); it != leaves.end(); it++) {
    (*it)->left = t1;
    (*it)->right = t2;
    (*it)->left->left = t3;
  }
}

struct tracenode* trace::new_assert_node(string a, string op, int v) {
  struct tracenode *temp = new tracenode;
  temp->a = a;
  temp->op = op;
  temp->value = v;
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
  add_assert_node(a, "==", value);
}

void trace::add_assert_in(string a, string op, int value) {
  add_assert_node(a, op, value);
}

trace::trace() {
  cout << "creating symbolic packet" << endl;
  trace::add_allocate_in("L3+0", 4);
  trace::add_allocate_in("L3+72", 8);
  trace::add_allocate_in("L3+96", 32);
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
  trace::add_assign_in("L4+106", 0);
  trace::add_allocate_in("L4+107", 1);
  trace::add_assign_in("L4+107", 0);
  trace::add_allocate_in("L4+108", 1);
  trace::add_assign_in("L4+108", 0);
  trace::add_allocate_in("L4+109", 1);
  trace::add_assign_in("L4+109", 0);
  trace::add_allocate_in("L4+110", 1);
  trace::add_allocate_in("L4+111", 1);

}

int trace::execute() {
  vector<vector<struct tracenode* >> paths;
  vector<struct tracenode*> path;
  paths = trace::get_paths(root, paths, path);
  vector<vector<struct tracenode* >>::iterator it;
  int path_i = 1;
  for (it = paths.begin(); it != paths.end(); it++) {
    cout << "Trace " << path_i++ << " ";
    solver s(ctx);
    vector<expr> decl_exprs;
    vector<struct tracenode*> t_path = (*it);
    vector<struct tracenode*>::iterator it2;
    for (it2 = t_path.begin(); it2 != t_path.end(); it2++) {
      if((*it2)->decl) {
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
	    } else if ((*it2)->op == ">") {
	      expr eq2 = (*decl_it) > (*it2)->value;
	      s.add(eq2);
	    } else if ((*it2)->op == "<") {
	      expr eq2 = (*decl_it) < (*it2)->value;
	      s.add(eq2);
	    } else if ((*it2)->op == "<=") {
	      expr eq2 = (*decl_it) <= (*it2)->value;
	      s.add(eq2);
	    } else if ((*it2)->op == "==") {
	      expr eq2 = (*decl_it) == (*it2)->value;
	      s.add(eq2);
	    } else if ((*it2)->op == "!=") {
	      expr eq2 = (*decl_it) != (*it2)->value;
	      s.add(eq2);
	    }
	  }
	}
      }
    }
    cout << s.check() << endl;
  }
}

