#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cout << "Enter String: ";
    getline(cin, str);
    map<char, int> mpp; 
    for (int i = 0; i < str.size(); i++)
    {
        mpp[str[i]]++;
    }
    for (auto it : mpp)
    {
        cout << it.first << "-->" << it.second << endl;
    }
    return 0; 
}
