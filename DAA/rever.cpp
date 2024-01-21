#include<iostream>
using namespace std;
void R(string s , int l,int i){
    if (l == i) {
        return;
    }
    cout<<s[l-i-1];
    R(s,l,i+1);
}
int main(){
    string s ;
    cout<<"Enter a String : "<<endl;
    getline(cin,s);
    int l=s.length();
    int i=0;
    cout<<"After : " <<endl;
    R(s,l,i);
}


