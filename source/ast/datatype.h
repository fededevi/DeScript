#pragma once

#include <map>
#include <vector>
#include <functional>

#include "visitormacros.h"
#include "expressionvisitor.h"

class DataType;
class Name :public std::string{
public:
    Name(const std::string & v) : std::string(v) {}
};

using MethodSignature = std::pair<Name, std::vector<DataType *>>;

class Method {
public:
    Method(DataType *, const Name &, const std::vector<DataType *>, const std::function<void *(std::vector<void *>)> & );
    Name name;
    DataType * returnType;
    std::vector<DataType * > parameters;
    std::function< void * ( std::vector<void *> )> implementation;

    static std::string signature(MethodSignature ms);
};


class DataType
{

public:
    DataType();

    void addMethod(const Method &);
    bool contains( MethodSignature ) const;

    std::string name;
    std::map<const DataType *, Name> fields;
    std::map<MethodSignature, const Method > methods;
};
