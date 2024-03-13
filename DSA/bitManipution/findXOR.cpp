#include<bits/stdc++.h>
using namespace std;

int findXor(int x, int y){
    return ((x&(~(y)))|((~(x))&(y)));
}

int main(){
    int a=2;
    int b=1;
    cout<<findXor(a,b)<<endl;
}