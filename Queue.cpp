#include <iostream>

using namespace std;

struct Node
{
    char data;
    Node* next = nullptr;
    Node* previous = nullptr;
};

struct Queue
{
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
};

void add(Queue*& queue, char data)
{
    Node* newNode = new Node;
    newNode->data = data;

    if (queue->tail == nullptr)
    {
        queue->head = newNode;
        queue->tail = newNode;
    }
    else
    {
        queue->tail->previous = newNode;
        newNode->next = queue->tail;
        queue->tail = newNode;
    }

    queue->size++;
}

void go_out(Queue*& queue)
{
    Node* current = queue->head;
    queue->head = current->previous;
    queue->head->next = nullptr;
    delete current;
    queue->size--;
}

void pop(Queue*& queue, int value)
{
    char first_head = queue->head->data;
    char temp_data = queue->head->data;

    if (queue->head->data == value)
    {
        go_out(queue);
        queue->size--;
        return;
    }

    while (temp_data != value)
    {
        go_out(queue);
        add(queue, temp_data);
        temp_data = queue->head->data;
    }
    go_out(queue);
    temp_data = queue->head->data;

    while (temp_data != first_head)
    {
        go_out(queue);
        add(queue, temp_data);
        temp_data = queue->head->data;
    }

    queue->size--;
}

void extra_push(Queue*& queue, char symb, int number, int count)
{
    const int SIZE = queue->size;
    char temp_data = queue->head->data;
    for (int i = 0; i < SIZE - number + 2; i++)
    {
        go_out(queue);
        add(queue, temp_data);
        temp_data = queue->head->data;
    }

    for (int i = 0; i < count; i++)
    {
        add(queue, symb);
    }

    temp_data = queue->head->data;
    for (int i = 0; i < number - 1; i++)
    {
        go_out(queue);
        add(queue, temp_data);
        temp_data = queue->head->data;
    }

    queue->size += count;
}

void print_queue(Queue*& queue)
{
    Node* current = queue->tail;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void delete_queue(Queue*& queue)
{
    Node* current = queue->head;

    while (current != nullptr)
    {
        Node* del_node = current;
        current = current->previous;
        delete del_node;
        del_node = nullptr;
        queue->size--;
    }
    delete queue;
}

int main()
{
    char key, symb;
    int number, count;

    Queue* queue = new Queue;

    char arr[] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 10; i++)
    {
        add(queue, arr[i]);
    }
    print_queue(queue);

    cout << "Выберите какой ключ удалить: ";
    cin >> key;
    pop(queue, key);

    print_queue(queue);

    cout << "Перед каким номером вставить элементы: ";
    cin >> number;
    cout << "Какой элемент вставить: ";
    cin >> symb;
    cout << "Сколько вставить элементов: ";
    cin >> count;

    extra_push(queue, symb, number, count);

    print_queue(queue);
    delete_queue(queue);

    return 0;
}
