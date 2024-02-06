#include <iostream>
#include <time.h>
#include <math.h>


using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    // int b, c;
    // cin >> b >> c;
    // unsigned int ROW = b;
    // unsigned int COL = c;
    // int a[ROW][COL];
    // for (int i = 0; i < ROW; i++)
    // {
    //     for (int j = 0; j < COL; j++)
    //     {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    int SIZE;
    cin >> SIZE;
    int a[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = rand()%100 - 50;
        cout << a[i] << ' ';
    }
    cout << endl;
    int sum = 0;
    for (int i = 0; i < SIZE / 2; i++)
    {
        sum += (a[i]+a[SIZE-i-1]);
    }
    if (SIZE%2 != 0)
    {
        sum += a[SIZE/2];
    }
    cout << sum << endl;
    system("pause");
}



