 #include "source/ast/expression.h"

#include <iostream>

int main(int , char** ) {

    //ExpressionUPtr e = ExpressionUPtr(Expression::parse("a + 324 +1 % 4 % a4sd1 * 7 / c"));
    int i = (1-5-7) % 34+ (1 * 45)+ 3- 3* (8*45)+(56/7) + 43 % 99;
    ExpressionUPtr e = ExpressionUPtr(Expression::parse("(1-5-7) % 34+ (1 * 45)+ 3- 3* (8*45)+(56/7) + 43 % 99"));
    std::cout << e->toString() << std::endl;

    ExpressionUPtr e_evaluated = ExpressionUPtr(e->evaluate());
    std::cout << e_evaluated->toString() << std::endl;
}

