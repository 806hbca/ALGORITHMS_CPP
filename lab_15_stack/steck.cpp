#include <iostream>
#include <fstream>
using namespace std;

struct Stack
{
    int top = -1;
    int n = 100;
    Stack(int t)
    {
        n = t;
    }
    Stack()
    {
        return;
    }
    int* arr = new int[n];

    void push(int a)
    {
        if (top >= n-1)
        {
            cout << "stack over flow\n";
            return;
        }
        top++;
        arr[top] = a;
    }

    void pop()
    {
        top--;
    }

    void print()
    {
        for (int i = top; i>=0; i--)
        {
            cout << arr[i]<<'\t';
        }
        cout << '\n';
    }
    ~Stack()
    {
        delete arr;
    }
};

int main()
{
    ifstream fin("inp.txt");
    Stack myt;
    int n;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        fin >> t;
        myt.push(t);
    }
    myt.print();
    myt.pop();
    myt.pop();
    myt.print();
    myt.push(9999);
    myt.print();
    cout << "Hello World!\n";
}

