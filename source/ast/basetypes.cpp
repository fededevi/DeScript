#include "basetypes.h"
#include "expression.h"

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
    Method *m = new Method(INT,  Name("operator+"), {INT, INT}, [](std::vector<void *> params) -> Int *{
                      Int * left = static_cast<Int *>(params[0]);
                      Int * right = static_cast<Int *>(params[1]);
                      return new Int(left->value + right->value);
                  });
    addMethod(*m);

}
