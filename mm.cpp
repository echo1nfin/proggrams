#include <iostream>
#include "Car.h"

int main()
{
    Car Renault(1100000, "Black");
    cout << Renault.get_price() << endl;
}