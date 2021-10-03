#include "expressionwriter.h"

#include "expression.h"


void * ExpressionWriter::writeMultiOperandOperation(const MultiExpression * node, void * data, const std::string & op) const
{
    std::string * out = (std::string *)data;
    node->operands[0]->accept(this, data);
    bool skipfirst = true;
    for (const auto & exp : node->operands) {
        if (skipfirst) {
            skipfirst = false;
            continue;
        }
        out->append(op);
        exp->accept(this, data);
    }
    return data;
}

void *ExpressionWriter::visit(const Add *node, void *data) const
{
    return writeMultiOperandOperation(node, data, "+");
}

void *ExpressionWriter::visit(const Sub *node, void *data) const
{
    return writeMultiOperandOperation(node, data, "-");
}

void *ExpressionWriter::visit(const Mul *node, void *data) const
{
    return writeMultiOperandOperation(node, data, "*");
}

void *ExpressionWriter::visit(const Div *node, void *data) const
{
    return writeMultiOperandOperation(node, data, "/");
}

void *ExpressionWriter::visit(const Mod *node, void *data) const
{
    return writeMultiOperandOperation(node, data, "%");
}

void *ExpressionWriter::visit(const Int *node, void *data) const
{
    std::string * out = (std::string *)data;
    out->append(std::to_string(node->value));
    return out;
}

void *ExpressionWriter::visit(const Id *node, void *data) const
{
    std::string * out = (std::string *)data;
    out->append(node->value);
    return out;
}

