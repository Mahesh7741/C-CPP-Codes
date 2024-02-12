#include<bits/stdc++.h>
using namespace std;

void toggle(int&num,int pos){
    num ^=(1<<pos);
}

int main(){
    int num=4,pos=1;
    toggle(num,pos);
    cout<<(int)(num)<<endl;
}