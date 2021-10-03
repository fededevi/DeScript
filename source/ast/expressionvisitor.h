#pragma once

class Expression;
class Add;
class Sub;
class Id;
class Int;
class Mul;
class Div;
class Mod;
class Int;

class ExpressionVisitor
{
public:
    virtual void *visit(const Expression * node, void *data) = 0;

    virtual void *visit(const Add * node, void *data) = 0;
    virtual void *visit(const Sub * node, void *data) = 0;

    virtual void *visit(const Mul * node, void *data) = 0;
    virtual void *visit(const Div * node, void *data) = 0;

    virtual void *visit(const Mod * node, void *data) = 0;

    virtual void *visit(const Int * node, void *data) = 0;
    virtual void *visit(const Id * node, void *data) = 0;
};
