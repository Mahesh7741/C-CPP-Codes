#include<iostream>
using namespace std;


// int main(){
//     int arr[5]={1,2,3,2,1};
//     int n=5;
//     int hash[5]={0};

//     for(int i=0; i<n; i++){
//         hash[arr[i]]+= 1;
//     }
//     for(int i=0; i<n; i++){
//         cout<<i<<"-->"<<" "<<hash[i]<<" "<<endl;
//     }
// }

int main(){
    string str;
    cin>>str;
    int hash[27]={0};
    for(int i=0; i<str.length(); i++){
        hash[str[i]-'a']++;
    }
    for(int i=0; i<str.length(); i++){
        cout<<str[i]<<"-->"<<" "<<hash[i]<<" "<<endl;
    }
}