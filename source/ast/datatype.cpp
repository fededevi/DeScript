#include "datatype.h"

#include <map>
#include <vector>
#include <functional>
#include "expression.h"

DataType::DataType()
{

}

void DataType::addMethod(const Method & m)
{
    methods.insert({ MethodSignature(m.name, m.parameters), m});
}


Method::Method(DataType * rt, const Name &nm, const std::vector<DataType *> pa, const std::function<void *(std::vector<void *>)> & impl)
    : name(nm)
    , returnType(rt)
    , parameters(pa)
    , implementation(impl)
{}
