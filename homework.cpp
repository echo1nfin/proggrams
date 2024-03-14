#include <iostream>

void swap_values(int& num1Ref, int& num2Ref)
{
    int tempRef = num1Ref;
    num1Ref = num2Ref;
    num2Ref = tempRef;
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << a << ' ' << b << std::endl;

    swap_values(a, b);

    std::cout << a << ' ' << b << std::endl;

    system("pause");
}