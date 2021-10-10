#pragma once

#include "expressionvisitor.h"
#include <string>

class MultiExpression;
class Expression;
class Add;
class Sub;
class Id;
class Int;
class Mul;
class Div;
class Mod;
class Int;

class ExpressionEvaluator : public ExpressionVisitor
{
    Expression * evaluate(const Expression *) const;

public:
    virtual void *visit(const Add * node, void *data) const;
    virtual void *visit(const Sub * node, void *data) const;
    virtual void *visit(const Mul * node, void *data) const;
    virtual void *visit(const Div * node, void *data) const;
    virtual void *visit(const Mod * node, void *data) const;
    virtual void *visit(const Neg *node, void *data) const override;

public:
    virtual void *visit(const Id * node, void *data) const;
    virtual void *visit(const Int * node, void *data) const;
    virtual void *visit(const Float *node, void *data) const;
    virtual void *visit(const Boolean *node, void *data) const;

public:
    virtual void *visit(const LessThan *node, void *data) const;
    virtual void *visit(const LessEqual *node, void *data) const;
    virtual void *visit(const GreaterEqual *node, void *data) const;
    virtual void *visit(const GreaterThan *node, void *data) const;
    virtual void *visit(const Equal *node, void *data) const;
    virtual void *visit(const NotEqual *node, void *data) const;
    virtual void *visit(const Not *node, void *data) const;

public:
    virtual void *visit(const And *node, void *data) const;
    virtual void *visit(const Or *node, void *data) const;

public:
    void *visit(const TypeId *node, void *data) const;
    void *visit(const Parameter *node, void *data) const;
    void *visit(const Method *node, void *data) const;

};
