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
    static Expression * evaluate(const std::string &);
    std::string toString() const;
    bool isNumber();
    Id * toId();
    Int * toInt();
    Float * toFloat();
    Boolean * toBool();
};

class BinaryExpression : public Expression {
public:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;

};

class UnaryExpression : public Expression {
public:
    std::unique_ptr<Expression> operand;
};

class Add : public BinaryExpression { ACCEPT_VISITOR; };
class Sub : public BinaryExpression { ACCEPT_VISITOR; };
class Mul : public BinaryExpression { ACCEPT_VISITOR; };
class Div : public BinaryExpression { ACCEPT_VISITOR; };
class Mod : public BinaryExpression { ACCEPT_VISITOR; };

class BooleanExpression : public BinaryExpression {};

class LessThan     : public BooleanExpression { ACCEPT_VISITOR; };
class LessEqual    : public BooleanExpression { ACCEPT_VISITOR; };
class GreaterEqual : public BooleanExpression { ACCEPT_VISITOR; };
class GreaterThan  : public BooleanExpression { ACCEPT_VISITOR; };
class Equal        : public BooleanExpression { ACCEPT_VISITOR; };
class NotEqual     : public BooleanExpression { ACCEPT_VISITOR; };
class Not          : public BooleanExpression { ACCEPT_VISITOR; };

class Literal : public Expression {};

class Number : public Literal{
};

class Int : public Number {
    ACCEPT_VISITOR;
    int64_t value;
    Int(int64_t v) : value(v) {}
};

class Float : public Number {
    ACCEPT_VISITOR;
    double value;
    Float(double v) : value(v) {}
};

class Boolean : public Literal {
    ACCEPT_VISITOR;
    bool value;
    Boolean(bool v) : value(v) {}
};

class Id : public Literal {
    ACCEPT_VISITOR;
    std::string value;
    Id(const std::string & v) : value(v) {}
};

using ExpressionUPtr = std::unique_ptr<Expression>;
using ExpressionList = std::vector<ExpressionUPtr>;

