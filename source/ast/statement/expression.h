#pragma once

#include <memory>

class ExpressionVisitor;
class Expression
{
    virtual void* accept(ExpressionVisitor * visitor, void * data);
};

class BinaryExpression : public Expression
{
public:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
};

class UnaryExpression : public Expression
{
public:
    std::unique_ptr<Expression> operand;
};


class Add : public BinaryExpression {};
class Sub : public BinaryExpression {};
class Mul : public BinaryExpression {};
class Div : public BinaryExpression {};
class Mod : public BinaryExpression {};

