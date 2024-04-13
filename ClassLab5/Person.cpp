#include <iostream>
#include "Person.h"

Person::Person()
{
    this->name = "None";
    this->age = -1;
}

void Person::show()
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Age: " << this->age << std::endl;
}

Person::Person(std::string name, int age)
{
    this->name = name;
    this->age = age;
}

Person::Person(Person& person)
{
    this->name = person.name;
    this->age = person.age;
}

Person::~Person()
{
    std::cout << "Destructor" << std::endl;
}

std::string Person::get_name()
{
    return this->name;
}

void Person::set_name(std::string name)
{
    this->name = name;
}

int Person::get_age()
{
    return this->age;
}

void Person::set_age(int age)
{
    this->age = age;
}

Person& Person::operator = (Person& person)
{
    this->name = person.name;
    this->age = person.age;
    return *this;
}

std::ostream& operator << (std::ostream& os, Person& person)
{
    os << person.get_name() << ' ' << person.get_age();
    return os;
}

std::istream& operator >> (std::istream& is, Person& person) {
    std::string name;
    int age;
    is >> name >> age;
    person.set_name(name);
    person.set_age(age);
    return is;
}