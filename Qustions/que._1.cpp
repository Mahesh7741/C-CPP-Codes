#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
const int N = 1e4 + 10;
int a[N];
int a1;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a1;
    while (a1--) {

        int b;
        cin >> b;
        char kk_1;
        cin >> kk_1;
        int kk_3 = 0;
        for (int i = 0; i < b - 1; i++) {

            char kk_2;
            cin >> kk_2;
            if (kk_2 == '1') {
                if (kk_3 == 0) {

                    cout << '-';
                    kk_3 = -1;
                }
                else {

                    cout << '+';
                    kk_3 = 0;
                }

            }
            else cout << '+';

        }
        cout << endl;

    }

    return 0;
}
