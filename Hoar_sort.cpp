#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

void fill_arr(vector<int>& arr, const int size)
{
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = rand()%100 - 50;
    }
}

void print_arr(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void quicksort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quicksort(arr, low, p);
        quicksort(arr, p + 1, high);
    }
}

int main()
{
    srand(time(NULL));
    int size;
    cin >> size;
    vector<int> arr(size);
    fill_arr(arr, size);
    print_arr(arr);

    quicksort(arr, 0, size - 1);

    print_arr(arr);

    return 0;
}
