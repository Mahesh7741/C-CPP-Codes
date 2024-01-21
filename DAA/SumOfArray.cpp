#include<iostream>
using namespace std;
int SumofArray(int arr[],int n){
    if(n<=0){
        return 0;
    }
    return SumofArray(arr,n-1)+arr[n-1];
}
int main(){
    int arr[5]={1,2,3,4,5};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<"Sum of given Array: "<<SumofArray(arr,n)<<endl;
}