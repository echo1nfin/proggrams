#pragma once

#include <string>

using namespace std;

class Car
{
private:
    float price;
    string color;
public:
    Car(float price, string color);
    Car();
    ~Car();
    get_price();
};

Car::Car(float price, string color)
{
    this->price = price;
    this->color = color;
}

Car::Car()
{
    this->price = 0;
    this->color = "None";
}

Car::~Car()
{
    cout << "Destructor" << endl;
}

Car::get_price()
{
    return this->price;
}