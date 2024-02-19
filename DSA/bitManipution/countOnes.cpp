#include <bits/stdc++.h>
using namespace std;

void countOnes(int n)
{
    int countOne = 0;
    for(int i=31;i>=0;i--){
        if(((n>>i)&1)==1){
            countOne++;
        }
    }
    cout << countOne << endl;
}

int main()
{
    countOnes(7);
    return 0;
}