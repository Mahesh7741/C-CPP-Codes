#include<bits/stdc++.h>
using namespace std;

int main(){
    // int i=4, j=5;
    // int result=i&j;  // result 4
    // int result=i|j;  // result 5
    // int result=i^j;  // result 1
    //int result=-(~j);    // result 6
    //cout<<result<<endl;

    // Left shift (<< K)

    // unsigned int num1 =128;
    // bitset<32> bt1 = num1;
    // cout<<bt1<<endl;

    // bitset<32> bt2= num1<<1;
    // cout<<bt2<<endl;

    // bitset<32> bt3= num1<<2;
    // cout<<bt3<<endl;


    //Right shift (>> K)

    unsigned int num2 =128;
    bitset<8> bt1 = num2;
    cout<<bt1<<endl;

    bitset<8>bt2= num2>>1;
    cout<<bt2<<endl;

    bitset<8>bt3=num2>>2;
    cout<<bt3<<endl;
    return 0;
}