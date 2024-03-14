#include <iostream>

using namespace std;


struct Node
{
    int data;
    Node* pointer_to_preview_node = nullptr;
    Node* pointer_to_next_node = nullptr;

};

struct List
{
    Node* head_node = nullptr;
    Node* tail_node = nullptr;
};

void insertItem(List& list, const int& data, const int& index = 0)
{
    Node* new_node = new Node;
    new_node->data = data;

    if (list.head_node == nullptr)
    {
        list.head_node = new_node;
        list.tail_node = new_node;
        return;
    }

    int counter = 0;
    Node* current_node = list.head_node;
    while (counter != index)
    {
        current_node = current_node->pointer_to_next_node;
        counter++;
    }

    new_node->pointer_to_preview_node = current_node;
    if (current_node->pointer_to_next_node != nullptr)
    {
        new_node->pointer_to_next_node = current_node->pointer_to_next_node;
        current_node->pointer_to_next_node->pointer_to_preview_node = new_node;
    }
    current_node->pointer_to_next_node = new_node;
    list.tail_node = new_node;

}

void del(List& list, int len)
{
    Node* current_node = list.tail_node->pointer_to_preview_node;

    for (int i = 0; i < len; i++)
    {
        Node* del_node = current_node->pointer_to_next_node;
        delete del_node;
        current_node->pointer_to_next_node = nullptr;
        current_node = current_node->pointer_to_preview_node;
    }
    delete &list;
}

int main()
{
    List list1, list2;

    for (int i = 0; i!= 7; i++)
    {
        insertItem(list1, i*i);
        
    }

    for (int i = 0; i != 7; i++)
    {
        insertItem(list2, i*i, i - 1);
    }

    del(list1, 7);
    del(list2, 7);
}