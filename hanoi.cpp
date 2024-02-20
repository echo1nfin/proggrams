#include <iostream>

using namespace std;

void tower_of_hanoi(int num, char source, char dest, char helper)
{
    if (num == 1)
    {
        cout << "Двигаем первый диск со стержня " << source << " на стержень " << dest << endl;
        cout << "==========================================================" << endl;
        return;
    }
    cout << "Вызываем функцию с параметрами: " << endl << "Номер кольца: " << num << endl << "Стартовый стрежень: " << source << endl;
    cout << "Вспомогательный стержень: " << helper << endl << "Стержень на который перемещаем: " << dest << endl;
    cout << "==========================================================" << endl;
    tower_of_hanoi(num - 1, source, helper, dest);
    cout << "Двигаем диск " << num << " со стержня " << source << " на стержень " << dest << endl;
    cout << "==========================================================" << endl;
    cout << "Вызываем функцию с параметрами: " << endl << "Номер кольца: " << num << endl << "Стартовый стрежень: " << source << endl;
    cout << "Вспомогательный стержень: " << helper << endl << "Стержень на который перемещаем: " << dest << endl;
    cout << "==========================================================" << endl;
    tower_of_hanoi(num - 1, helper, dest, source);
}

int main()
{
    setlocale(LC_ALL, "ru");
    system("chcp 1251");
    system("cls");
    int discs;
    cin >> discs;
    tower_of_hanoi(discs, 'A', 'B', 'C');

    system("pause");
}

