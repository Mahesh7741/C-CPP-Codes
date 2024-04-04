#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int p, int r)
{
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] <= x)
        {
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int main()
{
    int arr[5] = {2, 4, 5, 1, 3};
    quickSort(arr, 0, 4); 
    for (int i = 0; i < 5; i++) 
    {
        cout << arr[i] << " ";
    }
    return 0;
}
