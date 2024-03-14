#include <iostream>

using namespace std;

struct Node
{
    char data;
    Node* next = nullptr;
    Node* previous = nullptr;
};

struct List
{
    int size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
};

void add(List*& list, char data)
{
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;

    if (list->head == nullptr)
    {
        list->head = new_node;
        list->tail = new_node;
        list->size++;
        return;
    }

    list->tail->next = new_node;
    list->tail = new_node;
    list->size++;
}

void out(List*& list)
{
    Node* current_node = list->head;
    while (current_node != nullptr && list->size != 0)
    {
        cout << current_node->data << ' ';
        current_node = current_node->next;
    }
    cout << endl;
}

void put(List*& list, int index, char data)
{
    Node* new_node = new Node;
    new_node->data = data;

    if (index == 0)
    {
        new_node->next = list->head;
        list->head = new_node;
        list->size++;
        return;
    }

    if (index == list->size)
    {
        list->tail->next = new_node;
        list->tail = new_node;
        list->size++;
        return;
    }

    Node* current_node = list->head;
    for (int i = 0; i < index - 1; i++)
    {
        current_node = current_node->next;
    }
    Node* next_node = current_node->next;
    current_node->next = new_node;
    new_node->next = next_node;
    list->size++;
}

void pop(List*& list, char key)
{
    Node* current_node = list->head;
    Node* previous_node = nullptr;

    while (current_node != nullptr && current_node->data != key)
    {
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (previous_node == nullptr)
    {
        list->head = current_node->next;
        if (list->head != nullptr)
            list->head->previous = nullptr;
    }
    else
    {
        previous_node->next = current_node->next;
        if (current_node->next != nullptr)
            current_node->next->previous = previous_node;
    }

    if (current_node == list->tail)
        list->tail = previous_node;

    delete current_node;
    list->size--;

}

void del_list(List*& list)
{
    Node* current_node = list->head;
    while (current_node != nullptr)
    {
        Node* next_node = current_node->next;
        delete current_node;
        current_node = next_node;
        list->size--;
    }
    delete current_node;
    delete list;
}

void extra_put(List*& list, int number, int count, char symb)
{
    Node* current_node = list->head;
    for (int i = 0; i < number - 1; i++)
    {
        current_node = current_node->next;
    }
    for (int i = number - 1; i < count + number - 1; i++)
    {
        put(list, i, symb);
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    char key, symb;
    int number, count;
    char arr[] {'0', '1', '2', '3', '4', '5', '6'};
    List* list = new List;

    for (int i = 0; i < sizeof(arr); i++)
    {
        add(list, arr[i]);
    }
    out(list);
    cout << "Введите ключ, который нужно удалить: ";
    cin >> key;
    pop(list, key);
    out(list);
    cout << "Введите номер, перед каким элемментом поставить символы: ";
    cin >> number;
    cout << "Введите количество, символов: ";
    cin >> count;
    cout << "Введите символ: ";
    cin >> symb;
    extra_put(list, number, count, symb);
    out(list);
    del_list(list);
}