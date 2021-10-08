#include "basetypes.h"
#include "expression.h"

#define INT TypeInt::instance()
#define FLOAT TypeFloat::instance()
#define BOOL TypeBool::instance()

void TypeBool::load()
{

}

TypeBool::TypeBool() {
    name = "boolean";
}

void TypeFloat::load()
{
    addMethod( Method(FLOAT,  Name("+"), {FLOAT, FLOAT}, [](std::vector<void *> params) -> Float *{
                  Float * left = static_cast<Float *>(params[0]);
                  Float * right = static_cast<Float *>(params[1]);
                  return new Float(left->value + right->value);
              }));

    addMethod( Method(FLOAT,  Name("+"), {FLOAT, INT}, [](std::vector<void *> params) -> Float *{
                  Float * left = static_cast<Float *>(params[0]);
                  Int * right = static_cast<Int *>(params[1]);
                  return new Float(left->value + right->value);
              }));
}

TypeFloat::TypeFloat()
{
    name = "float";
}

void TypeInt::load()
{
    addMethod( Method(INT,  Name("+"), {INT, INT}, [](std::vector<void *> params) -> Int *{
                  Int * left = static_cast<Int *>(params[0]);
                  Int * right = static_cast<Int *>(params[1]);
                  return new Int(left->value + right->value);
              }));

    addMethod( Method(FLOAT,  Name("+"), {INT, FLOAT}, [](std::vector<void *> params) -> Float *{
                  Int * left = static_cast<Int *>(params[0]);
                  Float * right = static_cast<Float *>(params[1]);
                  return new Float(left->value + right->value);
              }));
}

TypeInt::TypeInt()
{
    name = "int";
}
