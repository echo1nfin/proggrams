#include <iostream>

using namespace std;

struct Node
{
    char data;
    Node* next = nullptr;
};

struct Stack
{
    int size = 0;
    Node* head = nullptr;
};

void add(Stack*& stack, char data)
{
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = stack->head;
    stack->head = new_node;
    stack->size++;
}

void out(Stack*& stack)
{
    Node* current_node = stack->head;
    while (current_node != nullptr && stack->size != 0)
    {
        cout << current_node->data << ' ';
        current_node = current_node->next;
    }
    cout << endl;
}

void pop_up(Stack*& stack)
{
    Node* current_node = stack->head;

    stack->head = current_node->next;

    delete current_node;
}

void put(Stack*& stack, int index, char data)
{
    Node* new_node = new Node;
    new_node->data = data;
    Node* current_node = stack->head;

    Stack* new_stack = new Stack;

    int count = 0;
    while (count != index)
    {
        add(new_stack, current_node->data);
        current_node = current_node->next;
        pop_up(stack);
        count++;
    }

    add(stack, data);

    current_node = new_stack->head;

    while (count != 0)
    {
        add(stack, current_node->data);
        current_node = current_node->next;
        pop_up(new_stack);
        count--;
    }

    stack->size++;

    delete new_stack;
    
}

void push(Stack*& stack, char key)
{
    Node* current_node = stack->head;

    Stack* new_stack = new Stack;

    if (stack->head->data == key)
    {
        stack->head = stack->head->next;
        delete current_node;
        return;
    }

    int count = 0;
    while (current_node != nullptr && current_node->data != key)
    {
        add(new_stack, current_node->data);
        current_node = current_node->next;
        pop_up(stack);
        count++;
    }

    pop_up(stack);

    current_node = new_stack->head;

    while (count != 0)
    {
        add(stack, current_node->data);
        current_node = current_node->next;
        pop_up(new_stack);
        count--;
    }

    stack->size++;

    delete new_stack;

}

void extra_put(Stack*& stack, int number, int count, char symb)
{
    Node* current_node = stack->head;
    
    Stack* new_stack = new Stack;

    int element_deleted = 0;

    while (element_deleted != number - 1)
    {
        add(new_stack, current_node->data);
        current_node = current_node->next;
        pop_up(stack);
        element_deleted++;
    }

    for (int i = 0; i < count; i++)
    {
        add(stack, symb);
    }

    current_node = new_stack->head;

    while (element_deleted != 0)
    {
        add(stack, current_node->data);
        current_node = current_node->next;
        pop_up(new_stack);
        element_deleted--;
    }

    delete new_stack;

}

void del_stack(Stack*& stack)
{
    Node* current_node = stack->head;
    while (current_node != nullptr)
    {
        Node* next_node = current_node->next;
        delete current_node;
        stack->size--;
        current_node = next_node;
    }
    delete current_node;
    delete stack;
}

int main()
{
    setlocale(LC_ALL, "ru");
    system("chcp 1251");
    system("cls");
    system("color 1");

    char key, symb;
    int number, count;
    char arr[] {'0', '1', '2', '3', '4', '5', '6'};
    Stack* stack = new Stack;

    for (int i = 0; i < sizeof(arr); i++)
    {
        add(stack, arr[i]);
    }

    out(stack);
    cout << "Введите ключ, который нужно удалить: ";
    cin >> key;
    push(stack, key);
    out(stack);

    cout << "Введите номер, перед которым поставить символы: ";
    cin >> number;
    cout << "Введите количество символов: ";
    cin >> count;
    cout << "Введите символ: ";
    cin >> symb;

    extra_put(stack, number, count, symb);
    out(stack);

    del_stack(stack);

    system("pause");
}