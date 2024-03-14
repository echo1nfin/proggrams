#include <iostream>
#include <string>

using namespace std;

int func(int a, int b)
{
    return a + b;
}

double func(double a, double b)
{
    return a * b;
}

template <typename t>
t upd_func(t a, t b)
{
    return a + b;
}

int main()
{
    cout << func(2, 2) << endl;
    cout << func(3.3, 1.1) << endl;
    cout << upd_func(4, 5) << endl;
    cout << upd_func(1.3, 4.5) << endl;
    string a = "abc";
    string b = "cba";
    cout << upd_func(a, b) << endl;
    system("pause");
    return 0;
}