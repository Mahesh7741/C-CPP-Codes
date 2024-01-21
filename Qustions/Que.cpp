#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout << "Enter the string"
         << " ";
    cin >> s;
    int one = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (i == 0)
        {
            one++;
        }
        else
        {
            if (s[i] == '1')
            {
                one++;
                if (one % 2 == 0)
                {
                    cout << "-";
                }
                else
                {
                    cout << "+";
                }
            }
            else
            {
                cout << "+";
            }
        }
    }
}