#include<bits/stdc++.h>
using namespace std;

int modulusOfBits(unsigned int n,unsigned int d){
    return n&(d-1);
}

int main(){
    int num=6;
    int d=4;
    cout<<modulusOfBits(num,d)<<endl;
}