#include <iostream>
#include <math.h>

using namespace std;

double len_by_dots(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1-y2, 2));
}

double area_of_triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return 0.5 * fabs((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1));
}

double square1(int count, ...)
{
    int* p = &count + 1;
    int sum = 0;
    for (count; count != 0; count--)
    {
        sum += *p;
        p++;
    }
    return sum;
}

int main()
{
    cout << area_of_triangle(10,2.2,3,4,5,16);
}