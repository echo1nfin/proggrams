#include <iostream>
#include <time.h>
#include <math.h>


using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int b, c;
    cin >> b >> c;
    unsigned int ROW = b;
    unsigned int COL = c;
    int a[ROW][COL];
    int num = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if ((i+j)%2 != 0)
            {
                a[i][j] = 0;
            }
            else
            {
                a[i][j] = num%9 + 1;
                num++;
            }
            cout << a[i][j] << "   ";
        }
        cout << endl;
        cout << endl;
    }
    cout << endl;
    system("pause");
}
