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


std::string Expression::toString() const
{
    ExpressionWriter ew;
    std::string out;
    accept(&ew, &out);
    return out;
}
