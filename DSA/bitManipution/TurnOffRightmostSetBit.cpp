#include<bits/stdc++.h>
using namespace std;

int TurnOffRightmostSetBit(unsigned int n){
    return n&(n-1);
}

int main(){
    int num=7;
    int result=TurnOffRightmostSetBit(num);
    cout<<num<<" ---> "<<result<<endl;
    return 0;
}