#include <bits/stdc++.h>
using namespace std;
int isPowerOfTwo(int n){
    return (!(n&&(n&(n-1))));
}
// int PositionOfSetBit(int n)
// {
//     if(!isPowerOfTwo(n)){
//         return -1;
//     }
//     int pos=0;
//     int count = 0;
//     while (n)
//     {
//         count = n & 1;
//         n = n >> 1;
//         pos++;
//     }
//     if (count % 2 == 0)
//     {
//         return -1;
//     }
//     return pos;
// }

int PositionOfSetBit(int n){
    if(!isPowerOfTwo(n)){
        return -1;
    }
    
}


int main()
{
    int num = 4;
    int result = PositionOfSetBit(num);
    cout << result << endl;
    return 0;
}
