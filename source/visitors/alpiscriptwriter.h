#pragma once

#include "source/javacc/generated/ParserVisitor.h"
#include "source/javacc/generated/Parser.h"

namespace AlpiScript {

class AlpiScriptVisitor: public ParserVisitor {

public:
    virtual void * visit(const SimpleNode *node, void *data) override;
    virtual void * visit(const ASTProgram *node, void *data) override;
    virtual void * visit(const ASTStatement *node, void *data) override;

};

}
