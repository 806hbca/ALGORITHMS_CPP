

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

struct Queue
{
    int size;
    Node* head = nullptr;
    Node* tail = nullptr;

    int get()
    {
        int ans = head->dat;
        Node* node = head;
        head = head->next_ptr;
        delete node;
        size--;
        return ans;
    }
    void put(int a)
    {
        Node* node = new Node;
        node->adddate(a);
        if (head == nullptr)
        {
            head = node;
            size = 1;
        }
        if (tail != nullptr)
        {
            tail->next_ptr = node;
            size++;
        }
        tail = node;
    }
    void strange_remove(int t)
    {
        for (int i = 0; i < size; i++)
        {
            if (head->dat == t)
            {
                get();
            }
            else
            {
                put(head->dat);
                get();
            }
        }
    }
    void remove(int t)
    {
        int k = 0;
        for (int i = 0; i < size+k; i++)
        {
            if (head->dat == t)
            {
                get();
                k++;
            }
            else
            {
                put(head->dat);
                get();
            }
        }
        
    }
    void print()
    {
        Node* node = head;
        while (node != nullptr)
        {
            cout << node->dat << ' ';
            node = node->next_ptr;
        }
        cout << '\n';
    }
    
};

int main()
{
    Queue q;
    q.put(1);
    q.put(2);
    q.put(3);
    q.put(3);
    q.put(3);
    q.put(4);
    q.put(3);
    q.put(5);
    q.print();
    q.remove(3);
    q.print();
}

