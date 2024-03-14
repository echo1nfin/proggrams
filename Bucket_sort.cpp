#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Функция заполнения массива случайными числами в заданном диапазоне
void fill_arr(int* const arr, const int size, int min_val, int max_val)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (max_val - min_val + 1) + min_val;
    }
}

// Функция печати массива
void print_arr(int* arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Функция поиска минимального элемента в массиве
int find_min(int* arr, int n)
{
    int min_val = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min_val)
        {
            min_val = arr[i];
        }
    }
    return min_val;
}

// Функция поиска максимального элемента в массиве
int find_max(int* arr, int n)
{
    int max_val = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }
    return max_val;
}

// Функция сортировки корзиной (Bucket Sort)
void bucketSort(int* arr, int n)
{
    // Определяем максимальное и минимальное значение в массиве
    int min_val = find_min(arr, n);
    int max_val = find_max(arr, n);

    // Создаем вектор корзин
    vector<int> buckets[max_val - min_val + 1];

    // Распределяем элементы по корзинам
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] - min_val; // Определяем индекс корзины
        buckets[bucket_index].push_back(arr[i]);
    }

    // Сортируем каждую корзину и объединяем их обратно в исходный массив
    int index = 0;
    for (int i = 0; i < (max_val - min_val + 1); i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main()
{
    srand(time(NULL));

    int size = 20;
    int min_val = -5;
    int max_val = 5;
    int* arr = new int[size];
    fill_arr(arr, size, min_val, max_val);
    cout << "Original array:" << endl;
    print_arr(arr, size);
    bucketSort(arr, size);
    cout << "Sorted array:" << endl;
    print_arr(arr, size);

    delete[] arr;

    return 0;
}
