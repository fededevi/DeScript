#pragma once

#include "source/javacc/generated/ParserVisitor.h"
#include "source/javacc/generated/Parser.h"

namespace AlpiScript {

class AlpiScriptVisitor: public ParserVisitor {

public:
    virtual void * visit(const SimpleNode *node, void *data) override;


    // ParserVisitor interface
public:
    virtual void *visit(const ASTExpression *node, void *data) override;
    virtual void *visit(const ASTAdd *node, void *data) override;
    virtual void *visit(const ASTMult *node, void *data) override;
    virtual void *visit(const ASTIdentifier *node, void *data) override;
    virtual void *visit(const ASTInteger *node, void *data) override;
    virtual void *visit(const ASTSub *node, void *data) override;
    virtual void *visit(const ASTModule *node, void *data) override;
    virtual void *visit(const ASTDivision *node, void *data) override;
};

}
