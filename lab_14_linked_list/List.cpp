

#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int dat;
    Node* next_ptr;
    void adddate(int a)
    {
        dat = a;
        next_ptr = nullptr;
    }
};

struct List
{
    Node* head = nullptr;
    Node* tail = nullptr;
    void push_back(int a)
    {
        Node* node = new Node;
        node->adddate(a);
        if (head == nullptr) head = node;
        if (tail != nullptr) tail->next_ptr = node;
        tail = node;
    }
};

int main()
{
    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    Node* node = list.head;
    while (node != nullptr)
    {
        cout << node->dat << ' ';
        node = node->next_ptr;
    }
}

