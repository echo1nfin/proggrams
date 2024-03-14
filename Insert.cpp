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

void merge(int* arr, int left, 
           int mid, int right)
{
    int subArrOne = mid - left + 1;
    int subArrTwo = right - mid;
 
    int* leftArr = new int[subArrOne];
    int* rightArr = new int[subArrTwo];

    for (int i = 0; i < subArrOne; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < subArrTwo; j++)
        rightArr[j] = arr[mid + 1 + j];
 
    int indexOfSubArrOne = 0;
    int indexOfSubArrTwo = 0; 
 
    int indexOfMergedArr = left; 

    while (indexOfSubArrOne < subArrOne && 
           indexOfSubArrTwo < subArrTwo) 
    {
        if (leftArr[indexOfSubArrOne] <= 
            rightArr[indexOfSubArrTwo]) 
        {
            arr[indexOfMergedArr] = leftArr[indexOfSubArrOne];
            indexOfSubArrOne++;
        }
        else
        {
            arr[indexOfMergedArr] = 
            rightArr[indexOfSubArrTwo];
            indexOfSubArrTwo++;
        }
        indexOfMergedArr++;
    }
     
    while (indexOfSubArrOne < subArrOne) 
    {
        arr[indexOfMergedArr] = leftArr[indexOfSubArrOne];
        indexOfSubArrOne++;
        indexOfMergedArr++;
    }
 
    while (indexOfSubArrTwo < subArrTwo) 
    {
        arr[indexOfMergedArr] = rightArr[indexOfSubArrTwo];
        indexOfSubArrTwo++;
        indexOfMergedArr++;
    }
}
 
void mergeSort(int* arr, 
               int const begin, 
               int const end)
{
    if (begin >= end)
        return; 
 
    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

int main()
{
    srand(time(NULL));
    int size = 25;
    int* arr = new int[size];
    fill_arr(arr, size);
	print_arr(arr, size);
    mergeSort(arr, 0, size-1);
    print_arr(arr, size);

	return 0;
}