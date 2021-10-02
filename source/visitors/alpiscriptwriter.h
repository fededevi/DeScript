#pragma once

#include "source/javacc/generated/ParserVisitor.h"
#include "source/javacc/generated/Parser.h"

namespace AlpiScript {

class AlpiScriptVisitor: public ParserVisitor {

public:
    void* visit(const SimpleNode *node, void * data);
};

}
