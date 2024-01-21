#include <bits/stdc++.h>
using namespace std;

template <class t1>
class add
{
    t1 a;
    t1 b;

public:
    add(t1 x, t1 y)
    {
       a= x;
       b= y;
    }
    int  sum()
    {
        t1 sums = a + b;
        return sums;
    }
};
int main()
{
    add<int  > mahesh (50,50);
    int k=mahesh.sum();
    cout<<k;
    return 0;
}

