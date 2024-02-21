#include <bits/stdc++.h>
using namespace std;

// void countOnes(int n)
// {
//     int countOne = 0;
//     for(int i=31;i>=0;i--){
//         if(((n>>i)&1)==1){
//             countOne++;
//         }
//     }
//     cout << countOne << endl;
// }

// int main()
// {
//     countOnes(7);
//     return 0;
// }

//Brian Kernighan's Algorithms


int Brian(int n){
    int count = 0;
    while(n!=0){
        n=n&(n-1);
        count++;
    }
    return count;
}

int main(){
    int num = 1;
    int result=Brian(num);
    cout<<result<<endl;
    return 0;
}