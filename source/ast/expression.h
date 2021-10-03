#pragma once

#include <memory>
#include <string>
#include <vector>
#include "expressionvisitor.h"

#define ACCEPT_VISITOR public: \
    virtual void* accept(const ExpressionVisitor * v, void * d) const { return v->visit(this, d);}

class ExpressionVisitor;
class Number;
class Expression {
public:
    virtual void* accept(const ExpressionVisitor * v, void * d) const = 0;
public:
    //virtual ~Expression() = 0;
    static Expression * parse(const std::string &);
    Expression * evaluate() const;
    std::string toString() const;
    bool isNumber() { return (Number *) this;}
    bool isId() { return (Id *) this;}
    bool isInt() { return (Int *) this;}
    bool isFloat() { return (Float *) this;}
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

class Number : public Expression{
public:
    virtual int64_t intValue() = 0;
    virtual double doubleValue() = 0;
};

class Int : public Number {
    ACCEPT_VISITOR;
    int64_t value;
    Int(int64_t v) : value(v) {}
    virtual int64_t intValue() override {return value;}
    virtual double doubleValue() override {return value;};
};

class Float : public Number {
    ACCEPT_VISITOR;
    double value;
    Float(double v) : value(v) {}
    virtual int64_t intValue() override {return value;};
    virtual double doubleValue() override {return value;};
};

class Id  : public Expression {
    ACCEPT_VISITOR;
    std::string value;
    Id(const std::string & v) : value(v) {}
};

using ExpressionUPtr = std::unique_ptr<Expression>;
using ExpressionList = std::vector<ExpressionUPtr>;

