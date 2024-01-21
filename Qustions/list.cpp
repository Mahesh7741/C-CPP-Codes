#include <bits/stdc++.h>
using namespace std;
template <class T>
class F
{
    T a;
    T b;
public:
    F(T x, T y)
    {
        x = a;
        y = b;
    }
    int sum()
    {
        int d = a + b;
        return d;
    }
};
int main()
{
    F<int> h(1, 2);
    int v = h.sum();
    cout << v << " ";
    return 0;
}