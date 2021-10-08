#pragma once

#include <map>
#include "expression.h"

class Type
{
public:
    Type();

    std::map<Id, Type> fields;
    std::map<Id, Type> methods;
};
