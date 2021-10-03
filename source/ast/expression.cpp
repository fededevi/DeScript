#include "expression.h"

#include "source/visitors/astconverter.h"
#include "source/ast/expressionwriter.h"
#include "source/ast/expressionevaluator.h"

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
    return ExpressionUPtr(parse(s))->evaluate();
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
