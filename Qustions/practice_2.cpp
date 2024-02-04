#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c = 4;
    int *b = &c;
    int **a = &b;

    cout << c << " " << &c << endl;
    cout << b << " " << &b << " " << *b << " " << endl;
    cout << a << " " << &a << " " << *a << " " << **a << endl;
}