#include "expression.h"

#include "source/visitors/astconverter.h"

using namespace AlpiScript;
Expression *Expression::parse(const std::string & input)
{
    AstConverter astconv;
    return astconv.parse(input + "\n");
}

Expression *Expression::evaluate() const
{
    return nullptr;
}
