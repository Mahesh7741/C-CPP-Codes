#include<bits/stdc++.h>
using namespace std;

void unset(int&num,int pos){
    num &=(~(1<<pos));
}

int main(){
    int num=7,pos=1;
    unset(num,pos);
    cout<<(int)(num)<<endl;
}