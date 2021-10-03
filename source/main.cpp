 #include "source/ast/expression.h"

#include <iostream>

int main(int , char** ) {

    //ExpressionUPtr e = ExpressionUPtr(Expression::parse("a + 324 +1 % 4 % a4sd1 * 7 / c"));

    ExpressionUPtr e = ExpressionUPtr(Expression::parse("1+2+32"));
    std::cout << e->toString() << std::endl;

    ExpressionUPtr e_evaluated = ExpressionUPtr(e->evaluate());
    std::cout << e_evaluated->toString() << std::endl;
}

