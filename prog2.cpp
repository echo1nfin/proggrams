#include <iostream>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int ROW, COL;

    std::cin >> ROW >> COL;

    int a[ROW][COL];
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (j <= i)
            {
                a[i][j] = (i - j)%9 + 1;
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            std::cout << a[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    system("pause");
}