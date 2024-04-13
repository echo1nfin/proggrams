#include <iostream>
#include <math.h>

using namespace std;

class GProgression
{
private:
    double first;
    int second;
public:
    GProgression(double a0, int k)
    {
        this->first = a0;
        this->second = k;
    }
    GProgression()
    {
        this->first = 0;
        this->second = 0;
    }

    double element(int j)
    {
        return this->first * pow(this->second, j);
    }
};

int main()
{
    GProgression a(2, 3);
    cout << a.element(3) << endl;

    return 0;
}
