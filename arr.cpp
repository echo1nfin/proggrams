#include <iostream>
#include <time.h>

using namespace std;

void out_array(int arr[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    cout << endl;
}

void out_matrix(int arr[][4], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void fill_array(int arr[][4], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = rand()%20 - 10;
        }
    }
}

void function(int arr[][4], int& rows)
{
    bool flag = false;
    for (int i = 0; i < rows; i++)
    {
        if ((i+1)%2 != 0)
        {
            for (int j = 0; j < 4; ++j)
            {
                arr[i / 2][j] = arr[i][j];
            }
        }

    }
    rows = (rows + 1) / 2;
}

void function(int arr[], int& SIZE)
{
    int c = 0;
    for (int i = 1; i < SIZE-1; i++)
    {
        if (arr[i-1] == 0 && arr[i+1] == 0 && arr[i] != 0)
        {
            c++;
            for (int j = i; j < SIZE-1; j++)
            {
                arr[j] = arr[j+1];
            }
        }
    }
    SIZE -= c;
}

int main()
{
    srand(time(NULL));
    int n;
    cin >> n;
    const int ROW = n;
    int rows = ROW;
    const int COLS = 4;
    int myArray[ROW][COLS];
    const int SIZE = 12;
    int size = SIZE;
    int a[SIZE] {0,1,0,3,3,4,0,6,0,0,0,7};
    
    // Вызываем функцию и передаем массив
    fill_array(myArray, rows);
    out_matrix(myArray, rows);
    cout << endl;
    function(a, size);
    out_array(a, size);
    function(myArray, rows);
    out_matrix(myArray, rows);
    system("pause");
    return 0;
}

