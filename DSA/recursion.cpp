#include <iostream>
using namespace std;

// int f(int n,int k){
//     if(n==0){
//         return 0;
//     }
//     else if(n%2){
//         return f(n/2,2*k)+k;
//     }
//     else{
//         return f(n/2,2*k)-k;
//     }
    
// }

// int main() {
//     int m=f(29,1);
//     cout<<m<<endl;
//     return 0;
// }


//Ans : 27 

// int f(int n){
//     static int r=0;
//     if(n<=0){
//         return 1;
//     }
//     if(n>3){
//         r=n;
//         return f(n-2)+2;
//     }
//     return f(n-2)+r;
// }

// int main(){
//     cout<<f(6)<<endl;
//     return 0;
// }

//Ans : 9 

int print(int n){
    cout<<"\n SGGSIT";
    if((n++ )==0){
        return 1 ;
    }

    print(n);
    n++;
    printf("\n%d",n);
}
int main(){
    cout<<print(-4)<<endl;
}

// Ans : 
/* 
SGGSIT
SGGSIT
SGGSIT
SGGSIT
SGGSIT
1
0
-1
-23
*/