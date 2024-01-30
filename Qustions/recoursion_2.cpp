#include <iostream>
using namespace std;

int print(int n) {
    cout << "\n SGGSIT";
    if ((n++) == 0) {
        return 1;
    }

    print(n);
    n++;
    printf("\n%d", n);
}

int main() {
    cout << print(-4) << endl;
}
