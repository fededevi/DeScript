#include "basetypes.h"

#define INT TypeInt::instance()
#define FLOAT TypeInt::instance()
#define BOOL TypeInt::instance()

TypeBool::TypeBool()
{

}

TypeFloat::TypeFloat()
{

}

TypeInt::TypeInt()
{
    addMethod(Method(BOOL, Name("+"), {INT, INT}));
    addMethod(Method(BOOL, Name("<"), {INT, INT}));
}
