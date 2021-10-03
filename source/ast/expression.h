#pragma once

#include <memory>
#include <string>
#include <vector>
#include "expressionvisitor.h"

#define ACCEPT_VISITOR public: \
    virtual void* accept(const ExpressionVisitor * v, void * d) const { return v->visit(this, d);}

class ExpressionVisitor;
class Expression {
public:
    virtual void* accept(const ExpressionVisitor * v, void * d) const = 0;
public:
    static Expression * parse(const std::string &);
    Expression * evaluate() const;
    std::string toString() const;
};

class MultiExpression : public Expression {
public: std::vector<std::unique_ptr<Expression>> operands;
};

class UnaryExpression : public Expression {
public: std::unique_ptr<Expression> operand;
};

class Add : public MultiExpression { ACCEPT_VISITOR; };
class Sub : public MultiExpression { ACCEPT_VISITOR; };
class Mul : public MultiExpression { ACCEPT_VISITOR; };
class Div : public MultiExpression { ACCEPT_VISITOR; };
class Mod : public MultiExpression { ACCEPT_VISITOR; };

class Int : public Expression {
    ACCEPT_VISITOR;
    int64_t value;
    Int(int64_t v) : value(v) {}
};

class Id  : public Expression {
    ACCEPT_VISITOR;
    std::string value;
    Id(const std::string & v) : value(v) {}
};

using ExpressionUPtr = std::unique_ptr<Expression>;

