#include<iostream>
using namespace std;

int main() {
    string str;
    cin >> str;

    int hash[256] = {0};
    for (int i = 0; i < str.size(); i++) {
        hash[str[i] - 'a'] += 1;
    }
    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << "--->" << hash[str[i] - 'a'] << endl;
    }

    return 0;
}
