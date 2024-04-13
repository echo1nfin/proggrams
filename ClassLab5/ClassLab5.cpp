#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Object.h"
#include "Vector.h"

using namespace std;

int main()
{
    
    Vector vector(5);
    Person man1;
    cin >> man1;
    Student man2;
    cin >> man2;
    Object* p = &man1;
    vector.add(p);
    p = &man2;
    vector.add(p);
    cout << vector;

    return 0;
}
