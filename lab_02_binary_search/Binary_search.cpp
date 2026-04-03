
#include <iostream>
#include <fstream>

using namespace std;

void print(int* arr, int n)
{
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}

void marge(int* arr, int left, int mid, int right)
{
    int n = right - left + 1;
    int* arr1 = new int[n];
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
        {
            arr1[k++] = arr[i++];
        }
        else
        {
            arr1[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        arr1[k++] = arr[i++];
    }
    while (j <= right)
    {
        arr1[k++] = arr[j++];
    }
    for (int i = left; i <= right; i++)
    {
        arr[i] = arr1[i - left];
    }
}

void marge_sort(int* arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int midd = left + (right - left) / 2;
    marge_sort(arr, left, midd);
    marge_sort(arr, midd + 1, right);
    marge(arr, left, midd, right);
}

int bin_search(int* arr, int l, int r, int k)
{
    int t = 0;
    if (l >= r)
    {
        return -1;
    }
    while (r >= l)
    {
        int mid = (r + l) / 2;
        t++;
        if (arr[mid] == k)
        {
            cout << t << "\n";
            return mid;
        }
        if (arr[mid] < k) l = mid + 1;
        if (arr[mid] > k) r = mid - 1;
    }
    return -1;
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
    marge_sort(arr, 0, n - 1);
    print(arr, n);
    int k;
    cin >> k;
    cout << bin_search(arr, 0, n - 1,k);

}