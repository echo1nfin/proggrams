#include <iostream>

using namespace std;

int main()
{
    int a = 7;
    int b = 8;
    int* pa = &a;
    cout << pa << endl;
    int* pb = &b;
    cout << pb << endl;
    pb = pa;
    cout << pb << endl;
    cout << *pb << endl;
    cout << *pa << endl;
}