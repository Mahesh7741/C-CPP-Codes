#include<bits/stdc++.h>
using namespace std;

int OddOccurrings(int a[],int size){
    int count = 0;
    for(int i = 0; i < size;i++){
        if(a[i]&1==1){
            count++;
        }
    }
    return count;
}
// int EvenOccurrings(int a[],int size){
//     int count = 0;
//     for(int i = 0; i < size;i++){
//         if((a[i]&1)==0){
//             count++;
//         }
//     }
//     return count;
// }


int main(){
    int arr[] = { 2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2 };
        int size = sizeof(arr) / sizeof(arr[0]);
    cout<<OddOccurrings(arr,size)<<endl;
}