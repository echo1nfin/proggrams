#pragma once

#include <iostream>
#include <string>
#include "Person.h"

class Student: public Person
{
protected:
    std::string subject;
    int mark;
public:
    Student();
    void show();
    Student(std::string name, int age, std::string subject, int mark);
    Student(Student& student);
    ~Student();
    std::string get_subject();
    int get_mark();
    void set_subject(std::string subject);
    void set_mark(int mark);
    void check_mark();
    Student& operator = (Student& student);
    friend std::ostream& operator << (std::ostream& os, Student& student);
    friend std::istream& operator >> (std::istream& is, Student& student);
};