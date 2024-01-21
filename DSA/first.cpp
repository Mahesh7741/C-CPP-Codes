#include <iostream>
using namespace std;

bool check(int size, int x, int a[])
{
    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = (i + 1); j < size; j++)
        {
            if (a[i] + a[j] == x)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int A[] =  {1, -2, 1, 0, 5};
    int x = 0;
    int size = sizeof(A) / sizeof(A[0]);
    if (check(size, x, A))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}