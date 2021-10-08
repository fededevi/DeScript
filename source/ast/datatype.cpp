#include "datatype.h"

#include <algorithm>
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

bool DataType::contains( MethodSignature ms) const
{
    return methods.end() != methods.find(ms);
}


Method::Method(DataType * rt, const Name &nm, const std::vector<DataType *> pa, const std::function<void *(std::vector<void *>)> & impl)
    : name(nm)
    , returnType(rt)
    , parameters(pa)
    , implementation(impl)
{}

std::string Method::signature(MethodSignature ms){
    std::string out;
    for (DataType * t : ms.second) {
        out += t->name + ",";
    }
    return ms.first + "(" + out.substr(0,out.length()-1) + ")";
}
