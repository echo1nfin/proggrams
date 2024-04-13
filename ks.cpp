#include <iostream>
#include <string>
using namespace std;

struct Node {
int data;
Node* next;
Node* prev;
};

class List {
private:
int size;
Node* head;
Node* tail;
public:
void pushFront(int data) {
Node* newNode = new Node;
newNode->data = data;
if (head == nullptr) {
this->head = newNode;
this->tail = newNode;
}
else {
head->prev = newNode;
newNode->next = head;
head = newNode;
}
this->size++;
}

void pushBack(int data) {
Node* newNode = new Node;
newNode->data = data;
newNode->next = nullptr;
if (head == nullptr) {
this->head = newNode;
this->tail = newNode;
}
else {
tail->next = newNode;
newNode->prev = tail;
tail = newNode;
}
this->size++;
}
List(int size) {
this->size = size;
if (size > 0) {
Node* node = new Node;
this->head = node;
this->tail = node;
for (int i = 1; i < size; i++) {
Node* newNode = new Node;
tail->next = newNode;
newNode->prev = tail;
tail = newNode;
}
}
else {
this->head = nullptr;
this->tail = nullptr;
}

}


List(int size, int data) {
this->size = size;
if (size > 0) {
Node* node = new Node;
node->data = data;
this->head = node;
this->tail = node;
for (int i = 1; i < size; i++) {
Node* newNode = new Node;
newNode->data = data;
tail->next = newNode;
newNode->prev = tail;
tail = newNode;
}
}
else {
this->head = nullptr;
this->tail = nullptr;
}

}

List(const List& list) {
this->head = nullptr;
this->tail = nullptr;
this->size = 0;

Node* current_node = list.head;
while (current_node != nullptr) {
pushBack(current_node->data);
current_node = current_node->next;
}
}

~List() {
Node* node = head;
while (node != nullptr) {
Node* newNode = node->next;
delete node;
node = newNode;
}
head = nullptr;
}

int popBack() {
int temp = 0;
if (this->tail != nullptr) {
Node* current_node = this->tail;
tail = current_node->prev;
temp = current_node->data;
tail->next = nullptr;
this->size = size - 1;
delete current_node;
}
return temp;
}

int popFront() {
int temp = 0;
if (this->head != nullptr) {
Node* current_node = this->head;
head = current_node->next;
temp = current_node->data;
if (head) {
head->prev = nullptr;
}
delete current_node;
this->size = size - 1;
}
return temp;
}

int front() {
return this->head->data;
}

int back() {
return this->tail->data;
}

bool is_empty() {
return this->size == 0;
}

List& operator =(const List& list) {
cout << "Вызвана операция присваивания: " << endl;
if (this == &list) {
return *this;
}

while (head != nullptr) {
Node* temp = head;
head = head->next;
delete temp;
}
this->size = 0;

Node* current = list.head;
while (current != nullptr) {
pushBack(current->data);
current = current->next;
}
return *this;
}

int operator [] (int index) {
cout << "Вызвана операция поиска по индексу: " << endl;
if (index < this->size && index >= 0) {
Node* current = head;
for (int i = 0; i < index; i++) {
current = current->next;
}
return current->data;
}
else {
cout << "Индекс не найден " << endl;
}
}

int operator () () {
return this->size;
}

friend istream& operator>> (istream& is, const List& list) {
cout << "Вызван оператор перегрузки >>" << endl << endl;
Node* current_node = list.head;
while (current_node != nullptr) {
is >> current_node->data;
current_node = current_node->next;
}
cout << "Ввод закончен" << endl << endl;
return is;

}
friend ostream& operator <<(ostream& os, List& list) {
os << "Вызван оператор перегрузки << " << endl << endl;
Node* current_node = list.head;
while (current_node != nullptr) {
os << current_node->data << " ";
current_node = current_node->next;
}
os << "Вывод закончен" << endl << endl;
return os;

}
};

int main() {
setlocale(LC_ALL, "Rus");
srand(time(NULL));
List l1(10, 5);
cout << l1;
cout << endl << endl;
List l2(10);
cin >> l2;
cout << l2;
return 0;
}