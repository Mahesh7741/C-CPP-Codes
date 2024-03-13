#include<bits/stdc++.h>
using namespace std;

// bool TwoNumberEqual(int a, int b){
//     if(a^b != 0) return false;
//     return true;

// }


bool TwoNumberEqual(int a, int b) {
    int xorResult = a ^ b;
    return !xorResult; 
}

int main() {
    int a = 2;
    int b = 2;
    cout << TwoNumberEqual(a, b) << endl;
    return 0;
}