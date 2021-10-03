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
class Float;

class ExpressionVisitor
{
public:
    virtual void *visit(const Add * node, void *data) const = 0;
    virtual void *visit(const Sub * node, void *data) const = 0;
    virtual void *visit(const Mul * node, void *data) const = 0;
    virtual void *visit(const Div * node, void *data) const = 0;
    virtual void *visit(const Mod * node, void *data) const = 0;
    virtual void *visit(const Int * node, void *data) const = 0;
    virtual void *visit(const Id * node, void *data) const = 0;
    virtual void *visit(const Float * node, void *data) const = 0;
};
