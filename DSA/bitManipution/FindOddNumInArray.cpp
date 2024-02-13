#include<bits/stdc++.h>
using namespace std;

// program to find odd occcuring elements in an array

int findOdd(int arr[],int size){
    int res=0;
    for(int i=0;i<size;i++){
        res^=arr[i];
    }
    return res;
}



int main(){
    int size;
    cout<<"Enter size of array"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter element into array"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<findOdd(arr,size)<<endl;
}
/*
arr[] = {12, 12, 14, 90, 14, 14, 14}

Iteration 1: res ^= arr[0] = 0 ^ 12 = 12
Iteration 2: res ^= arr[1] = 12 ^ 12 = 0
Iteration 3: res ^= arr[2] = 0 ^ 14 = 14
Iteration 4: res ^= arr[3] = 14 ^ 90 = 76
Iteration 5: res ^= arr[4] = 76 ^ 14 = 90
Iteration 6: res ^= arr[5] = 90 ^ 14 = 76
Iteration 7: res ^= arr[6] = 76 ^ 14 = 90

*/