#include<bits/stdc++.h>
using namespace std;


int checkPowerOfTwo(int num){
    return (num &&(! (num &(num-1))));
}

int main(){
    int num=8;
    int result= checkPowerOfTwo(num);
    cout<<result<<endl;
}