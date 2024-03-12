#include<bits/stdc++.h>
using namespace std;

void FindEven(int arr[],int size){
    int a[size];
    int j=0;
    for(int i=0;i<size;i++){
        if(arr[i]==1){
            continue;
        }
        if((arr[i]&(1))==0)
        {
            a[j]=arr[i];
            j++;
        }
    }
    for(int i=0;i<size;i++){
        cout<<a[i]<<" "<<endl;
    }
}

int main(){
    int arr[10]= {1,2,3,4,5,6,7,8,9,10};
    FindEven(arr,10);
    return 0;
}