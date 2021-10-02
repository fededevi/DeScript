#include "alpiscriptwriter.h"


void *AlpiScript::AlpiScriptVisitor::visit( const AlpiScript::SimpleNode *node, void *data )
{
    return nullptr;
}

void *AlpiScript::AlpiScriptVisitor::visit( const AlpiScript::ASTProgram *node, void *data )
{
    return nullptr;
}

void *AlpiScript::AlpiScriptVisitor::visit( const AlpiScript::ASTStatement *node, void *data )
{
    return nullptr;
}
