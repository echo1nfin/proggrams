#pragma once

#include <iostream>
#include <string>
#include "Object.h"

class Person: public Object
{
protected:
    std::string name;
    int age;
public:
    Person();
    void show();
    Person(std::string name, int age);
    Person(Person& person);
    ~Person();
    std::string get_name();
    void set_name(std::string name);
    int get_age();
    void set_age(int age);
    Person& operator = (Person& person);
    friend std::ostream& operator << (std::ostream& os, Person& person);
    friend std::istream& operator >> (std::istream& is, Person& person);
};

