// You are given an array of size N having no duplicate elements. The array can be categorized into the following:
// 1.  Ascending
// 2.  Descending
// 3.  Descending Rotated
// 4.  Ascending Rotated
// Your task is to return which type of array it is and the maximum element of that array.

//  Input :
// N = 5
// A[] = { 2, 1, 5, 4, 3}
// Output :
// 5 3
// Explanation:
// Descending rotated with maximum
// element 5

// Example 2:

// Input :
// N = 5
// A[] = { 3, 4, 5, 1, 2}
// Output :
// 5 4
// Explanation:
// Ascending rotated with maximum element 5

#include <iostream>
using namespace std;

int findAD(int arr[], int n)
{
    int type;
    int first = arr[0] - arr[1];
    int last = arr[0] - arr[n - 1];
    if ((arr[0] - arr[1] >= 0) && (arr[n - 1] - arr[0] >= 0))
    {
        // cout << n << " 3" << endl;
        type = 3;
    }
    else if (first > last)
    {
        // cout << n << " 1" << endl;
        type = 1;
    }
    else if ((arr[0] - arr[1] < 0) && (arr[n - 1] - arr[0] < 0))
    {
        // cout << n << " 4" << endl;
        type = 4;
    }
    else
    {
        // cout << n << " 2" << endl;
        type = 2;
    }
    return type;
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << n<<" "<< findAD(arr, n) << endl;
    ;

    return 0;
}
