#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

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

void interpol(vector<int>& numbers, const int pattern)
{
    int left_index = 0;
    int right_index = numbers.size() - 1;
    bool flag = false;
    while (left_index <= right_index && !flag)
    {
        int middle_index = left_index + (((pattern - numbers[left_index])*(right_index - left_index))/(numbers[right_index] - numbers[left_index]));
        if (numbers.at(middle_index) > pattern)
        {
            right_index = middle_index - 1;
        }
        else if (numbers.at(middle_index) < pattern)
        {
            left_index = middle_index + 1;
        }
        else
        {
            flag = true;
            cout << middle_index << endl;
        }
    }
}

int main()
{
    srand(time(NULL));
    system("chcp 1251 > Null");
    vector<int> numbers;
    for (int i = 0; i < 15; i++)
    {
        numbers.push_back(rand()%51 - 25);
    }
    quicksort(numbers, 0, numbers.size() - 1);

    for (int i: numbers)
    {
        cout << i << ' ';
    }
    cout << endl;

    int number;
    cin >> number;

    interpol(numbers, number);
    
    system("pause");
}