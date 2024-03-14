#include <iostream>
#include <time.h>
using namespace std;

void fill_arr(int* const arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand()%100 - 50;
    }
}

void print_arr(int* arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void qsortRecursive(int *mas, int size)
{
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    int mid = mas[size / 2];

    //Делим массив
    do
    {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(mas[i] < mid)
        {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(mas[j] > mid)
        {
            j--;
        }

        //Меняем элементы местами
        if (i <= j)
        {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    }
    while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0)
    {
        //"Левый кусок"
        qsortRecursive(mas, j + 1);
    }
    if (i < size)
    {
        //"Првый кусок"
        qsortRecursive(&mas[i], size - i);
    }
}

int main()
{
    srand(time(NULL));
    int size = 25;
    int* arr = new int[size];
    fill_arr(arr, size);
	print_arr(arr, size);
    qsortRecursive(arr, size);
    print_arr(arr, size);

	return 0;
}