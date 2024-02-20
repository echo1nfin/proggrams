#include <iostream>
#include <math.h>

using namespace std;

long long fac(int x)
{
    long long mult = 1;
    for (int i = 2; i < x+1; i++)
    {
        mult *= i;
    }
    return mult;
}

double func(int x, int m)
{
    if (m < 2)
    {
        return pow(x, m)/fac(m);
    }
    return pow(x, m)/fac(m) + func(x, m-2);
}

int main()
{
    setlocale(LC_ALL, "ru");
    int x, n;
    cin >> x >> n;
    cout << func(x, 2*n+1) << endl;
    system("pause");
}

