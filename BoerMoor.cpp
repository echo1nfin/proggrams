#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 256;

void make_shifts_table(const string& pattern, vector<int>& table)
{
    int pattern_lenght = pattern.length();

    for (int i = 0; i < pattern_lenght; ++i)
    {
        table[pattern[i]] = i;
    }
}

bool search(const string text, const string pattern) {
    int text_lenght = text.length();
    int pattern_lenght = pattern.length();

    vector<int> table(ALPHABET_SIZE, -1);

    make_shifts_table(pattern, table);

    int shift = 0;
    while (shift <= (text_lenght - pattern_lenght))
    {
        int right_index = pattern_lenght - 1;

        while (right_index >= 0 && pattern[right_index] == text[shift + right_index])
        {
            right_index--;
        }

        if (right_index < 0)
        {
            cout << "Паттерн: от " << shift + 1 << " до " << pattern_lenght + shift << " символа включительно" << endl;
            return true;
        } 
        else
        {
            shift += max(1, right_index - table[text[shift + right_index]]);
        }
    }
    cout << "Паттерн не найден" << endl;
    return false;
}

int main()
{
    setlocale(LC_ALL, "ru");
    system("chcp 1251 > Null");
    string text, pattern;
    cout << "Введите строку: ";
    getline(cin, text);
    cout << "Введите что нужно найти: ";
    getline(cin, pattern);
    search(text, pattern);

    system("pause");
    return 0;
}
