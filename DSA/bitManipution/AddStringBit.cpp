#include <iostream>
#include <string>
#include <algorithm> // for reverse

using namespace std;

// string addBinaryStrings(string A, string B) {
//     // Reverse the strings for easier processing
//     reverse(A.begin(), A.end());
//     reverse(B.begin(), B.end());
    
//     int carry = 0;
//     string result = "";
    
//     int i = 0;
//     while (i < A.size() || i < B.size() || carry) {
//         int sum = carry;
        
//         if (i < A.size())
//             sum += (A[i] - '0');
        
//         if (i < B.size())
//             sum += (B[i] - '0');
        
//         result += (sum % 2) + '0';
//         carry = sum / 2;
        
//         i++;
//     }
    
//     // Reverse the result string to get the correct order
//     reverse(result.begin(), result.end());
    
//     return result;
// }

// int main() {
//     string A = "1100011";
//     string B = "10";
    
//     cout << "Sum: " << addBinaryStrings(A, B) << endl;
    
//     return 0;
// }


string addStringBit(string A, string B) {
    int i=A.size()-1;
    int j=B.size()-1;
    int carry = 0;
    string ans="";

    while(i>=0||j>=0||carry){
        carry+=((i>=0)?(A[i--]-'0'):(0));
        carry+=((j>=0)?(B[j--]-'0'):(0));
        ans +=char('0'+(carry%2))+ans;
        carry=carry/2;
    }
    
    return ans;
}

int main(){
    string A="11";
    string B="01";
    string result=addStringBit(A, B);
    cout<<result<<endl;
}