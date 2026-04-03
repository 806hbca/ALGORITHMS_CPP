#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int count_ob(string str, string& full_str)
{

    vector<int> mas(str.size(), 0);
    int n = str.size();
    int j=0;
    for (int i = 1; i < n; i++)
    {
        if (str[j] == str[i])
        {
            mas[i] = mas[i - 1] + 1;
            j++;
        }
        else
        {
            j = mas[i - 1];
        }
    }
    for (auto i : mas)
    {
        cout << i << "  ";
    }
    cout << endl;
    j = 0;
    int count = 0;
    for (int i = 0; i < full_str.size(); i++)
    {
        if (str[j] == full_str[i])
        {
            j++;
            if (j == n-1)
            {
                count++;
                j = 0;
            }
        }
        else if(j!=0)
        {
            j = mas[j - 1];
        }
        
        
    }

    return count;
}

int main()
{
    string str = "abcabca";
    string full_str = "waababcabcabcabcabafh";
    cout<<count_ob(str, full_str);
}
