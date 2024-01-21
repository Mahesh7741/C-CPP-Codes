#include<iostream>
#include <map> 
using namespace std;

int main(){
    int size;
    cout<<"Enter Array Size : "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter Array : "<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    map< int, int>mpp;
    for(int i=0;i<size;i++){
        mpp[arr[i]]++;
    }
    // for(int i=0;i<size;i++){
    //     cout<<arr[i]<<"--->"<<mpp[arr[i]]<<endl;
    // }
    for(auto it:mpp){
        cout<<it.first<<"-->"<<it.second<<endl; 
    }
}