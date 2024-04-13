#include <iostream>
#include "Pair.h"

int main()
{
    Pair my_pair(3, 3.1);
    cout << my_pair + 2 << endl;
    cout << my_pair + 3.4 << endl;
    return 0;
}