#include "alpiscriptwriter.h"


void *AlpiScript::AlpiScriptVisitor::visit( const AlpiScript::SimpleNode *node, void *data )
{
    return nullptr;
}

void *AlpiScript::AlpiScriptVisitor::visit(const AlpiScript::ASTExpression *node, void *data)
{
    node->jjtGetChild(0)->jjtAccept(this,null);
    cout << endl;
    return null;
}

void *AlpiScript::AlpiScriptVisitor::visit(const AlpiScript::ASTInteger *node, void *data)
{
    char * c = (char *)(node->jjtGetValue());
    cout << c;
    node->jjtChildrenAccept(this, nullptr);
    return null;

}

void *AlpiScript::AlpiScriptVisitor::visit(const AlpiScript::ASTSub *node, void *data)
{
    cout << " (";
    node->jjtGetChild(0)->jjtAccept(this,null);

    int i = 1;
    while ( i < node->jjtGetNumChildren() ) {
        cout << " - ";
        node->jjtGetChild(i)->jjtAccept(this,null);
        ++i;
    }
    cout << ") ";
    return null;
}

void *AlpiScript::AlpiScriptVisitor::visit(const AlpiScript::ASTModule *node, void *data)
{
    cout << " (";
    node->jjtGetChild(0)->jjtAccept(this,null);

    int i = 1;
    while ( i < node->jjtGetNumChildren() ) {
        cout << " % ";
        node->jjtGetChild(i)->jjtAccept(this,null);
        ++i;
    }
    cout << ") ";
    return null;
}

void *AlpiScript::AlpiScriptVisitor::visit(const AlpiScript::ASTDivision *node, void *data)
{
    cout << " (";
    node->jjtGetChild(0)->jjtAccept(this,null);

    int i = 1;
    while ( i < node->jjtGetNumChildren() ) {
        cout << " / ";
        node->jjtGetChild(i)->jjtAccept(this,null);
        ++i;
    }
    cout << ") ";
    return null;
}

void *AlpiScript::AlpiScriptVisitor::visit(const AlpiScript::ASTIdentifier *node, void *data)
{
    char * c = (char *)(node->jjtGetValue());
    cout << c;
    return null;
}

void *AlpiScript::AlpiScriptVisitor::visit(const AlpiScript::ASTMult *node, void *data)
{
    cout << " (";
    node->jjtGetChild(0)->jjtAccept(this,null);

    int i = 1;
    while ( i < node->jjtGetNumChildren() ) {
        cout << " * ";
        node->jjtGetChild(i)->jjtAccept(this,null);
        ++i;
    }
    cout << ") ";
    return null;
}

void *AlpiScript::AlpiScriptVisitor::visit(const AlpiScript::ASTAdd *node, void *data)
{
    cout << " (";
    node->jjtGetChild(0)->jjtAccept(this,null);

    int i = 1;
    while ( i < node->jjtGetNumChildren() ) {
        cout << " + ";
        node->jjtGetChild(i)->jjtAccept(this,null);
        ++i;
    }
    cout << ") ";
    return null;

}
