#include <iostream>
#include <string>
#include <vector>

using namespace std;

void input_strings(vector<string>& arr)
{
    string temp_string;
    char answer;
    bool flag = true;
    cout << "Введите строку: ";
    cin >> temp_string;
    arr.push_back(temp_string);
    while (flag)
    {
        cout << "Хотите добавить ещё строку? (y/n): ";
        cin >> answer;
        if (answer == 'y')
        {
            cout << "Введите строку: ";
            cin >> temp_string;
            arr.push_back(temp_string);
        }
        else
        {
            flag = false;
        }
    }
}

void output_arr(vector<string> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void put_string(vector<string>& arr, int number_string)
{
    arr.push_back(arr[number_string - 1]);
    // arr.insert(arr.begin() + number_string, string);
}

int main()
{
    int size;
    int number_string;
    vector<string> arr;
    input_strings(arr);
    output_arr(arr);
    cout << "Введите номер строки, которую нужно добавить в конец: ";
    cin >> number_string;
    put_string(arr, number_string);
    output_arr(arr);
    system("pause");
}

