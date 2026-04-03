
#include <bits/stdc++.h>

using namespace std;

template< typename T2>
void print(int * arr, T2 y, int n)
{
    for (int i = 0;i<n;i++)
    {
        cout << arr[i] << "  ";
    }
    cout << y;
}

void choose_sort(int* arr, int first, int d, int n)
{
    bool fl = 0;
    for (int i = first; i < n && !fl; i += d)
    {
        fl = 1;
        for (int j = i + d; j < n; j += d)
        {
            if (arr[j] < arr[j - d])
            {
                int tmp = arr[j];
                arr[j] = arr[j - d];
                arr[j - d] = tmp;
                fl = 0;
            }
        }
    }
    for (int i = first; i < n; i += d)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int mains()
{
    ifstream fin("inp.txt");
    int n;
    fin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        fin >> arr[i];
    }
    int d = n;
    while (d > 0)
    {
        d /= 2;
        for (int i = 0; i < d; i++)
        {
            choose_sort(arr, i, d, n);
        }
        print(arr, "\n\n", n);
    }
    return 1;
}
/*Применяется для набора данных со средним количеством элементов, так как  для малых
работают - простые, а для больших - сложные*/


void Shell(vector<int>& mas)
{
    for (int d = mas.size() / 2; d > 0; d /= 2)
    {
        for (int i = d; i < mas.size(); i++)
        {
            for (int j = i; j >= d && mas[j - d] > mas[j]; j -= d)
            {
                int tmp = mas[j - d];
                mas[j - d] = mas[j];
                mas[j] = tmp;
            }
        }
    }
}

int main()
{
    vector<int> mas = { 6,54,6,7,4,3,2,9,8,0 };
    Shell(mas);
    for (auto a : mas)
    {
        cout << a << "  ";
    }
}