#include "expression.h"
#include <iostream>

#include "source/visitors/astconverter.h"
#include "source/ast/expressionwriter.h"
#include "source/ast/expressionevaluator.h"

#include "type.h"

using namespace AlpiScript;

Expression *Expression::parse(const std::string & input)
{
    AstConverter astconv;
    return astconv.parse(input + "\n");
}

Expression *Expression::evaluate() const
{
    ExpressionEvaluator evaluator;
    return static_cast<Expression *>(accept(&evaluator, nullptr));
}

Expression *Expression::evaluate(const std::string & s)
{
    ExpressionUPtr toEvaluate (parse(s));
    std::cout << toEvaluate->toString() << std::endl;
    Expression * evaluated = toEvaluate->evaluate();
    std::cout << evaluated->toString();
    return nullptr;
}

std::string Expression::toString() const
{
    ExpressionWriter ew;
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
    type = Type::baseTypeInt();
}

Float::Float(double v) : value(v) {
    type = Type::baseTypeInt();
}

Boolean::Boolean(bool v) : value(v) {
    type = Type::baseTypeInt();
}
