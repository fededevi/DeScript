#pragma once

#include "type.h"

#define INT TypeInt::instance()
#define FLOAT TypeInt::instance()
#define BOOL TypeInt::instance()

class TypeInt : public Type
{
    static TypeInt * instance() {
        static TypeInt instance;
        return &instance;
    }

private:
    TypeInt();
};

class TypeFloat : public Type
{
private:
    TypeFloat();
};

class TypeBool : public Type
{
private:
    TypeBool();
};

