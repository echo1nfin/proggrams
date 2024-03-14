#include <iostream>
#include <string>

using namespace std;

int main()
{
    system("chcp 1251");
    system("cls");
    string str;
    cin >> str;
    const int LENGHT = size(str);
    int lenght = LENGHT;
    int count = 1;
    while (lenght >= count)
    {
        lenght -= count;
        count++;
    }
    int spaces = LENGHT - lenght;
    int len_current_word = count - 1;
    int syms = LENGHT;
    int symbols_have_passed = 0;
    int count_syms = 0;
    int len_next_word = lenght;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < spaces; j++)
        {
            cout << ' ';
        }
        spaces -= len_current_word;
        for (int j = syms - symbols_have_passed - len_next_word; j < syms - symbols_have_passed; j++)
        {
            cout << str[j];
            count_syms++;
        }
        symbols_have_passed += count_syms;
        count_syms = 0;
        len_next_word = len_current_word;
        len_current_word--;
        cout << endl;
    }

    system("pause");
}