#include <iostream>

using namespace std;

void tower_of_hanoi(int num, char source, char dest, char helper)
{
    if (num == 1)
    {
        cout << " Двигаем первый диск со стержня " << source << " на стержень " << dest << endl;
        return;
    }
    tower_of_hanoi(num - 1, source, helper, dest);
    cout << " Двигаем диск " << num << " со стержня " << source << " на стержень " << dest << endl;
    tower_of_hanoi(num - 1, helper, dest, source);
}

int main()
{
    setlocale(LC_ALL, "ru");
    int discs;
    cin >> discs;
    tower_of_hanoi(discs, 'A', 'B', 'C');

    system("pause");
}
