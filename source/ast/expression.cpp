#include "expression.h"
#include <iostream>

#include "source/visitors/astconverter.h"
#include "source/ast/expressionwriter.h"
#include "source/ast/expressionevaluator.h"

#include "datatype.h"
#include "basetypes.h"

using namespace AlpiScript;

Expression *Expression::parse(const std::string & input)
{
    AstConverter astconv;
    return astconv.parse(input + "\n");
}

Expression *Expression::evaluate() const
{
    static ExpressionEvaluator evaluator;
    return static_cast<Expression *>(accept(&evaluator, nullptr));
}

Expression *Expression::evaluate(const std::string & s)
{
    std::cout << s << " -> " << std::flush;
    ExpressionUPtr toEvaluate (parse(s));
    std::cout << toEvaluate->toString() << " -> " << std::endl;
    Expression * evaluated = toEvaluate->evaluate();
    std::cout << evaluated->toString() << std::endl;
    return evaluated;
}

std::string Expression::toString() const
{
    static ExpressionWriter ew;
    std::string out;
    accept(&ew, &out);
    return out;
}

bool Expression::isNumber() {
    return dynamic_cast<Number *>(this);
}

Id * Expression::toId() {
    return dynamic_cast<Id *>(this);
}

Int * Expression::toInt() {
    return dynamic_cast<Int *>(this);
}

Float * Expression::toFloat() {
    return dynamic_cast<Float *>(this);
}

Boolean * Expression::toBool() {
    return dynamic_cast<Boolean *>(this);
}

Int::Int(int64_t v) : value(v) {
    type = TypeInt::instance();
}

Float::Float(double v) : value(v) {
    type = TypeFloat::instance();
}

Boolean::Boolean(bool v) : value(v) {
    type = TypeBool::instance();
}
