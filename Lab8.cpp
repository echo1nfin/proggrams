#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct Student
{
    string name;
    string surname;
    string last_name;
    string birthday;
    string home_adress;
    string rate;

    void giveInfo(string n, string s, string l, string b, string h, string r)
    {
        name = n;
        surname = s;
        last_name = l;
        birthday = b;
        home_adress = h;
        rate = r;
    }
};

void enter_info(Student base[] ,int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        string n, s, l, b, h, r;
        cout << "Введите данные студента" << endl;
        cout << "ФИО, День рождения, Адрес, Рейтинг: ";
        cin >> s >> n >> l >> b >> h >> r;
        base[i].giveInfo(n, s, l, b, h, r);
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    system("chcp 1251");
    system("cls");
    int SIZE;
    cout << "Количество студентов: ";
    cin >> SIZE;
    Student base[SIZE+1];
    int bd[SIZE];
    int k = 0;
    enter_info(base, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (base[i].birthday == base[j].birthday)
            {
                bd[k] = i;
                bd[k+1] = j;
                k += 2;
            }
        }
    }
    string fam;
    int index_fam = -1;
    cout << "Введите фамилию человека, перед которым нужно поставить другого: ";
    cin >> fam;
    for (int i = 0; i < SIZE; i++)
    {
        if (base[i].surname == fam)
        {
            index_fam = i;
        }
    }
    if (index_fam != -1)
    {
        for (int i = SIZE; i > index_fam; i--)
        {
            base[i] = base[i-1];
        }
        string n, s, l, b, h, r;
        cout << "ФИО, День рождения, Адрес, Рейтинг нового студента: ";
        cin >> s >> n >> l >> b >> h >> r;
        base[index_fam].giveInfo(n, s, l, b, h, r);
        for (int i = 0; i < k; i++)
        {
            if (bd[i] >= index_fam)
            {
                bd[i] += 1;
            }
        }
    }
    ofstream output("base.txt");
    for (int i = 0; i < SIZE + 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < k; j++)
        {
            if (i == bd[j])
            {
                flag = false;
            }
        }
        if (flag)
        {
            output << base[i].name << ' ' << base[i].surname << ' ' << base[i].last_name << ' ';
            output << base[i].birthday << ' ' << base[i].home_adress << ' ' << base[i].rate << ' ' << endl;
        }
    }
    output.close();
    system("pause");
}