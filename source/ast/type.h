#pragma once

#include <map>
#include <vector>

#include "visitormacros.h"
#include "expressionvisitor.h"

class Type;

class Name {
public:
    std::string value;
    Name(const std::string & v) : value(v) {}
};

class Method {
public:
    Method(Type *, const Name &, const std::vector<Type *> );
    Name name;
    Type * returnType;
    std::vector<Type * > parameters;
};

class Type
{
public:
    Type();

    void addMethod(const Method &);

    std::map<const Type *, const TypeId> fields;
    std::map<Name, Method> methods;
};
