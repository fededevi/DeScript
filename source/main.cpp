#include "source/ast/expression.h"
#include "source/ast/basetypes.h"

#include <iostream>
#include <assert.h>

void alpiScriptArithmeticTest01(){
    int i, j;

    i = (1-5+7) + 34 + (1 * 45)+ 3- 3* (8*45)+(56/7) + 43 % 99;
    j = Expression::evaluate("(1-5+7) + 34 + (1 * 45)+ 3- 3* (8*45)+(56/7) + 43 % 99")->toInt()->value;
    assert(i == j);

    i = (1-5-7) % 34;
    j = Expression::evaluate("(1-5-7) % 34")->toInt()->value;
    assert(i == j);
}

void alpiScriptArithmeticTest02(){
    double x,y;

    x = (1-.5-7) * .34;
    y = Expression::evaluate("(1-.5-7) * .34")->toFloat()->value;
    assert(x == y);

    x = (8*45) * (1-.5-7) * .34;
    y = Expression::evaluate("(8*45) * (1-.5-7) * .34")->toFloat()->value;
    assert(x == y);
}

void alpiScriptBooleanTest01(){
    assert( Expression::evaluate(" 1 < 1")->toBool()->value ==  (1  < 1) );
    assert( Expression::evaluate(" 1 < 1")->toBool()->value ==  (1  < 1) );
    assert( Expression::evaluate(".1 < 1")->toBool()->value ==  (.1 < 1) );
    assert( Expression::evaluate(".1 < 1")->toBool()->value ==  (.1 < 1) );
    assert( Expression::evaluate(".1 < .1")->toBool()->value == (.1 < .1) );
    assert( Expression::evaluate(".1 < .1")->toBool()->value == (.1 < .1) );
    assert( Expression::evaluate(" 1 < .1")->toBool()->value == (1  < .1) );
    assert( Expression::evaluate(" 1 < .1")->toBool()->value == (1  < .1) );
    assert( Expression::evaluate(" 1 < 2")->toBool()->value ==  (1  < 2) );
    assert( Expression::evaluate(" 2 < 1")->toBool()->value ==  (2  < 1) );
    assert( Expression::evaluate(".1 < 2")->toBool()->value ==  (.1 < 2) );
    assert( Expression::evaluate(".2 < 1")->toBool()->value ==  (.2 < 1) );
    assert( Expression::evaluate(".1 < .2")->toBool()->value == (.1 < .2) );
    assert( Expression::evaluate(".2 < .1")->toBool()->value == (.2 < .1) );
    assert( Expression::evaluate(" 1 < .2")->toBool()->value == (1  < .2) );
    assert( Expression::evaluate(" 2 < .1")->toBool()->value == (2  < .1) );

    assert( Expression::evaluate(" 1 <= 1")->toBool()->value ==  (1  <= 1) );
    assert( Expression::evaluate(" 1 <= 1")->toBool()->value ==  (1  <= 1) );
    assert( Expression::evaluate(".1 <= 1")->toBool()->value ==  (.1 <= 1) );
    assert( Expression::evaluate(".1 <= 1")->toBool()->value ==  (.1 <= 1) );
    assert( Expression::evaluate(".1 <= .1")->toBool()->value == (.1 <= .1) );
    assert( Expression::evaluate(".1 <= .1")->toBool()->value == (.1 <= .1) );
    assert( Expression::evaluate(" 1 <= .1")->toBool()->value == (1  <= .1) );
    assert( Expression::evaluate(" 1 <= .1")->toBool()->value == (1  <= .1) );
    assert( Expression::evaluate(" 1 <= 2")->toBool()->value ==  (1  <= 2) );
    assert( Expression::evaluate(" 2 <= 1")->toBool()->value ==  (2  <= 1) );
    assert( Expression::evaluate(".1 <= 2")->toBool()->value ==  (.1 <= 2) );
    assert( Expression::evaluate(".2 <= 1")->toBool()->value ==  (.2 <= 1) );
    assert( Expression::evaluate(".1 <= .2")->toBool()->value == (.1 <= .2) );
    assert( Expression::evaluate(".2 <= .1")->toBool()->value == (.2 <= .1) );
    assert( Expression::evaluate(" 1 <= .2")->toBool()->value == (1  <= .2) );
    assert( Expression::evaluate(" 2 <= .1")->toBool()->value == (2  <= .1) );

    assert( Expression::evaluate(" 1 >= 1")->toBool()->value ==  (1  >= 1) );
    assert( Expression::evaluate(" 1 >= 1")->toBool()->value ==  (1  >= 1) );
    assert( Expression::evaluate(".1 >= 1")->toBool()->value ==  (.1 >= 1) );
    assert( Expression::evaluate(".1 >= 1")->toBool()->value ==  (.1 >= 1) );
    assert( Expression::evaluate(".1 >= .1")->toBool()->value == (.1 >= .1) );
    assert( Expression::evaluate(".1 >= .1")->toBool()->value == (.1 >= .1) );
    assert( Expression::evaluate(" 1 >= .1")->toBool()->value == (1  >= .1) );
    assert( Expression::evaluate(" 1 >= .1")->toBool()->value == (1  >= .1) );
    assert( Expression::evaluate(" 1 >= 2")->toBool()->value ==  (1  >= 2) );
    assert( Expression::evaluate(" 2 >= 1")->toBool()->value ==  (2  >= 1) );
    assert( Expression::evaluate(".1 >= 2")->toBool()->value ==  (.1 >= 2) );
    assert( Expression::evaluate(".2 >= 1")->toBool()->value ==  (.2 >= 1) );
    assert( Expression::evaluate(".1 >= .2")->toBool()->value == (.1 >= .2) );
    assert( Expression::evaluate(".2 >= .1")->toBool()->value == (.2 >= .1) );
    assert( Expression::evaluate(" 1 >= .2")->toBool()->value == (1  >= .2) );
    assert( Expression::evaluate(" 2 >= .1")->toBool()->value == (2  >= .1) );

    assert( Expression::evaluate(" 1 > 1")->toBool()->value ==  (1  > 1) );
    assert( Expression::evaluate(" 1 > 1")->toBool()->value ==  (1  > 1) );
    assert( Expression::evaluate(".1 > 1")->toBool()->value ==  (.1 > 1) );
    assert( Expression::evaluate(".1 > 1")->toBool()->value ==  (.1 > 1) );
    assert( Expression::evaluate(".1 > .1")->toBool()->value == (.1 > .1) );
    assert( Expression::evaluate(".1 > .1")->toBool()->value == (.1 > .1) );
    assert( Expression::evaluate(" 1 > .1")->toBool()->value == (1  > .1) );
    assert( Expression::evaluate(" 1 > .1")->toBool()->value == (1  > .1) );
    assert( Expression::evaluate(" 1 > 2")->toBool()->value ==  (1  > 2) );
    assert( Expression::evaluate(" 2 > 1")->toBool()->value ==  (2  > 1) );
    assert( Expression::evaluate(".1 > 2")->toBool()->value ==  (.1 > 2) );
    assert( Expression::evaluate(".2 > 1")->toBool()->value ==  (.2 > 1) );
    assert( Expression::evaluate(".1 > .2")->toBool()->value == (.1 > .2) );
    assert( Expression::evaluate(".2 > .1")->toBool()->value == (.2 > .1) );
    assert( Expression::evaluate(" 1 > .2")->toBool()->value == (1  > .2) );
    assert( Expression::evaluate(" 2 > .1")->toBool()->value == (2  > .1) );

    assert( Expression::evaluate(" 1 == 1")->toBool()->value ==  (1  == 1) );
    assert( Expression::evaluate(" 1 == 1")->toBool()->value ==  (1  == 1) );
    assert( Expression::evaluate(".1 == 1")->toBool()->value ==  (.1 == 1) );
    assert( Expression::evaluate(".1 == 1")->toBool()->value ==  (.1 == 1) );
    assert( Expression::evaluate(".1 == .1")->toBool()->value == (.1 == .1) );
    assert( Expression::evaluate(".1 == .1")->toBool()->value == (.1 == .1) );
    assert( Expression::evaluate(" 1 == .1")->toBool()->value == (1  == .1) );
    assert( Expression::evaluate(" 1 == .1")->toBool()->value == (1  == .1) );
    assert( Expression::evaluate(" 1 == 2")->toBool()->value ==  (1  == 2) );
    assert( Expression::evaluate(" 2 == 1")->toBool()->value ==  (2  == 1) );
    assert( Expression::evaluate(".1 == 2")->toBool()->value ==  (.1 == 2) );
    assert( Expression::evaluate(".2 == 1")->toBool()->value ==  (.2 == 1) );
    assert( Expression::evaluate(".1 == .2")->toBool()->value == (.1 == .2) );
    assert( Expression::evaluate(".2 == .1")->toBool()->value == (.2 == .1) );
    assert( Expression::evaluate(" 1 == .2")->toBool()->value == (1  == .2) );
    assert( Expression::evaluate(" 2 == .1")->toBool()->value == (2  == .1) );

    assert( Expression::evaluate(" 1 != 1")->toBool()->value ==  (1  != 1) );
    assert( Expression::evaluate(" 1 != 1")->toBool()->value ==  (1  != 1) );
    assert( Expression::evaluate(".1 != 1")->toBool()->value ==  (.1 != 1) );
    assert( Expression::evaluate(".1 != 1")->toBool()->value ==  (.1 != 1) );
    assert( Expression::evaluate(".1 != .1")->toBool()->value == (.1 != .1) );
    assert( Expression::evaluate(".1 != .1")->toBool()->value == (.1 != .1) );
    assert( Expression::evaluate(" 1 != .1")->toBool()->value == (1  != .1) );
    assert( Expression::evaluate(" 1 != .1")->toBool()->value == (1  != .1) );
    assert( Expression::evaluate(" 1 != 2")->toBool()->value ==  (1  != 2) );
    assert( Expression::evaluate(" 2 != 1")->toBool()->value ==  (2  != 1) );
    assert( Expression::evaluate(".1 != 2")->toBool()->value ==  (.1 != 2) );
    assert( Expression::evaluate(".2 != 1")->toBool()->value ==  (.2 != 1) );
    assert( Expression::evaluate(".1 != .2")->toBool()->value == (.1 != .2) );
    assert( Expression::evaluate(".2 != .1")->toBool()->value == (.2 != .1) );
    assert( Expression::evaluate(" 1 != .2")->toBool()->value == (1  != .2) );
    assert( Expression::evaluate(" 2 != .1")->toBool()->value == (2  != .1) );

}

int main(int , char** ) {

    TypeInt::instance()->load();
    TypeFloat::instance()->load();
    TypeBool::instance()->load();

    //std::cout <<  Expression::evaluate("1 + 1")->toString() << std::endl;
    //std::cout <<  Expression::evaluate(".1 + 2")->toString() << std::endl;
    alpiScriptArithmeticTest01();
    alpiScriptArithmeticTest02();
    alpiScriptBooleanTest01();

    std::cout << "All tests succesfull." << std::endl;

    return 0;
}

