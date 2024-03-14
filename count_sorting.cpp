#include <iostream>
#include <ctime>
using namespace std;

void fill_arr(int* const arr, const int size, int min_val, int max_val)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (max_val - min_val + 1) + min_val;
    }
}

void print_arr(int* arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void countSort(int* arr, int n)
{
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int range = max - min + 1;
    int* count = new int[range]();
    
    for (int i = 0; i < n; i++)
    {
        count[arr[i] - min]++;
    }

    int j = 0;
    for (int i = 0; i < range; i++)
    {
        while (count[i] > 0)
        {
            arr[j++] = i + min;
            count[i]--;
        }
    }

    delete[] count;
}

int main()
{
    srand(time(NULL));
    int size = 25;
    int* arr = new int[size];
    int min_val = -5;
    int max_val = 5;
    fill_arr(arr, size, min_val, max_val);
    cout << "Исходный массив:\n";
    print_arr(arr, size);
    countSort(arr, size);
    cout << "Отсортированный массив:\n";
    print_arr(arr, size);

    delete[] arr;

    return 0;
}