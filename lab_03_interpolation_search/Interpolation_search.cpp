
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
int interpolation_search(int* arr, int l, int r, int k)
{
    int t = 0;
    if (r < l)
    {
        return -1;
    }
    int pos;
    while (r >= l)
    {
        pos = l + (k - arr[l]) * (r - l) / (arr[r] - arr[l]);
        t++;
        if (arr[pos] == k)
        {
            cout << t << "\n";
            return pos;
        }
        if (arr[pos] < k) l = pos;
        if (arr[pos] > k) r = pos;
        
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
    print(arr, n);
    int k;
    cin >> k;
    cout << interpolation_search(arr, 0, n - 1, k);
}

