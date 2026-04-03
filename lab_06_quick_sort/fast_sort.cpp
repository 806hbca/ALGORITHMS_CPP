#include <iostream>
#include <fstream>
using namespace std;


template< typename T2>
void print(int* arr, T2 y, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << y;
}
void qeuk_sort(int* arr, int first, int last, int n)
{
    if (first == last)
    {
        return;
    }
    int i = first;
    int j = last;
    int v = arr[(i + j) / 2];
    while (i < j)
    {
        while (arr[i] < v)
        {
            i++;
        }
        while (arr[j] > v)
        {
            j--;
        }
        if (i < j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    print(arr, '\n', n);
    qeuk_sort(arr, first, j, n);
    qeuk_sort(arr, j+1, last, n);
}

int main()
{
    ifstream fin("inp.txt");
    int n;
    fin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        fin >> arr[i];
    }
    qeuk_sort(arr, 0, n - 1, n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<' ';
    }
}

