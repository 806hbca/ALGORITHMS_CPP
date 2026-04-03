
#include <bits/stdc++.h>

using namespace std;

int minn(int a, int b)
{
    return a < b ? a : b;
}
template<typename T>
void print(T arr)
{
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

int z_func(string str, string p)
{
    str = p + "&" + str;
    vector<int> a(str.size(),0);
    int i= 1, r = 0, l = 0;
    while (i < str.size()-p.size()+1)
    {
        if (i < r)
        {
            a[i] = minn(r - i, a[r - i-1]);
        }
        while (str[a[i] + i] == str[a[i]] && a[i]+i< str.size())
        {
            a[i]++;
        }
        if (i >= r)
        {
            r = i + a[i];
            l = i;
        }
        i++;
    }
    print(str);
    print(a);
    return 1;
}

int main()
{
    string a = "abaorpaba";
    string tmp = "aba";
    z_func(a, tmp);
}

