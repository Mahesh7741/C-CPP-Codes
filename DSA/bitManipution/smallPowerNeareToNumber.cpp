#include <bits/stdc++.h>
using namespace std;

int smallestPower(int n)
{
    int num=n-1;
    if (n % 2 != 0)
    {
         num = (n & (n - 1));
    }
    int cont = 0;
    while (num != 0)
    {
        num /= 2;
        cont++;
    }
    return (pow(2, cont));
}

int main()
{
    cout << smallestPower(32) << endl;
    return 0;
}