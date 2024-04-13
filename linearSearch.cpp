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

bool linearSearch(const string text, const string pattern)
{
    for (int i = 0; i < text.length(); i++)
    {
        bool flag = true;
        for (int j = 0; j < pattern.length() && flag; j++)
        {
            if (text[i+j] != pattern[j])
            {
                flag = false;
            }
        }
        if (flag)
        {
            cout << "От " << i << " до " << i+pattern.length() << endl;
            return true;
        }
    }
    return false;
}

bool binSearch(vector<int>& numbers, const int pattern)
{
    int left_index = 0;
    int right_index = numbers.size() - 1;
    int middle_index = (left_index + right_index) / 2; // 0 1 2 (3) 4 5 6
    
    while (numbers.at(middle_index) != pattern && left_index < right_index)
    {
        if (numbers.at(middle_index) > pattern)
        {
            right_index = middle_index - 1;
            middle_index = (left_index + right_index)/2;
        }
        else
        {
            left_index = middle_index + 1;
            middle_index = (left_index + right_index)/2;
        }
    }
    cout << middle_index << endl;
    return true;
}

int main()
{
    srand(time(NULL));
    system("chcp 1251 > Null");
    string text, pattern;
    vector<int> numbers;
    for (int i = 0; i < 15; i++)
    {
        numbers.push_back(rand()%(50+1) - 50);
    }
    quicksort(numbers, 0, numbers.size() - 1);
    // getline(cin, text);
    // getline(cin, pattern);
    for (int i: numbers)
    {
        cout << i << ' ';
    }
    cout << endl;
    // cout << linearSearch(text, pattern);
    int number;
    cin >> number;
    binSearch(numbers, number);
    system("pause");
}