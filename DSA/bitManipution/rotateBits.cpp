#include<bits/stdc++.h>
using namespace std;
#define INT_BIT 32

class Rotate{
    public:
          int leftRotate(int n,unsigned int d){
            return (n<<d)|(n>>(INT_BIT-d));
          }
          int rightRotate(int n,unsigned int d){
            return(n>>d)|(n<<(INT_BIT-d));
          }
};

int main(){
    int n=64;
    int d=2;

    Rotate r;
    cout<<r.leftRotate(n,d)<<endl;
    cout<<r.rightRotate(n,d)<<endl;
    return 0;
}