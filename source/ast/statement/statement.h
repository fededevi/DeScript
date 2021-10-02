#ifndef STATEMENT_H
#define STATEMENT_H

#include <memory>

#include "astnode.h"
class Statement : public ASTNode
{
    virtual void execute( ) = 0;

    std::unique_ptr<Statement> next;
};

#endif // STATEMENT_H
