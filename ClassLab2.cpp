#include <iostream>
#include <string>

using namespace std;

class Pay
{
private:
    string fullname;
    double salary;
    int bonus;
public:
    Pay()
    {
        this->fullname = "None";
        this->salary = 0.0;
        this->bonus = 0;
        cout << "Default constructor" << endl;
    }
    Pay(string fullname, double salary, int bonus)
    {
        this->fullname = fullname;
        this->salary = salary;
        this->bonus = bonus;
        cout << "Parametrs constructor" << endl;
    }
    Pay(Pay* pay)
    {
        this->fullname = pay->fullname;
        this->salary = pay->salary;
        this->bonus = pay->bonus;
        cout << "Copy object constructor" << endl;
    }
    ~Pay()
    {
        cout << "Destructor" << endl;
    }

    string get_fullname()
    {
        return this->fullname;
    }
    void set_fullname(string new_fullname)
    {
        this->fullname = new_fullname;
    }

    double get_salary()
    {
        return this->salary;
    }
    void set_salary(double new_salary)
    {
        this->salary = new_salary;
    }

    int get_bonus()
    {
        return this->bonus;
    }
    void set_bonus(int new_bonus)
    {
        this->bonus = new_bonus;
    }

    void print_info()
    {
        cout << "ФИО: " << this->fullname << '\n' << 
                "Оклад: " << this->salary << '\n' << 
                "Премия: " << this->bonus <<  '%' << endl;
    }
};

Pay make_pay()
{
    string fullname;
    double salary;
    int bonus;
    cout << "Введите ФИО: ";
    getline(cin, fullname);
    cout << "Введите Оклад: ";
    cin >> salary;
    cout << "Введите премию в процентах: ";
    cin >> bonus;
    Pay pay(fullname, salary, bonus);
    return pay;
}

int main()
{
    Pay p1;
    p1.print_info();
    Pay p2("Иванов Иван Иванович", 3264.2, 15);
    p2.print_info();
    Pay p3;
    p3.set_fullname("Кириллов Кирилл Кириллович");
    p3.set_salary(124700);
    p3.set_bonus(40);
    cout << "ФИО: " << p3.get_fullname() << '\n' << 
            "Оклад: " << p3.get_salary() << '\n' << 
            "Премия: " << p3.get_bonus() <<  '%' << endl;

    Pay p4 = make_pay();
    p4.print_info();
    return 0;
}