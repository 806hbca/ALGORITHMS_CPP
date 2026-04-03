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
bool line_search(int* arr, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            return 1;
        }
    }
    return 0;
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
    print(arr, n);
    int k;
    cin >> k;
    cout << line_search(arr, n, k);
}

