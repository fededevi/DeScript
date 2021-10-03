#include "expressionevaluator.h"
#include "expression.h"
#include <stdexcept>

void *ExpressionEvaluator::visit(const Add *node, void *data) const
{
    ExpressionList evaluatedOperands;

    bool cantCompute = false;
    for (const auto & op : node->operands) {
        Expression * e = static_cast<Expression *> (op->accept(this, data));
        evaluatedOperands.push_back(ExpressionUPtr(e));
        if (!e->isNumber())
            cantCompute = true;
    }

    if (cantCompute) {
        Add * add = new Add;
        add->operands = std::move(evaluatedOperands);
        return add;
    }

    if (evaluatedOperands[0]->isFloat()) {
        double value = 0;
        for (const auto & op : evaluatedOperands)
            value += static_cast<Float * >(op.get())->doubleValue();
        return new Float(value);
    }

    if (evaluatedOperands[0]->isInt()) {
        int64_t value = 0;
        for (const auto & op : evaluatedOperands)
            value += static_cast<Int * >(op.get())->intValue();
        return new Int(value);
    }

    return nullptr;
}

void *ExpressionEvaluator::visit(const Sub *node, void *data) const
{
return new Int(0);
}

void *ExpressionEvaluator::visit(const Mul *node, void *data) const
{
    return new Int(0);

}

void *ExpressionEvaluator::visit(const Div *node, void *data) const
{
    return new Int(0);

}

void *ExpressionEvaluator::visit(const Mod *node, void *data) const
{
    return new Int(0);

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
