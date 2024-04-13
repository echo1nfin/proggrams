#include <iostream>
#include "Vector.h"

Vector::Vector()
{
    this->size = 0;
    this->begin = 0;
    this->current = 0;
}

Vector::~Vector()
{
    if (this->begin != nullptr)
    {
        delete [] this->begin;
        this->begin = nullptr;
    }
}

Vector::Vector(int n)
{
    this->begin = new Object*[n];
    this->size = n;
    this->current = 0;
}

void Vector::add(Object* object)
{
    if (this->current < this->size)
    {
        this->begin[this->current] = object;
        this->current++;
    }
}

std::ostream& operator << (std::ostream& os, const Vector& vector)
{
    Object** p = vector.begin;
    for (int i = 0; i < vector.current; i++)
    {
        (*p)->show();
        p++;
    }
    return os;
}