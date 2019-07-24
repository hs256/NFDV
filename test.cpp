#include <z3++.h>

using namespace z3;
using namespace std;

int main() {
    std::cout << "eval example 1\n";
    context c;
    //Z3_ast ax;
    /*expr x;
    Z3_symbol s = Z3_mk_string_symbol(c, "x");
    Z3_sort int_sort = Z3_mk_int_sort(c);
    x = Z3_mk_const(c, s int_sort);
    expr y = c.int_const("y");
    solver s(c);

    s.add(x < y);
    s.add(x > 2);*/
    
    expr x = c.int_const("x");
    solver s(c);
    s.add(x == 11);
    s.add(x != 11);
    std::cout << s.check() << "\n";
 
    /*model m = s.get_model();
    std::cout << "Model:\n" << m << "\n";
    std::cout << "x" << m.eval(x) << "\n";*/
    return 0;
}
