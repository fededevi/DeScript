#include "type.h"

Type::Type()
{

}

void Type::addMethod(const Method & m)
{
    methods.insert({ m.name, m});
}

