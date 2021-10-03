#include "expressionevaluator.h"
#include "expression.h"
#include <stdexcept>

void *ExpressionEvaluator::visit(const Add *node, void *data) const
{
    ExpressionList evaluatedOperands;

    bool cantCompute = false;
    bool computeFP = false;
    for (const auto & op : node->operands) {
        Expression * e = static_cast<Expression *> (op->accept(this, data));
        evaluatedOperands.push_back(ExpressionUPtr(e));
        if (!e->isNumber())
            cantCompute = true;
        if (e->isFloat())
            computeFP = true;
    }

    if (cantCompute) {
        Add * add = new Add;
        add->operands = std::move(evaluatedOperands);
        return add;
    }

    if (computeFP) {
        double value = 0;
        for (const auto & op : evaluatedOperands)
            value += static_cast<Float * >(op.get())->doubleValue();
        return new Float(value);
    }

    //MUST BE INT
    int64_t value = 0;
    for (const auto & op : evaluatedOperands)
        value += static_cast<Int * >(op.get())->intValue();
    return new Int(value);
}

void *ExpressionEvaluator::visit(const Sub *node, void *data) const
{
    ExpressionList evaluatedOperands;

    bool cantCompute = false;
    bool computeFP = false;
    for (const auto & op : node->operands) {
        Expression * e = static_cast<Expression *> (op->accept(this, data));
        evaluatedOperands.push_back(ExpressionUPtr(e));
        if (!e->isNumber())
            cantCompute = true;
        if (e->isFloat())
            computeFP = true;
    }


    if (cantCompute) {
        Sub * add = new Sub;
        add->operands = std::move(evaluatedOperands);
        return add;
    }

    if (computeFP) {
        double value = static_cast<Float * >(evaluatedOperands[0].get())->doubleValue();
        bool first = true;
        for (const auto & op : evaluatedOperands) {
            if (first) { first = false; continue; }
            value -= static_cast<Float * >(op.get())->doubleValue();
        }
        return new Float(value);
    }

    //MUST BE INT
    int64_t value = static_cast<Int * >(evaluatedOperands[0].get())->intValue();
    bool first = true;
    for (const auto & op : evaluatedOperands) {
        if (first) { first = false;continue; }
        value -= static_cast<Int * >(op.get())->intValue();
    }
    return new Int(value);
}

void *ExpressionEvaluator::visit(const Mul *node, void *data) const
{
    ExpressionList evaluatedOperands;

    bool cantCompute = false;
    bool computeFP = false;
    for (const auto & op : node->operands) {
        Expression * e = static_cast<Expression *> (op->accept(this, data));
        evaluatedOperands.push_back(ExpressionUPtr(e));
        if (!e->isNumber())
            cantCompute = true;
        if (e->isFloat())
            computeFP = true;
    }


    if (cantCompute) {
        Sub * add = new Sub;
        add->operands = std::move(evaluatedOperands);
        return add;
    }

    if (computeFP) {
        double value = static_cast<Float * >(evaluatedOperands[0].get())->doubleValue();
        bool first = true;
        for (const auto & op : evaluatedOperands) {
            if (first) { first = false; continue; }
            value *= static_cast<Float * >(op.get())->doubleValue();
        }
        return new Float(value);
    }

    //MUST BE INT
    int64_t value = static_cast<Int * >(evaluatedOperands[0].get())->intValue();
    bool first = true;
    for (const auto & op : evaluatedOperands) {
        if (first) { first = false;continue; }
        value *= static_cast<Int * >(op.get())->intValue();
    }
    return new Int(value);
}

void *ExpressionEvaluator::visit(const Div *node, void *data) const
{
    ExpressionList evaluatedOperands;

    bool cantCompute = false;
    bool computeFP = false;
    for (const auto & op : node->operands) {
        Expression * e = static_cast<Expression *> (op->accept(this, data));
        evaluatedOperands.push_back(ExpressionUPtr(e));
        if (!e->isNumber())
            cantCompute = true;
        if (e->isFloat())
            computeFP = true;
    }


    if (cantCompute) {
        Sub * add = new Sub;
        add->operands = std::move(evaluatedOperands);
        return add;
    }

    if (computeFP) {
        double value = static_cast<Float * >(evaluatedOperands[0].get())->doubleValue();
        bool first = true;
        for (const auto & op : evaluatedOperands) {
            if (first) { first = false; continue; }
            value /= static_cast<Float * >(op.get())->doubleValue();
        }
        return new Float(value);
    }

    //MUST BE INT
    int64_t value = static_cast<Int * >(evaluatedOperands[0].get())->intValue();
    bool first = true;
    for (const auto & op : evaluatedOperands) {
        if (first) { first = false;continue; }
        value /= static_cast<Int * >(op.get())->intValue();
    }
    return new Int(value);
}

void *ExpressionEvaluator::visit(const Mod *node, void *data) const
{
    ExpressionList evaluatedOperands;

    bool cantCompute = false;
    bool computeFP = false;
    for (const auto & op : node->operands) {
        Expression * e = static_cast<Expression *> (op->accept(this, data));
        evaluatedOperands.push_back(ExpressionUPtr(e));
        if (!e->isNumber())
            cantCompute = true;
        if (e->isFloat())
            computeFP = true;
    }


    if (cantCompute) {
        Sub * add = new Sub;
        add->operands = std::move(evaluatedOperands);
        return add;
    }

    if (computeFP) {
        int64_t value = static_cast<Float * >(evaluatedOperands[0].get())->intValue();
        bool first = true;
        for (const auto & op : evaluatedOperands) {
            if (first) { first = false; continue; }
            value = value % static_cast<Float * >(op.get())->intValue();
        }
        return new Int(value);
    }

    //MUST BE INT
    int64_t value = static_cast<Int * >(evaluatedOperands[0].get())->intValue();
    bool first = true;
    for (const auto & op : evaluatedOperands) {
        if (first) { first = false;continue; }
        value %= static_cast<Int * >(op.get())->intValue();
    }
    return new Int(value);

}

void *ExpressionEvaluator::visit(const Int *node, void *data) const
{
    return new Int(node->value);
}

void *ExpressionEvaluator::visit(const Id *node, void *data) const
{
    return new Id(node->value);
}

void *ExpressionEvaluator::visit(const Float *node, void *data) const
{
    return new Float(node->value);
}
