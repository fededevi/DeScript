#pragma once

#include "visitormacros.h"
#include "expressionvisitor.h"
#include "context.h"

#include <memory>
#include <string>
#include <vector>

class ExpressionVisitor;
class Id;
class Int;
class Float;
class Boolean;
class Context;
class DataType;
class Expression {
public:
    virtual void* accept(const ExpressionVisitor * v, void * d = nullptr) const = 0;
public:
    static Expression * parse(const std::string &);
    Expression * compile( Context * ctx = nullptr );
    Expression * evaluate( Context * ctx = nullptr ) const;
    static Expression * evaluate(const std::string &, Context * ctx  = nullptr);
    std::string toString() const;
    bool isNumber();
    Id * toId();
    Int * toInt();
    Float * toFloat();
    Boolean * toBool();

public:
    DataType * type;
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

class Add : public BinaryExpression { VISITOR_ACCEPT(ExpressionVisitor); };
class Sub : public BinaryExpression { VISITOR_ACCEPT(ExpressionVisitor); };
class Mul : public BinaryExpression { VISITOR_ACCEPT(ExpressionVisitor); };
class Div : public BinaryExpression { VISITOR_ACCEPT(ExpressionVisitor); };
class Mod : public BinaryExpression { VISITOR_ACCEPT(ExpressionVisitor); };
class Neg : public UnaryExpression  { VISITOR_ACCEPT(ExpressionVisitor); };

class BooleanExpression : public BinaryExpression {};

class LessThan     : public BooleanExpression { VISITOR_ACCEPT(ExpressionVisitor); };
class LessEqual    : public BooleanExpression { VISITOR_ACCEPT(ExpressionVisitor); };
class GreaterEqual : public BooleanExpression { VISITOR_ACCEPT(ExpressionVisitor); };
class GreaterThan  : public BooleanExpression { VISITOR_ACCEPT(ExpressionVisitor); };
class Equal        : public BooleanExpression { VISITOR_ACCEPT(ExpressionVisitor); };
class NotEqual     : public BooleanExpression { VISITOR_ACCEPT(ExpressionVisitor); };
class Not          : public UnaryExpression { VISITOR_ACCEPT(ExpressionVisitor); };

class And          : public BooleanExpression { VISITOR_ACCEPT(ExpressionVisitor); };
class Or           : public BooleanExpression { VISITOR_ACCEPT(ExpressionVisitor); };

class Literal : public Expression {};

class Number : public Literal{};

class Int : public Number {
    VISITOR_ACCEPT(ExpressionVisitor);
    int64_t value;
    Int(int64_t v);
};

class Float : public Number {
    VISITOR_ACCEPT(ExpressionVisitor);

    double value;
    Float(double v);
};

class Boolean : public Literal {
    VISITOR_ACCEPT(ExpressionVisitor);
    bool value;
    Boolean(bool v);
};

class Id : public Literal {
    VISITOR_ACCEPT(ExpressionVisitor);
    std::string value;
    Id(const std::string & v) : value(v) {}
};


using ExpressionUPtr = std::unique_ptr<Expression>;
using ExpressionList = std::vector<ExpressionUPtr>;

