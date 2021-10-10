#include "expressionwriter.h"

#include "expression.h"


void * ExpressionWriter::writeBinaryOperation(const BinaryExpression * node, void * data, const std::string & op) const
{
    std::string * out = (std::string *)data;
    out->append("(");
    node->left->accept(this, data);
    out->append(op);
    node->right->accept(this, data);
    out->append(")");
    return data;
}

void *ExpressionWriter::visit(const Add *node, void *data) const
{
    return writeBinaryOperation(node, data, "+");
}

void *ExpressionWriter::visit(const Sub *node, void *data) const
{
    return writeBinaryOperation(node, data, "-");
}

void *ExpressionWriter::visit(const Mul *node, void *data) const
{
    return writeBinaryOperation(node, data, "*");
}

void *ExpressionWriter::visit(const Div *node, void *data) const
{
    return writeBinaryOperation(node, data, "/");
}

void *ExpressionWriter::visit(const Mod *node, void *data) const
{
    return writeBinaryOperation(node, data, "%");
}

void *ExpressionWriter::visit(const Neg *node, void *data) const
{
    std::string * out = (std::string *)data;
    out->append("-");
    node->operand->accept(this, data);
    return out;
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

void *ExpressionWriter::visit(const Float *node, void *data) const
{
    std::string * out = (std::string *)data;
    out->append(std::to_string(node->value));
    return out;
}

void *ExpressionWriter::visit(const Boolean *node, void *data) const
{
    std::string * out = (std::string *)data;
    out->append(node->value ? "true" : "false");
    return out;
}

void *ExpressionWriter::visit(const LessThan *node, void *data) const
{
    return writeBinaryOperation(node, data, "<");
}

void *ExpressionWriter::visit(const LessEqual *node, void *data) const
{
    return writeBinaryOperation(node, data, "<=");
}

void *ExpressionWriter::visit(const GreaterEqual *node, void *data) const
{
    return writeBinaryOperation(node, data, ">=");
}

void *ExpressionWriter::visit(const GreaterThan *node, void *data) const
{
    return writeBinaryOperation(node, data, ">");
}

void *ExpressionWriter::visit(const Equal *node, void *data) const
{
    return writeBinaryOperation(node, data, "==");
}

void *ExpressionWriter::visit(const NotEqual *node, void *data) const
{
    return writeBinaryOperation(node, data, "!=");
}

void *ExpressionWriter::visit(const Not *node, void *data) const
{
    std::string * out = (std::string *)data;
    out->append("!");
    node->operand->accept(this, data);
    return out;
}

void *ExpressionWriter::visit(const And *node, void *data) const
{
    return writeBinaryOperation(node, data, " AND ");
}

void *ExpressionWriter::visit(const Or *node, void *data) const
{
    return writeBinaryOperation(node, data, " OR ");
}

void *ExpressionWriter::visit(const TypeId *node, void *data) const
{

}

void *ExpressionWriter::visit(const Parameter *node, void *data) const
{

}

void *ExpressionWriter::visit(const Method *node, void *data) const
{

}

