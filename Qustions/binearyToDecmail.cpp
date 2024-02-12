// #include <iostream>
// #include <string>

// using namespace std;

// int main() {
//   string binary = "0101"; // The binary number to convert
//   int decimal = stoi(binary, nullptr, 2); // Convert the binary string to an integer using stoi with a base of 2 (indicating binary representation)

//   cout << "The decimal equivalent of " << binary << " is " << decimal << endl;

//   return 0;
// }
#include <iostream>
#include <string>

using namespace std;

int binaryToDecimal(const string& binary) {
    int decimal = 0;

    // Iterate through each character in the binary string
    for (char bit : binary) {
        decimal <<= 1; // Left shift the current value of decimal by 1 bit
        decimal += (bit - '0'); // Add the current bit to decimal (convert char to int)
    }

    return decimal;
}

int main() {
    string binary = "100101"; // The binary number to convert
    int decimal = binaryToDecimal(binary);

    cout << "The decimal equivalent of " << binary << " is " << decimal << endl;

    return 0;
}
