#include <iostream>
#include <string>

#include "Student.h"

Student::Student()
{
    this->name = "None";
    this->age = -1;
    this->subject = "None";
    this->mark = -1;
}

Student::Student(std::string name, int age, std::string subject, int mark)
{
    this->name = name;
    this->age = age;
    this->subject = subject;
    this->mark = mark;
}

Student::Student(Student& student)
{
    this->name = student.name;
    this->age = student.age;
    this->subject = student.subject;
    this->mark = student.mark;
}

Student::~Student()
{
    std::cout << "Student Destructor" << std::endl;
}

std::string Student::get_subject()
{
    return this->subject;
}

int Student::get_mark()
{
    return this->mark;
}

void Student::set_subject(std::string subject)
{
    this->subject = subject;
}

void Student::set_mark(int mark)
{
    this->mark = mark;
}

void Student::check_mark()
{
    if (this->mark < 3)
    {
        std::cout << "bad mark" << std::endl;
    }
    else
    {
        std::cout << "good mark" << std::endl;
    }
}

Student& Student::operator = (Student& student)
{
    this->subject = student.subject;
    this->mark = student.mark;
    return *this;
}

std::ostream& operator << (std::ostream& os, Student& student)
{
    os << static_cast<Person&>(student) << ' ' << student.subject << ' ' << student.mark;
    return os;
}

std::istream& operator>>(std::istream& is, Student& student)
{
    is >> static_cast<Person&>(student);
    is >> student.subject;
    is >> student.mark;
    return is;
}
