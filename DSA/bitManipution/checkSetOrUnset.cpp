#include<bits/stdc++.h>
using namespace std;

bool checkSetOrUnset(int& num,int pos){
    bool bit=num&(1<<pos);
    return bit;
}

int main(){
    int num=5   , pos=1;
    int check=checkSetOrUnset(num,pos);
    cout<<check<<endl;
}