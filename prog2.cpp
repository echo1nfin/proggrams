#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int ROW, COL;
    cin >> ROW >> COL;
    int a[ROW][COL];
    int elem;
    bool flag;

    // fill array
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            flag = false;
            while (!flag)
            {
                elem = rand()%10;

                for (int k = 0; k < ROW; k++)
                {
                    for (int t = 0; t < COL; t++)
                    {
                        if (elem == a[k][t])
                        {
                            flag = true;
                        }
                    }
                }
                if (flag)
                {
                    flag = false;
                }
                else
                {
                    flag = true;
                }
            }
            a[i][j] = elem;
        }
    }
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

    system("pause");
}