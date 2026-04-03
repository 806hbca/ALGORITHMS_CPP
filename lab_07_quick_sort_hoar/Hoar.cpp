#include <bits/stdc++.h>
using namespace std;

int posit(int* arr, int first, int last)
{
    int i = first;
    int j = first;
    int v = arr[last];
    while (i < last)
    {
        if (arr[i] <= v)
        {
            swap(arr[i], arr[j]);
            j++;
        }
        i++;
    }
    swap(arr[j], arr[last]);
    return j;
}

void sort_Hoar(int* arr, int first, int last)
{
    if (first >= last)
    {
        return;
    }
    int j = posit(arr, first, last);
    sort_Hoar(arr, first, j - 1);
    sort_Hoar(arr, j + 1, last);
}

int main()
{
    int arr[] = { 9, 3, 7, 1, 5, 8, 2, 6, 4, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sort_Hoar(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
