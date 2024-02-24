#include<bits/stdc++.h>
using namespace std;

// bool PowerOfTwo(unsigned int n){
//     int cnt=0;
//     while(n>0){
//         if((n&1)==1){
//             cnt++;
//         }
//         n=n>>1;
//     }
//     if(cnt==1){
//         return true;
//     }
//     return false;
// }

bool PowerOfTwo(unsigned int n){
    if(n<0){
        return false;
    }
    return (n&&(!(n&(n-1))));
}


int main(){
    PowerOfTwo(31)?cout<<"Yes\n":cout<<"No\n";
    PowerOfTwo(32)?cout<<"Yes\n":cout<<"No\n";
    return 0;
}