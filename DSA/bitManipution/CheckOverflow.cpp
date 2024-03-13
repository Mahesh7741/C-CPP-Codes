#include <bits/stdc++.h>
using namespace std;
int addOvf(int *result, int a, int b)
{
    *result = a + b;
    if (a > 0 && b > 0 && *result < 0)
    {
        return -1;
    }
    if (a < 0 && b < 0 && *result > 0)
    {
        return -1;
    }
    return 0;
}
int main()
{
    int *result=new int[sizeof(int)];
    int a = 2147483640;
    int b = 10;
    cout<< addOvf( result,  a,  b)<<endl;;
    cout << *result << endl;
    return 0;
}