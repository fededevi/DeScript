#include "source/ast/expression.h"

#include <iostream>
#include <assert.h>

void alpiScriptArithmeticTest01(){
    int i = (1-5-7) % 34+ (1 * 45)+ 3- 3* (8*45)+(56/7) + 43 % 99;
    int j = Expression::evaluate("(1-5-7) % 34+ (1 * 45)+ 3- 3* (8*45)+(56/7) + 43 % 99")->toInt()->value;
    assert(i == j);

    i = (1-5-7) % 34;
    j = Expression::evaluate("(1-5-7) % 34")->toInt()->value;
    assert(i == j);
}

void alpiScriptArithmeticTest02(){
    double x = (1-.5-7) * .34;
    double y = Expression::evaluate("(1-.5-7) * .34")->toFloat()->value;
    assert(x == y);

    x = (8*45) * (1-.5-7) * .34;
    y = Expression::evaluate("(8*45) *(1-.5-7) * .34")->toFloat()->value;
    assert(x == y);
}


int main(int , char** ) {
    std::cout << Expression::evaluate("3872 - 27  - 45 * (80 / 43) * 4*4")->toString() << std::endl;

    alpiScriptArithmeticTest01();
    alpiScriptArithmeticTest02();
}

