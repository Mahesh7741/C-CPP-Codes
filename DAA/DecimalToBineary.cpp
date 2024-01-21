//Mahesh Savant 
#include <iostream>
using namespace std;
void DB(int decimalNo, char binaryResult[], int &index)
{
    if (decimalNo == 0)
    {
        binaryResult[index] = '\0';
        return;
    }
    binaryResult[index++] = (decimalNo % 2) + '0';
    DB(decimalNo / 2, binaryResult, index);
}
int main()
{
    int decimalNo;
    cout << "Enter a decimal number: ";
    cin >> decimalNo;
    char binaryResult[32];
    int index = 0;
    DB(decimalNo, binaryResult, index);
    cout << "The binary representation of " << decimalNo << " is: ";
    for (int i = index - 1; i >= 0; --i)
    {
        cout << binaryResult[i];
    }
    cout << endl;
    return 0;
}
