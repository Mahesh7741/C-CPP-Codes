#include <bits/stdc++.h>
using namespace std;

// int smallestPower(int n)
// {
//     int num=n-1;
//     if (n % 2 != 0)
//     {
//          num = (n & (n - 1));
//     }
//     int cont = 0;
//     while (num != 0)
//     {
//         num /= 2;
//         cont++;
//     }
//     return (pow(2, cont));
// }

int smallestPower(int n){
    int a=log2(n);
    if(pow(2,a)==n){
        return n;
    }
    return pow(2,a+1);
}

int main()
{
    cout << smallestPower(32) << endl;
    return 0;
}