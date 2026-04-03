#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("inp.txt");
    int n, mn=1000000,mx=-1000000;
    fin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        fin>>arr[i];
        mn = mn < arr[i] ? mn : arr[i];
        mx = mx > arr[i] ? mx : arr[i];
    }
    int nn = mx - mn + 1;
    int* arr1 = new int[nn] {0};

    for (int i = 0; i < n; i++)
    {
        arr1[arr[i] - mn]++;
    }
    for (int i = 0; i < nn; i++)
    {
        for (int j = 0; j < arr1[i]; j++)
        {
            cout << i + mn<<' ';
        }
    }
    cout << "Hello World!\n";
}

