#pragma once

#include <iostream>

class Object
{
public:
    Object(/* args */);
    ~Object();
    virtual void show() = 0;
};