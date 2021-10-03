#include "astconverter.h"

#include "../ast/expression.h"

#include "source/javacc/generated/Parser.h"
#include "source/javacc/generated/ParseException.h"
#include "source/javacc/generated/CharStream.h"
#include "source/javacc/generated/ParserTokenManager.h"
#include "source/javacc/generated/ParserTokenManager.h"

namespace AlpiScript {

Expression *AstConverter::parse(const std::string &input)
{
    try {
        CharStream stream(input.c_str(), input.size() - 1, 1, 1);
        ParserTokenManager scanner = ParserTokenManager(&stream);
        Parser parser(&scanner);
        SimpleNode * baseNode = parser.parse();
        AstConverter astconv;
        Expression * e = (Expression *)baseNode->jjtAccept(&astconv, null);
        return e;
    } catch (const ParseException& e) {
        cout << "ERROR..." << e.tokenImage << endl;
        return null;
    }
}

void *AstConverter::visit(const SimpleNode *, void *)
{
    return nullptr;
}

void * AstConverter::visit(const ASTExpression *node, void *)
{
    return node->jjtGetChild(0)->jjtAccept(this,null);
}

void * AstConverter::visit(const ASTInteger *node, void *)
{
    char * c = (char *)(node->jjtGetValue());
    return new Int(std::stoi(c));
}

void *AstConverter::visit(const ASTSub * node, void *)
{
    MultiExpression * e = new Sub();
    fillOperands(e, node);
    return e;
}

void *AstConverter::visit(const ASTModule * node, void *)
{
    MultiExpression * e = new Mod();
    fillOperands(e, node);
    return e;
}

void *AstConverter::visit(const ASTDivision * node, void *)
{
    MultiExpression * e = new Div();
    fillOperands(e, node);
    return e;
}


void *AstConverter::visit(const ASTIdentifier *node, void *)
{
    return new Id((char *)(node->jjtGetValue()));
}

void *AstConverter::visit(const ASTMult * node, void *)
{
    MultiExpression * e = new Mul();
    fillOperands(e, node);
    return e;
}

void *AstConverter::visit(const ASTAdd *node, void *)
{
    MultiExpression * e = new Add();
    fillOperands(e, node);
    return e;
}

void AstConverter::fillOperands(MultiExpression * me, const SimpleNode * node)
{
    int i = 0;
    while ( i < node->jjtGetNumChildren() ) {
        Expression * e = (Expression*)node->jjtGetChild(i)->jjtAccept(this, null);
        me->operands.push_back(std::unique_ptr<Expression>(e));
        ++i;
    }
}

}
