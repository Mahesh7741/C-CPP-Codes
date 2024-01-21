#include<iostream>
#include<climits>
using namespace std;
void MinAndMax(int arr[], int n, int &minimum, int &maximum) {
    if(n <= 0) {
        return;
    }
    if(arr[n-1] > maximum) {
        maximum = arr[n-1];
    }
    if(arr[n-1] < minimum) {
        minimum = arr[n-1];
    }
    MinAndMax(arr, n-1, minimum, maximum);
}
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int minimum = INT_MAX; 
    int maximum = INT_MIN; 
    MinAndMax(arr, n, minimum, maximum);
    cout << "Minimum: " << minimum << endl;
    cout << "Maximum: " << maximum << endl;
    return 0;
}
