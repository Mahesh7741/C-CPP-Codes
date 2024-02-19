#include<bits/stdc++.h>
using namespace std;


//Method 1: Iterative 


// void bin(long n){
//     long i;
//     cout<<"0";
//     for(i=1<<30;i>0;i=i/2){
//         if((n&i)!=0){
//             cout<<"1";
//         }else{
//             cout<<"0";
//         }
//     }
// }


// int main(){
//     bin(7);
// }

//Method 2: Recursive 

// void bin(unsigned n){
//     if(n>0){
//         bin(n/2);
//     }
//     cout<<n%2;
// }

// int main(){
//     bin(7);
// }

//Method 3: Recursive using bitwise operator

// void bin(unsigned n){
//     if(n>1){
//         bin(n>>1);
//     }
//     cout<<(n&1);

// }

//Best Representation of binary representation
//time complexity 0(1) and space complexity is no

void bin(int num){
    for(int i=31;i>=0;i--){
        int bt=((num>>i)&1);
        cout<<bt;
    }
    cout<<endl;
}

int main(){
    bin(7);
}