#include <iostream>
using namespace std;

void Separator(int arr[], int size)
{
    int odd[100];
    int k = 0, v = 0;
    int even[100];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even[k] = arr[i];
            k++;
        }
        else
        {
            odd[v] = arr[i];
            v++;
        }
    }
    cout<<"Number Even : ";
    for (int i = 0; i < k; i++)
    {
        cout<< even[i] << " ";
    }
    cout<<endl;
    cout<<"Number odd : ";
    for (int i = 0; i < v; i++)
    {
        cout << odd[i] << " ";
    }
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    Separator(arr, size);
}
