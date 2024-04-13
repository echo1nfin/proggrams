#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
    Student man1("Kirill", 23, "Math", 4);
    Student man2("Andrew", 12, "Inf", 5);
    Student man3;
    
    man1 = man2;

    cout << man1 << endl;

    cin >> man3;

    cout << man3 << endl;

    return 0;
}
