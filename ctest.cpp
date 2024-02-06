#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

long double fac(int num)
{
    long double mult = 1;
    for (int i = 2; i < num+1; i++)
    {
        mult *= i;
    }
    return mult;
}


int main()
{
    cout << fixed << setprecision(0) << fac(1000) << endl;
    
}