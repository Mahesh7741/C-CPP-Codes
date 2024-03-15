#include <bits/stdc++.h>
using namespace std;

unsigned int swapBit(unsigned int n, unsigned int p1, unsigned int p2, unsigned int t)
{
    unsigned int set1 = ((n >> p1) & ((1 << t) - 1));
    unsigned int set2 = ((n >> p2) & ((1 << t) - 1));
    unsigned int XOR = (set1 ^ set2);
    cout << XOR << endl;
    cout << (XOR << p1) << endl;
    cout << (XOR << p2) << endl;
    XOR = (XOR << p1) | (XOR << p2);
    cout << ((XOR << p1) | (XOR << p2)) << endl;
    unsigned int result = n ^ XOR;
    return result;
}

// int swapBit(int x, int p1 , int p2,int n){
//     int bitArray [32]={0};
//     int idx = 31;
//     while(x !=1){
//         bitArray[idx--]=x%2;
//         x=x/2;
//     }
//     bitArray[idx]=1;
//     int updatedp1=31-p1;
//     int updatedp2=31-p2;
//     for(int i=1; i<=n; i++){
//         swap(bitArray[updatedp1],bitArray[updatedp2]);
//         updatedp1--;
//         updatedp2--;
//     }
//     int ans=0;
//     for(int i=31; i>=0; i--){
//         ans=ans+(pow(2,32-i)*bitArray[i]);
//     }
//     return ans;
// }

int main()
{
    cout << swapBit(47, 1, 5, 3) << endl;
    return 0;
}