#ifndef CONTEXT_H
#define CONTEXT_H

#include <map>
#include <memory>
#include <string>

#include "expression.h"

class Literal;
class Context
{
public:
    Context();
    std::map<std::string, std::unique_ptr<Literal>> data;
};

#endif // CONTEXT_H
