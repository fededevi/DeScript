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

template<typename T>
T * fill(AstConverter * astConv, const SimpleNode * node)
{
    int c = 0;
    T * l = (T *)node->jjtGetChild(c++)->jjtAccept(astConv, null);

    while (c < node->jjtGetNumChildren()) {
        auto sub = new T();
        sub->left = std::unique_ptr<Expression>(l);
        sub->right =   std::unique_ptr<Expression>((Expression*)node->jjtGetChild(c++)->jjtAccept(astConv, null));
        l = sub;
    }

    return l;
}
/*
void AstConverter::fillOperands(UnaryExpression * me, const SimpleNode * node)
{
    Expression * e = (Expression*)node->jjtGetChild(0)->jjtAccept(this, null);
    me->operand = std::unique_ptr<Expression>(e);
}

void AstConverter::fillOperands(BinaryExpression * me, const SimpleNode * node)
{
    Expression * l = (Expression*)node->jjtGetChild(0)->jjtAccept(this, null);
    me->left= std::unique_ptr<Expression>(l);
    Expression * r = (Expression*)node->jjtGetChild(1)->jjtAccept(this, null);
    me->right= std::unique_ptr<Expression>(r);
}*/

void *AstConverter::visit(const SimpleNode *, void *){ return nullptr; }

void *AstConverter::visit(const ASTStart *node, void *)
{
    if (node->jjtGetNumChildren() != 1) {
        std::cout << "Start node have " << node->jjtGetNumChildren() <<
                     " children, abort." << std::endl;
    }
    return node->jjtGetChild(0)->jjtAccept(this, null);
}

void *AstConverter::visit(const ASTSub * node, void *){
    return fill<Sub>(this, node);
}

void *AstConverter::visit(const ASTModule * node, void *){
    return fill<Mod>(this, node);
}

void *AstConverter::visit(const ASTDivision * node, void *){
    return fill<Div>(this, node);
}

void *AstConverter::visit(const ASTNegative *node, void *data)
{
    Neg * n = new Neg();
    n->operand = std::unique_ptr<Expression>((Expression*)node->jjtGetChild(0)->jjtAccept(this, null));
    return n;
}

void *AstConverter::visit(const ASTMult * node, void *){
    return fill<Mul>(this, node);
}

void *AstConverter::visit(const ASTAdd *node, void *){
    return fill<Add>(this, node);
}

void *AstConverter::visit(const ASTLessThan *node, void *){
    return fill<LessThan>(this, node);
}

void *AstConverter::visit(const ASTLessEqual *node, void *) {
    return fill<LessEqual>(this, node);
}

void *AstConverter::visit(const ASTGreaterEqual *node, void *){
    return fill<GreaterEqual>(this, node);
}

void *AstConverter::visit(const ASTGreaterThan *node, void *){
    return fill<GreaterThan>(this, node);
}

void *AstConverter::visit(const ASTEqual *node, void *) {
    return fill<Equal>(this, node);
}

void *AstConverter::visit(const ASTNotEqual *node, void *){
    return fill<NotEqual>(this, node);
}

void *AstConverter::visit(const ASTNot *node, void *){
    Not * n = new Not();
    n->operand = std::unique_ptr<Expression>((Expression*)node->jjtGetChild(0)->jjtAccept(this, null));
    return n;
}

void *AstConverter::visit(const ASTAnd *node, void *) {
    return fill<And>(this, node);
}

void *AstConverter::visit(const ASTOr *node, void * ) {
    return fill<Or>(this, node);
}

void *AstConverter::visit(const ASTFloat * node, void *){
    char * c = (char *)(node->jjtGetValue());
    return new Float(std::stod(c));
}

void *AstConverter::visit(const ASTBoolean *node, void *){
    char * c = (char *)(node->jjtGetValue());

    if (std::string(c) == "true")
        return new Boolean(true);
    else
        return new Boolean(false);
}

void * AstConverter::visit(const ASTInteger * node, void *){
    char * c = (char *)(node->jjtGetValue());
    return new Int(std::stoi(c));
}

void *AstConverter::visit(const ASTIdentifier * node, void *)
{
    return new Id((char *)(node->jjtGetValue()));
}

}
