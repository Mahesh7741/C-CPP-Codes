#include<bits/stdc++.h>
using namespace std;

void SwapNumber(int a, int b,int c) {
    c=a+b;
    b=a;
    a=c-a;
    cout<<a<<" "<<b<<" "<<endl;
}

int main(){
    int a=2;
    int b=3;
    int c;
    SwapNumber(a,b,c);
}