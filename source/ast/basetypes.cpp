#include "basetypes.h"
#include "expression.h"

#define INT TypeInt::instance()
#define FLOAT TypeFloat::instance()
#define BOOL TypeBool::instance()

void TypeBool::load()
{
    addMethod( Method(BOOL,  Name("!"), {BOOL}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(!static_cast<Boolean *>(params[0])->value);
               }));
    addMethod( Method(BOOL,  Name("=="), {BOOL, BOOL}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Boolean *>(params[0])->value == static_cast<Boolean *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name("!="), {BOOL, BOOL}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Boolean *>(params[0])->value != static_cast<Boolean *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name("&&"), {BOOL, BOOL}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Boolean *>(params[0])->value && static_cast<Boolean *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name("||"), {BOOL, BOOL}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Boolean *>(params[0])->value || static_cast<Boolean *>(params[1])->value);
               }));
}

TypeBool::TypeBool() {
    name = "boolean";
}

void TypeFloat::load()
{
    addMethod( Method(FLOAT,  Name("-"), { FLOAT}, [](std::vector<void *> params) -> Float *{
                   return new Float(-static_cast<Float *>(params[0])->value);
               }));

    addMethod( Method(FLOAT,  Name("+"), {FLOAT, FLOAT}, [](std::vector<void *> params) -> Float *{
                   return new Float(static_cast<Float *>(params[0])->value + static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(FLOAT,  Name("+"), {FLOAT, INT}, [](std::vector<void *> params) -> Float *{
                   return new Float(static_cast<Float *>(params[0])->value + static_cast<Int *>(params[1])->value);
               }));
    addMethod( Method(FLOAT,  Name("-"), {FLOAT, FLOAT}, [](std::vector<void *> params) -> Float *{
                   return new Float(static_cast<Float *>(params[0])->value - static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(FLOAT,  Name("-"), {FLOAT, INT}, [](std::vector<void *> params) -> Float *{
                   return new Float(static_cast<Float *>(params[0])->value - static_cast<Int *>(params[1])->value);
               }));
    addMethod( Method(FLOAT,  Name("*"), {FLOAT, FLOAT}, [](std::vector<void *> params) -> Float *{
                   return new Float(static_cast<Float *>(params[0])->value * static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(FLOAT,  Name("*"), {FLOAT, INT}, [](std::vector<void *> params) -> Float *{
                   return new Float(static_cast<Float *>(params[0])->value * static_cast<Int *>(params[1])->value);
               }));
    addMethod( Method(FLOAT,  Name("/"), {FLOAT, FLOAT}, [](std::vector<void *> params) -> Float *{
                   return new Float(static_cast<Float *>(params[0])->value / static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(FLOAT,  Name("/"), {FLOAT, INT}, [](std::vector<void *> params) -> Float *{
                   return new Float(static_cast<Float *>(params[0])->value / static_cast<Int *>(params[1])->value);
               }));

    // BOOLEAN OPERATORS
    addMethod( Method(BOOL,  Name("<"), {FLOAT, FLOAT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Float *>(params[0])->value < static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name("<"), {FLOAT, INT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Float *>(params[0])->value < static_cast<Int *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name("<="), {FLOAT, FLOAT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Float *>(params[0])->value <= static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name("<="), {FLOAT, INT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Float *>(params[0])->value <= static_cast<Int *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name(">="), {FLOAT, FLOAT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Float *>(params[0])->value >= static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name(">="), {FLOAT, INT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Float *>(params[0])->value >= static_cast<Int *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name(">"), {FLOAT, FLOAT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Float *>(params[0])->value > static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name(">"), {FLOAT, INT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Float *>(params[0])->value > static_cast<Int *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name("=="), {FLOAT, FLOAT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Float *>(params[0])->value == static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name("=="), {FLOAT, INT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Float *>(params[0])->value == static_cast<Int *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name("!="), {FLOAT, FLOAT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Float *>(params[0])->value != static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name("!="), {FLOAT, INT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Float *>(params[0])->value != static_cast<Int *>(params[1])->value);
               }));

}

TypeFloat::TypeFloat()
{
    name = "float";
}

void TypeInt::load()
{
    addMethod( Method(INT,  Name("-"), { INT}, [](std::vector<void *> params) -> Int *{
                   return new Int(-static_cast<Int *>(params[0])->value);
               }));

    addMethod( Method(INT,  Name("+"), {INT, INT}, [](std::vector<void *> params) -> Int *{
                   return new Int(static_cast<Int *>(params[0])->value + static_cast<Int *>(params[1])->value);
               }));
    addMethod( Method(FLOAT,  Name("+"), {INT, FLOAT}, [](std::vector<void *> params) -> Float *{
                   return new Float(static_cast<Int *>(params[0])->value + static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(INT,  Name("-"), {INT, INT}, [](std::vector<void *> params) -> Int *{
                   return new Int(static_cast<Int *>(params[0])->value - static_cast<Int *>(params[1])->value);
               }));
    addMethod( Method(FLOAT,  Name("-"), {INT, FLOAT}, [](std::vector<void *> params) -> Float *{
                   return new Float(static_cast<Int *>(params[0])->value - static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(INT,  Name("*"), {INT, INT}, [](std::vector<void *> params) -> Int *{
                   return new Int(static_cast<Int *>(params[0])->value * static_cast<Int *>(params[1])->value);
               }));
    addMethod( Method(FLOAT,  Name("*"), {INT, FLOAT}, [](std::vector<void *> params) -> Float *{
                   return new Float(static_cast<Int *>(params[0])->value * static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(INT,  Name("/"), {INT, INT}, [](std::vector<void *> params) -> Int *{
                   return new Int(static_cast<Int *>(params[0])->value / static_cast<Int *>(params[1])->value);
               }));
    addMethod( Method(FLOAT,  Name("/"), {INT, FLOAT}, [](std::vector<void *> params) -> Float *{
                   return new Float(static_cast<Int *>(params[0])->value / static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(INT,  Name("%"), {INT, INT}, [](std::vector<void *> params) -> Int *{
                   return new Int(static_cast<Int *>(params[0])->value % static_cast<Int *>(params[1])->value);
               }));

    // BOOLEAN OPERATORS
    addMethod( Method(BOOL,  Name("<"), {INT, FLOAT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Int *>(params[0])->value < static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name("<"), {INT, INT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Int *>(params[0])->value < static_cast<Int *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name("<="), {INT, FLOAT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Int *>(params[0])->value <= static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name("<="), {INT, INT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Int *>(params[0])->value <= static_cast<Int *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name(">="), {INT, FLOAT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Int *>(params[0])->value >= static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name(">="), {INT, INT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Int *>(params[0])->value >= static_cast<Int *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name(">"), {INT, FLOAT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Int *>(params[0])->value > static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name(">"), {INT, INT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Int *>(params[0])->value > static_cast<Int *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name("=="), {INT, FLOAT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Int *>(params[0])->value == static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name("=="), {INT, INT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Int *>(params[0])->value == static_cast<Int *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name("!="), {INT, FLOAT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Int *>(params[0])->value != static_cast<Float *>(params[1])->value);
               }));
    addMethod( Method(BOOL,  Name("!="), {INT, INT}, [](std::vector<void *> params) -> Boolean *{
                   return new Boolean(static_cast<Int *>(params[0])->value != static_cast<Int *>(params[1])->value);
               }));
}

TypeInt::TypeInt()
{
    name = "int";
}
