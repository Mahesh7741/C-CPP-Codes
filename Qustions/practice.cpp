#include<bits/stdc++.h>
using namespace std;

int sum(int a)
{
    if(a>0)
        return a +sum(a-1);
    else
        return 0;
}



int main()
{
   cout<<sum(10);
    
}