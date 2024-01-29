#include <iostream>
using namespace std;

int f(int n){
    static int r=0;
    if(n<=0){
        return 1;
    }
    if(n>3){
        r=n;
        return f(n-2)+2;
    }
    return f(n-1)+r;
}

int main()
{
    int n=6;
    cout<<f(6)<<endl;

    return 0;
}