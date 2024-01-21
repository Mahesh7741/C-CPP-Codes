#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t, n, m, k, i, j, max_f, max_e;
    cin >> t;
    for (; t--;)
    {
        cin >> n >> m >> k;
        if ((n % k) == 0)
        {
            max_f = n / k;
            max_e = k;
        }
        else
        {
            max_f = n / k + 1;
            max_e = n % k;
        }
        ll a[m];
        for (i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < m; i++)
        {
            if (a[i] == max_f)
            {
                max_e--;
            }
            else if (a[i] > max_f)
            {
                max_e = -1;
                break;
            }
            if (max_e < 0)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
        }
    }
}