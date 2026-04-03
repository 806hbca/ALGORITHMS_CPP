
#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;



int count_ob(string str, string& full_str)
{
    int n = str.size();
    reverse(str.begin(), str.end());
    int d[256];
    for (int i = 0; i < 256; i++)
        d[i] = n;
    for (int i = 1; i <n; i++)
    {
        if (d[str[i]]==n)
        {
            d[str[i]] = i;
        }
    }
    
    int count = 0;
    for (int i = n-1; i < full_str.size();)
    {
        if (d[full_str[i]]!=n)
        {
            int t = 0;
            while (t < n && full_str[i - t] == str[t])
            {
                t++;
            }
            if (t == n)
            {
                count++;
            }
        }
        i += d[full_str[i]];
    }
    return count;
}

int main()
{
    string str = "aababa";
    string full_str = "waababaababafh";
    cout<<count_ob(str, full_str);
}
