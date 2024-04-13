#pragma once

#include <iostream>
#include "Object.h"

class Vector
{
private:
    Object** begin;
    int size;
    int current;
public:
    Vector();
    Vector(int);
    void add(Object*);
    friend std::ostream& operator<<(std::ostream& os,const Vector&);
    ~Vector();
};