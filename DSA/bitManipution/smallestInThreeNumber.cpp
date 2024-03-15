#include<bits/stdc++.h>
using namespace std;

int smallestNumber(int a, int b,int c) {
    int smallestNo=0;
    while(a&&b&&c){
        a--;
        b--;
        c--;
        smallestNo++;
    }
    return smallestNo;
}

int main(){
    int a=5,b=4,c=12;
    cout<<smallestNumber(a,b,c)<<endl;
    return 0;
}