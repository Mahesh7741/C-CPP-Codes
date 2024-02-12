#include<bits/stdc++.h>
using namespace std;

void nu(int&bit,int pos){
    bit |=(1<<pos);
}

int main(){
    int bit=5,pos=3;
    nu(bit,pos);
    cout<<(int)bit<<endl;
}

/*

Original number (5):  0101
Bit mask (1 << 3):    1000
Bitwise OR operation: 
                      0101
                    | 1000
                    -------
Result (13):         1101

*/
