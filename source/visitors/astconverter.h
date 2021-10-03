#pragma once

#include "source/javacc/generated/ParserVisitor.h"

class Expression;
class MultiExpression;
namespace AlpiScript {

class AstConverter: public ParserVisitor {

public:
    Expression * parse(const std::string & input);

    virtual void *visit(const SimpleNode *node, void *data) override;
    virtual void *visit(const ASTExpression *node, void *data) override;
    virtual void *visit(const ASTAdd *node, void *data) override;
    virtual void *visit(const ASTMult *node, void *data) override;
    virtual void *visit(const ASTIdentifier *node, void *data) override;
    virtual void *visit(const ASTInteger *node, void *data) override;
    virtual void *visit(const ASTSub *node, void *data) override;
    virtual void *visit(const ASTModule *node, void *data) override;
    virtual void *visit(const ASTDivision *node, void *data) override;

private:
    void fillOperands(MultiExpression * e, const AlpiScript::SimpleNode * node);


};

}
