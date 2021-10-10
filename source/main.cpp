#include "source/ast/expression.h"
#include "source/ast/basetypes.h"

#include <iostream>
#include <assert.h>

void alpiScriptArithmeticTest01(){
    assert(Expression::evaluate("(1-.5-7) * .34")->toFloat()->value == ((1-.5-7) * .34));
    assert(Expression::evaluate("(8*45) * (1-.5-7) * .34")->toFloat()->value == (8*45) * (1-.5-7) * .34);

    assert(Expression::evaluate("(1-5+7) + 34 + (1 * 45)+ 3- 3* (8*45)+(56/7) + 43 % 99")->toInt()->value == (1-5+7) + 34 + (1 * 45)+ 3- 3* (8*45)+(56/7) + 43 % 99);
    assert(Expression::evaluate("(1-5-7) % 34")->toInt()->value == (1-5-7) % 34);

    assert(Expression::evaluate("10 % (1)")->toInt()->value == (10 % 1));
    assert(Expression::evaluate("10 % 100")->toInt()->value == (10 % 100));
}

void alpiScriptArithmeticTest02(){
    assert(Expression::evaluate("10 - -6")->toInt()->value == (10 - -6));
    assert(Expression::evaluate("10 * -6")->toInt()->value == (10 * -6));
    assert(Expression::evaluate("-10 - -6")->toInt()->value == (-10 - -6));
    assert(Expression::evaluate("-10 * -6")->toInt()->value == (-10 * -6));
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

void alpiScriptBooleanTest02(){
    assert( Expression::evaluate("true || false")->toBool()->value == (true || false) );
    assert( Expression::evaluate("false || true")->toBool()->value == (false || true) );
    assert( Expression::evaluate("false || false")->toBool()->value == (false || false) );
    assert( Expression::evaluate("true || true")->toBool()->value == (true || true) );

    assert( Expression::evaluate("false && true")->toBool()->value == (false && true) );
    assert( Expression::evaluate("true && false")->toBool()->value == (true && false) );
    assert( Expression::evaluate("false && false")->toBool()->value == (false && false) );
    assert( Expression::evaluate("true && true")->toBool()->value == (true && true) );
}

int main(int , char** ) {

    TypeInt::instance()->load();
    TypeFloat::instance()->load();
    TypeBool::instance()->load();

    alpiScriptBooleanTest02();
    alpiScriptBooleanTest01();
    alpiScriptArithmeticTest01();
    alpiScriptArithmeticTest02();

    std::cout << "All tests succesfull." << std::endl;

    return 0;
}

