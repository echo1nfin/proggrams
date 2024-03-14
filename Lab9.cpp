#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функция для подсчета количества цифр в строке
int countDigits(const string word)
{
    int count = 0;
    for (int i = 0; i < size(word); i++)
    {
        if (isdigit(word[i]))
        {
            count++;
        }
    }
    return count;
}

int main() {
    ifstream input("fa.txt"); // Открытие файла F1 для чтения
    ofstream output("fb.txt"); // Открытие файла F2 для записи

    string line;
    int maxDigitWordIndex = -1; // Индекс слова с максимальным количеством цифр
    int maxDigitCount = 0; // Максимальное количество цифр в слове
    int wordIndex = 0;

    while (getline(input, line)) // Построчное чтение файла F1
    {
        bool hasDuplicateWords = false;
        string word;

        // Разбиение строки на слова
        for (int i = 0; i < line.length(); ++i)
        {
            if (line[i] == ' ' || i == line.length() - 1)
            {
                if (i == line.length() - 1 && line[i] != ' ')
                {
                    word += line[i];
                }

                // Проверка наличия двух одинаковых слов
                int found = line.find(word, i  + word.length());

                // npos - find не нашёл слово
                if (found != string::npos)
                {
                    hasDuplicateWords = true;
                }

                // Подсчет цифр в слове
                int digitCount = countDigits(word);
                if (digitCount > maxDigitCount)
                {
                    maxDigitCount = digitCount;
                    maxDigitWordIndex = wordIndex;
                }

                // Переход к следующему слову
                word.clear();
                ++wordIndex;
            }
            else
            {
                word += line[i];
            }
        }

        // Если в строке есть два одинаковых слова, записываем ее в файл F2
        if (hasDuplicateWords)
        {
            output << line << endl;
        }
    }

    // Вывод результата
    if (maxDigitWordIndex != -1)
    {
        cout << "Номер слова с максимальным количеством цифр: " << maxDigitWordIndex + 1 << endl;
    }
    else
    {
        cout << "Файл пуст или не содержит слов!" << endl;
    }

    // Закрытие файлов
    input.close();
    output.close();

    return 0;
}
