#include <bits/stdc++.h>

using namespace std;

int key_func(double x)
{
    if (x == 0)
    {
        return 1;
    }
    return (int)log10(abs(x));
}

void print(int** arr, int *ar,int nn)
{
    for (int i = 0; i < nn; i++)
    {
        for (int j = 0; j <= ar[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void print(int* arr, int n)
{
    for (int j = 1; j <= n; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}

void low_sort(int* arr, int n)
{
    //print(arr, n);
    for (int i = 1; i <= n; i++)
    {
        int ml = i;
        for (int j = i; j <= n; j++)
        {
            if (arr[ml] > arr[j])
            {
                ml = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[ml];
        arr[ml] = tmp;
    }
    //print(arr, n);
}

int main()
{
    ifstream fin("inp.txt");
    int n, mn = 1000000, mx = -1000000;
    fin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        fin >> arr[i];
        mn = mn < key_func(arr[i]) ? mn : key_func(arr[i]);
        mx = mx > key_func(arr[i]) ? mx : key_func(arr[i]);
    }
    int nn = mx - mn + 1;
    int* arr1 = new int[nn] {0};
    
    for (int i = 0; i < n; i++)
    {
        arr1[key_func(arr[i]) - mn]++;
    }
    //print(arr1, nn);
    int** arr2 = new int*[nn];
    for (int i = 0; i < nn; i++)
    {
        arr2[i] = new int[arr1[i] + 1] {0};
        arr2[i][0] = 0;

    }
    
    for (int i = 0; i < n; i++)
    {
        int t = key_func(arr[i]) - mn;
        arr2[t][arr2[t][0]+1] = arr[i];
        arr2[t][0]++;
        
    }
    //print(arr2, arr1, nn);
    for (int i = 0; i < nn; i++)
    {
        low_sort(arr2[i], arr2[i][0]);
    }
    print(arr2, arr1, nn);
    for (int i = 1; i < nn; i++)
    {
        int m= arr2[i - 1][0] + arr2[i][0];
        int* arr3 = new int[m+1];
        arr1[i] = m;
        arr3[0] = m;
        int x=1, y=1, k=1;
        int n1 = arr2[i - 1][0], n2 = arr2[i][0];
        while (x <= n1 && y <= n2) {
            if (arr2[i - 1][x] < arr2[i][y])
                arr3[k++] = arr2[i - 1][x++];
            else
                arr3[k++] = arr2[i][y++];
        }

        // Store remaining elements of a
        while (x <= n1)
            arr3[k++] = arr2[i - 1][x++];

        // Store remaining elements of b
        while (y <= n2)
            arr3[k++] = arr2[i][y++];
        //int* arr4 = arr2[i];
        
        //print(arr3, arr3[0] + 1);
        arr2[i] = arr3;
        //delete[] arr4;
        print(arr2, arr1, nn);
    }
    print(arr2[nn - 1], arr2[nn - 1][0]);
}