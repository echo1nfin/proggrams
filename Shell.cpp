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

void shellSort(vector<int>& arr, int size) 
{ 
    for (int gap = size/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < size; i++) 
        { 
            int temp = arr[i]; 
            int j; 
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
            {
                arr[j] = arr[j - gap]; 
            }           
            arr[j] = temp; 
        } 
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
    shellSort(arr, size);
    print_arr(arr);

	return 0;
}