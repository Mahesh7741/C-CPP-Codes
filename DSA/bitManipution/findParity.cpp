#include <bits/stdc++.h>
using namespace std;

string findPrity(int n){
    int cnt=0;
    while(n){
        n=n&(n-1);
        cnt++;
    }
    if(cnt&1==0) return {"even"};
    return {"odd"};

}

int main(){
    int n=7;
    cout<<findPrity(n)<<endl;
    return 0;
}