#include <iostream>

using namespace std;

void tower_of_hanoi(int num, char source, char dest, char helper)
{
    if (num == 1)
    {
        cout << "������� ������ ���� �� ������� " << source << " �� �������� " << dest << endl;
        cout << "==========================================================" << endl;
        return;
    }
    cout << "�������� ������� � �����������: " << endl << "����� ������: " << num << endl << "��������� ��������: " << source << endl;
    cout << "��������������� ��������: " << helper << endl << "�������� �� ������� ����������: " << dest << endl;
    cout << "==========================================================" << endl;
    tower_of_hanoi(num - 1, source, helper, dest);
    cout << "������� ���� " << num << " �� ������� " << source << " �� �������� " << dest << endl;
    cout << "==========================================================" << endl;
    cout << "�������� ������� � �����������: " << endl << "����� ������: " << num << endl << "��������� ��������: " << source << endl;
    cout << "��������������� ��������: " << helper << endl << "�������� �� ������� ����������: " << dest << endl;
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

