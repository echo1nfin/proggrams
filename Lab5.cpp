#include <iostream>
#include <math.h>
#include <time.h>

void arr_fill(int a[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = -1;
    }
}

using namespace std;

int main()
{       
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int ROW, COL;
    cin >> ROW >> COL;
    int a[ROW][COL];
    int SIZE = ROW*COL*2;
    int b[SIZE];
    int first_col[ROW];
    int elem;
    bool flag = false;

    // fill array
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            flag = false;
            while (!flag)
            {
                elem = rand()%200 - 50;

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

    // fill array first_col[]
    for (int i = 0; i < ROW; i++)
    {
        first_col[i] = a[i][0];
    }

    int temp1[ROW];
    arr_fill(temp1, ROW);
    int temp_i;
    int i = rand()%ROW;
    temp1[0] = i;
    int k = 0;
    int j = 0;
    int n = 0;

    // ROW from array a[] to array b[]
    while (k != SIZE/2)
    {
        if (j < COL)
        {
            b[k] = a[i][j];
            j++;
            k++;
        }
        else
        {
            n++;
            flag = false;
            while (!flag)
            {
                temp_i = rand()%ROW;
                for (int c = 0; c < ROW; c++)
                {
                    if (temp_i == temp1[c])
                    {
                        flag = true;
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
            i = temp_i;
            temp1[n] = i;
            j = 0;
        }
    }
    int temp2[COL];
    arr_fill(temp2, COL);
    i = rand()%COL;
    temp2[0] = i;
    n = 0;
    j = 0;
    // COL from array a[] to array b[]
    while (k != SIZE)
    {
        if (j < COL)
        {
            b[k] = a[j][i];
            j++;
            k++;
        }
        else
        {
            n++;
            flag = false;
            while (!flag)
            {
                temp_i = rand()%COL;
                for (int c = 0; c < COL; c++)
                {
                    if (temp_i == temp2[c])
                    {
                        flag = true;
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
            i = temp_i;
            temp2[n] = i;
            j = 0;
        }
    }

    int new_a[ROW][COL];
    int row = 0;
    int col = 0;

    while (row != ROW)
    {
        int curr_elem = first_col[row];
        for (int t = 0; t < SIZE/2; t++)
        {
            if (b[t] == curr_elem)
            {
                while (col != COL)
                {
                    new_a[row][col] = b[t+col];
                    col++;
                }
            }
        }
        row++;
        col = 0;
    }

    // out array`s
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << b[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << new_a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    system("pause");
}

