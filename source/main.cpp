 #include "source/ast/expression.h"

#include <iostream>

int main(int , char** ) {

    ExpressionUPtr e = ExpressionUPtr(Expression::parse("a + 324 + 1 * 7 / c"));
    std::string out = e->toString();
    std::cout << out << std::endl;
}

