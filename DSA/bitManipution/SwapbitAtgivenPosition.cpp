#include <bits/stdc++.h>
using namespace std;

unsigned int swapBit(unsigned int n, unsigned int p1, unsigned int p2, unsigned int t)
{
    unsigned int set1 = ((n >> p1) & ((1 << t) - 1));
    unsigned int set2 = ((n >> p2) & ((1 << t) - 1));
    unsigned int XOR = (set1 ^ set2);
    XOR = (XOR << p1) | (XOR << p2);
    unsigned int result = n ^ XOR;
    return result;
}

int main()
{
    cout << swapBit(28, 0, 3, 2) << endl;
    return 0;
}