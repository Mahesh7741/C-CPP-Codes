#include<bits/stdc++.h>
using namespace std;

int positionOfOneInbit(int num){
    if(num&1){
        return 1;
    }

    num=num^(num&(num-1));
    int pos=0;
    while(num){
        num=num>>1;
        pos++;
    }
    return pos;
}

int main(){
    int num=12;
    int result=positionOfOneInbit(num);
    cout<<result<<endl;

}