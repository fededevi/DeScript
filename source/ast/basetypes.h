#pragma once

#include "datatype.h"


class TypeInt : public DataType
{
public:
    static TypeInt *instance() {
        static TypeInt instance;
        return &instance;
    }

    void load();
private:
    TypeInt();
};

class TypeFloat : public DataType
{
public:
    static TypeFloat * instance() {
        static TypeFloat instance;
        return &instance;
    }

    void load();
private:
    TypeFloat();
};

class TypeBool : public DataType
{
public:
    static TypeBool * instance() {
        static TypeBool instance;
        return &instance;
    }

    void load();
private:
    TypeBool();
};

