#pragma once

using namespace std;

class Pair
{
private:
    int int_number;
    double double_number;
public:
    Pair();
    Pair(int number1, double number2);
    friend ostream& operator << (ostream& os, Pair pair);
    Pair operator - (Pair pair);
    Pair operator + (int num);
    Pair operator + (double num);
};

Pair::Pair()
{
    this->int_number = 0;
    this->double_number = 0.0;
}

Pair::Pair(int number1, double number2)
{
    this->int_number = number1;
    this->double_number = number2;
}

ostream& operator << (ostream& os, Pair pair)
{
    os << pair.int_number << " : " << pair.double_number;
    return os;
}

Pair Pair::operator + (int num)
{
    this->int_number += num;
    return *this;
}

Pair Pair::operator + (double num)
{
    this->double_number += num;
    return *this;
}