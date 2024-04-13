#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next_node;
    Node* prev_node;
};

class Iterator
{
private:
    friend class List;
    Node* elem;
public:
    Iterator()
    {
        this->elem = nullptr;
    }
    Iterator(const Iterator& iterator)
    {
        this->elem = iterator.elem;
    }
    Iterator& operator = (const Iterator& iterator)
    {
        this->elem = iterator.elem;
        return *this;
    }
    bool operator == (const Iterator& iterator)
    {
        return this->elem == iterator.elem;
    }
    bool operator != (const Iterator& iterator)
    {
        return this->elem != iterator.elem;
    }
    Iterator& operator ++ (int)
    {
        this->elem = this->elem->next_node;
        return *this;
    }
    Iterator& operator -- ()
    {
        this->elem = this->elem->prev_node;
        return *this;
    }
    Iterator operator + (const int number) const
    {
        Iterator temp(*this);
        for (int i = 0; i < number; i++)
            {
                temp.elem = temp.elem->next_node;
            }
        return temp;
    }

    Iterator operator - (const int number) const
    {
        Iterator temp(*this);
        for (int i = 0; i < number; i++)
            {
                temp.elem = temp.elem->prev_node;
            }
            return temp;
    }

    int& operator * ()
    {
        return this->elem->data;
    }
};

class List
{
private:
    int size;
    Node* head;
    Node* tail;
    Iterator begin;
    Iterator end;
public:
    List(int size, int data);
    List(const List& list);
    List(int size);
    ~List();
    Iterator first();
    Iterator last();
    void push_back(int data);
    void push_front(int data);
    int pop_back();
    int pop_front();
    bool is_empty();
    int operator () ();
    List& operator = (const List& list);
    int& operator [] (int index);
    List operator * (List& list);
    friend ostream& operator << (ostream& out, const List& list);
    friend istream& operator >> (istream& in, const List& list);
};

List::List(int size, int data)
{
    this->size = size;
    if (size > 0)
    {
        Node* node = new Node;
        node->data = data;
        this->head = node;
        this->tail = node;
        for (int i = 1; i < size; i++)
        {
            Node* newNode = new Node;
            newNode->data = data;
            tail->next_node = newNode;
            newNode->prev_node = tail;
            tail = newNode;
        }
        tail->next_node = nullptr;
    }
    else
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    this->begin.elem = this->head;
    this->end.elem = this->tail;
}

List::List(int size)
{
    this->size = size;
    if (size > 0)
    {
        Node* node = new Node;
        this->head = node;
        this->tail = node;
        for (int i = 1; i < size; i++)
        {
            Node* newNode = new Node;
            tail->next_node = newNode;
            newNode->prev_node = tail;
            tail = newNode;
        }
        tail->next_node = nullptr;
    }
    else
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    this->begin.elem = this->head;
    this->end.elem = this->tail;
}

List::List(const List& list) {
    this->head= nullptr;
    this->tail = nullptr;
    this->size = 0;
    
    Node* current_node = list.head;
    while (current_node != nullptr) {
        push_back(current_node->data);
        current_node = current_node->next_node;
    }
    this->begin = list.begin;
    this->end = list.end;
}


List::~List() {
    Node* current_node = head;
    while (current_node != nullptr)
    {
        Node* next_node = current_node->next_node;
        delete current_node;
        current_node = next_node;
    }
    head = nullptr;
}

void List::push_back(int data)
{
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next_node = nullptr;
    if (this->head == nullptr)
    {
        this->head = new_node;
        this->tail = new_node;
        this->begin.elem = this->head;
        this->end.elem = this->tail;
    }
    else
    {
        tail->next_node = new_node;
        new_node->prev_node = tail;
        tail = new_node;
    }
    this->size++;
}


void List::push_front(int data)
{
    Node* new_node = new Node;
    new_node->data = data;
    if (this->head == nullptr)
    {
        this->head = new_node;
        this->tail = new_node;
        this->size++;
        this->begin.elem = this->head;
        this->end.elem = this->tail;
    }
    else
    {
        head->prev_node = new_node;
        new_node->next_node = head;
        head = new_node;
        this->size++;
        this->begin.elem = this->head;
    }
}

Iterator List::first()
{
    return this->begin;
}

Iterator List::last()
{
    return this->end;
}

int List::pop_back()
{
    int temp;
    if (this->tail != nullptr)
    {
        Node* current_node = this->tail;
        tail = current_node->prev_node;
        temp = current_node->data;
        tail->next_node = nullptr;
        this->size--;
        this->end.elem = tail;
    }
    return temp;
}

int List::pop_front()
{
    int temp;
    if (this->head != nullptr)
    {
        Node* current_node = this->head;
        head = current_node->next_node;
        temp = current_node->data;
        head->prev_node = nullptr;
        this->size--;
        this->begin.elem = head;
    }
    return temp;
}

bool List::is_empty()
{
    return this->size == 0;
}

List& List::operator = (const List& list)
{
    cout << "Оператор присваивания" << endl;
    if (this == &list) {
        return *this;
    }
    
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next_node;
        delete temp;
    }
    size = 0;
    
    Node* current_node = list.head;
    while (current_node != nullptr)
    {
        push_back(current_node->data);
        current_node = current_node->next_node;
    }
    this->begin = list.begin;
    this->end = list.end;
    return *this;
}


int& List::operator [] (int index)
{
    if (index < this->size && index >= 0)
    {
        Node* current_node = this->head;
        for (int i = 0; i != index; i++)
        {
            current_node = current_node->next_node;
        }
        return current_node->data;
    }
    else
    {
        cerr << "Index out of range";
        exit(0);
    }
}

int List::operator () ()
{
    return this->size;
}

List List::operator* (List& list) {
    int temp_size;
    if (this->size > list.size) {
        temp_size = list.size;
    } else {
        temp_size = this->size;
    }
    List temp(temp_size, 0);
    for (int i = 0; i < temp_size; i++) {
        temp[i] = (*this)[i] * list[i];
    }
    return temp;
}

ostream& operator << (ostream& out, const List& list)
{
    out << endl << "Вывод элементов списка" << endl;
    Node* current_node = list.head;
    while (current_node != nullptr)
    {
        out << current_node->data << ' ';
        current_node = current_node->next_node;
    }
    out << endl << "Вывод элементов завершён" << endl;
    return out;
}

istream& operator >> (istream& in, const List& list)
{
    cout << endl << "Ввод элементов списка" << endl;
    Node* current_node = list.head;
    while (current_node != nullptr)
    {
        in >> current_node->data;
        current_node = current_node->next_node;
    }
    cout << endl << "Ввод элементов завершён" << endl;
    return in;
}



int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    List list1(10);
    for (int i = 0; i < list1(); i++)
    {
        list1[i] = rand()%(100+1) - 50;
    }
    cout << endl << list1 << endl;
    cout << *(list1.first()) << ' ' << *(list1.last());
    List list2(list1); 
    cout << endl << list2 << endl;
    list2.push_back(0);
    list2.pop_front();
    cout << endl << list2 << endl;
    cout << *(list2.first()) << ' ' << *(list2.last());
    List list3(6);
    cin >> list3;
    cout << endl << list3 << endl;
    cout << *(list3.first()) << ' ' << *(list3.last());
    List list4 = list3 * list2;
    cout << endl << list4 << endl;
    cout << *(list4.first()) << ' ' << *(list4.last()) << endl;

    for (Iterator iter = list1.first(); iter != list1.last() + 1; iter++)
    {
        cout << *iter << ' ';
    }
    cout << endl;

    system("pause");
    return 0;
}
