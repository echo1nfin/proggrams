#include <iostream>
#include <math.h>
#include <string>
#include <time.h>

using namespace std;

const int M = 5;
const double A = sqrt(6)/6;
int collision_counter = 0;

const string SURNAMES[] = {
    "Иванов", "Петров", "Сидоров", "Белов", "Волков",
    "Зайцев", "Михайлов", "Кузнецов", "Соколов", "Васильев"
};

const string NAMES[] = {
    "Иван", "Олег", "Дмитрий", "Антон", "Сергей",
    "Виктор", "Николай", "Пётр", "Кирилл", "Виталий"
};

const string PATRONYMICS[] = {
    "Вячеславович", "Васильевич", "Иванович", "Денисович", "Кириллович",
    "Константинович", "Антонович", "Петров", "Игоревич", "Романович"
};

struct Node
{
    string key = "";
    string value = "";
    Node* next = nullptr;
    Node* previous = nullptr;
};

struct Hash_table
{
    Node* table[M] {nullptr};
};

double mod1(double k)
{
    int int_part = k;
    return k - int_part;
}

int get_hash(string line)
{
    long long number = 0;
    for (int i = 0; i < line.size(); i++)
    {
        number += (long long)(abs(pow(line[i], 2) + line[i]*pow(A, i)));
    }
    return M * mod1(number*A);
}

bool add(Hash_table*& table, string key, string elem)
{
    Node* new_node = new Node;
    new_node->key = key;
    new_node->value = elem;
    int hash = get_hash(key);
    if (table->table[hash] == nullptr)
    {
        table->table[hash] = new_node;
        return true;
    }
    else
    {
        Node* current_node = table->table[hash];
        while (current_node->next != nullptr)
        {
            current_node = current_node->next;
        }
        current_node->next = new_node;
        new_node->previous = current_node;
        collision_counter++;
        return true;
    }
    return false;
}

bool remove_by_key(Hash_table*& table, string key)
{
    int hash = get_hash(key);
    Node* current_node = table->table[hash];
    while (current_node != nullptr)
    {
        if (current_node->key == key)
        {
            if (current_node->previous != nullptr)
            {
                current_node->previous->next = current_node->next;
            }
            else
            {
                table->table[hash] = current_node->next;
            }
            if (current_node->next != nullptr)
            {
                current_node->next->previous = current_node->previous;
            }
            delete current_node;
            return true;
        }
        current_node = current_node->next;
    }
    return false;
}

bool remove_by_value(Hash_table*& table, string value)
{
    for (int i = 0; i < M; i++)
    {
        Node* current_node = table->table[i];
        while (current_node != nullptr)
        {
            if (current_node->value == value)
            {
                if (current_node->previous != nullptr)
                {
                    current_node->previous->next = current_node->next;
                }
                else
                {
                    table->table[i] = current_node->next;
                }
                if (current_node->next != nullptr)
                {
                    current_node->next->previous = current_node->previous;
                }
                delete current_node;
                return true;
            }
            current_node = current_node->next;
        }
    }
    return false;
}

string get(Hash_table* table, string key)
{
    int hash = get_hash(key);
    Node* current_node = table->table[hash];
    while (current_node != nullptr)
    {
        if (current_node->key == key)
        {
            return current_node->value;
        }
        current_node = current_node->next;
    }
    return "None";
}

void print(Hash_table* table)
{
    for (int i = 0; i < M; i++)
    {
        Node* current_node = table->table[i];
        while (current_node != nullptr)
        {
            cout << '[' << current_node->key << ':' << current_node->value << "] \n";
            current_node = current_node->next;
        }
        cout << "[                                                                                  ]\n";

    }
    cout << endl;
}

string random_fullname()
{
    return SURNAMES[rand()%10] + ' ' + NAMES[rand()%10] + ' ' + PATRONYMICS[rand()%10];
}

string correct_string(int number, int lenght)
{
    string str_number = to_string(number);
    while (str_number.size() < lenght)
    {
        str_number = '0' + str_number;
    }
    while (str_number.size() > lenght)
    {
        str_number.erase(0, 1);
    }
    return str_number;
}

string birthday_date(int days, int month, int year)
{
    return correct_string(rand()%days + 1, 2) + ' ' + 
           correct_string(month, 2) + ' ' + 
           to_string(year);
}

string random_birthday()
{
    int rand_month = rand()%12 + 1;
    int rand_year = rand()%10000;

    if (rand_year % 4 == 0)
    {
        if (rand_month == 2)
        {
            return birthday_date(29, rand_month, rand_year);
        }
    }
    if (rand_month == 2)
    {
        return birthday_date(28, rand_month, rand_year);
    }
    else if (rand_month % 2 == 0)
    {
        return birthday_date(31, rand_month, rand_year);
    }
    else
    {
        return birthday_date(30, rand_month, rand_year);
    }
}

string random_password_data()
{
    return correct_string(rand()%10000, 4) + ' ' + correct_string(rand()%1000000 * 100 + rand(), 6);
}

Node* random_human(Hash_table* table)
{
    bool table_empty = true;
    for (int i = 0; i < M && table_empty; ++i)
    {
        if (table->table[i] != nullptr)
        {
            table_empty = false;
        }
    }
    if (table_empty)
    {
        cerr << "Ошибка: таблица пуста" << endl;
        exit(1);
    }

    int index;
    Node* random_human;
    do
    {
        index = rand() % M;
        random_human = table->table[index];
    }
    while (random_human == nullptr);

    return random_human;
}

int main()
{
    system("chcp 1251 && cls");
    srand(time(NULL));
    Hash_table* hash_table = new Hash_table;
    for (int i = 0; i < M; i++)
    {
        string birthday = random_birthday();
        string human_data = random_fullname() + " | " + birthday + " | " + random_password_data();
        add(hash_table, birthday, human_data);
    }
    cout << "Хэш-таблица: \n";
    print(hash_table);

    string key_to_remove = random_human(hash_table)->key;
    cout << "************************************************************************************\n";
    cout << "Удаление по ключу: '" << key_to_remove << "': \n";
    cout << "************************************************************************************\n";
    remove_by_key(hash_table, key_to_remove);
    print(hash_table);

    string value_to_remove = random_human(hash_table)->value;
    cout << "************************************************************************************\n";
    cout << "Удаление по значению: '" << value_to_remove << "': \n";
    cout << "************************************************************************************\n";
    remove_by_value(hash_table, value_to_remove);
    print(hash_table);

    string key_to_get = random_human(hash_table)->key;
    cout << "************************************************************************************\n";
    cout << "Получение по ключу: '" << key_to_get << "': \n";
    cout << "************************************************************************************\n";
    cout << get(hash_table, key_to_get) << endl;

    cout << "Число коллизий: " << collision_counter << endl;

    system("pause");
    return 0;
}