#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

// Function to split the IP address into octets
vector<int> splitIPAddress(string ipAddress) {
    vector<int> result;
    stringstream ss(ipAddress);
    string token;
    
    while (getline(ss, token, '.')) {
        result.push_back(stoi(token));
    }

    return result;
}

// Function to determine if the IP is public, private, or reserved
string getIPAddressType(vector<int>& ipAddress) {
    // Check if the IP falls into reserved ranges
    if (ipAddress[0] == 0 || (ipAddress[0] == 10) || (ipAddress[0] == 100 && ipAddress[1] >= 64 && ipAddress[1] <= 127) ||
        (ipAddress[0] == 127) || (ipAddress[0] == 169 && ipAddress[1] == 254) || (ipAddress[0] == 172 && (ipAddress[1] >= 16 && ipAddress[1] <= 31))) {
        return "Reserved";
    }

    // Check if the IP is in a private range
    if ((ipAddress[0] == 192 && ipAddress[1] == 168) || (ipAddress[0] == 172 && (ipAddress[1] >= 16 && ipAddress[1] <= 31)) || (ipAddress[0] == 10)) {
        return "Private";
    }

    return "Public";
}

// Function to determine the class of the IP address
char getIPAddressClass(vector<int>& ipAddress) {
    if (ipAddress[0] < 128) {
        return 'A';
    } else if (ipAddress[0] < 192) {
        return 'B';
    } else {
        return 'C';
    }
}

// Function to calculate network information for classful addressing
void calculateClassfulInfo(vector<int>& ipAddress) {
    char ipAddressClass = getIPAddressClass(ipAddress);

    cout << "Default Mask: ";

    if (ipAddressClass == 'A') {
        cout << "255.0.0.0" << endl;
        cout << "Block: " << ipAddress[0] << ".0.0.0" << endl;
    } else if (ipAddressClass == 'B') {
        cout << "255.255.0.0" << endl;
        cout << "Block: " << ipAddress[0] << "." << ipAddress[1] << ".0.0" << endl;
    } else if (ipAddressClass == 'C') {
        cout << "255.255.255.0" << endl;
        cout << "Block: " << ipAddress[0] << "." << ipAddress[1] << "." << ipAddress[2] << ".0" << endl;
    }

    cout << "First IP: " << ipAddress[0] << ".";
    if (ipAddressClass == 'A') {
        cout << "0.0.1" << endl;
    } else if (ipAddressClass == 'B') {
        cout << ipAddress[1] << ".0.1" << endl;
    } else if (ipAddressClass == 'C') {
        cout << ipAddress[1] << "." << ipAddress[2] << ".1" << endl;
    }

    cout << "Last IP: " << ipAddress[0] << ".";
    if (ipAddressClass == 'A') {
        cout << "255.255.255" << endl;
    } else if (ipAddressClass == 'B') {
        cout << ipAddress[1] << ".255.255" << endl;
    } else if (ipAddressClass == 'C') {
        cout << ipAddress[1] << "." << ipAddress[2] << ".255" << endl;
    }

    cout << "Network Address: " << ipAddress[0] << ".";
    if (ipAddressClass == 'A') {
        cout << "0.0.0" << endl;
    } else if (ipAddressClass == 'B') {
        cout << ipAddress[1] << ".0.0" << endl;
    } else if (ipAddressClass == 'C') {
        cout << ipAddress[1] << "." << ipAddress[2] << ".0" << endl;
    }
}

// Function to calculate network information for classless addressing
void calculateClasslessInfo(vector<int>& ipAddress, int subnetMask) {
    cout << "/ Value: " << subnetMask << endl;

    // Calculate mask in decimal
    int maskOctets[4] = {0};
    int fullOctets = subnetMask / 8;
    int remainingBits = subnetMask % 8;

    for (int i = 0; i < fullOctets; ++i) {
        maskOctets[i] = 255;
    }

    if (remainingBits > 0) {
        int mask = 0;
        for (int i = 7; i >= 8 - remainingBits; --i) {
            mask |= (1 << i);
        }
        maskOctets[fullOctets] = mask;
    }

    cout << "Mask in Decimal: " << maskOctets[0] << "." << maskOctets[1] << "." << maskOctets[2] << "." << maskOctets[3] << endl;

    // Calculate number of IP addresses in the block
    unsigned int numAddresses = static_cast<unsigned int>(pow(2, 32 - subnetMask));
    cout << "No of IP Addresses in Block: " << numAddresses << endl;

    // Calculate first IP, last IP, and network address
    unsigned int firstIPOctets[4] = {0};
    unsigned int lastIPOctets[4] = {0};
    unsigned int networkAddressOctets[4] = {0};

    for (int i = 0; i < 4; ++i) {
        firstIPOctets[i] = ipAddress[i] & maskOctets[i];
        lastIPOctets[i] = firstIPOctets[i] + numAddresses - 1;
        networkAddressOctets[i] = ipAddress[i] & maskOctets[i];
    }

    // Ensure last IP octets do not exceed 255
    for (int i = 3; i >= 0; --i) {
        if (lastIPOctets[i] > 255) {
            unsigned int carry = lastIPOctets[i] / 256;
            lastIPOctets[i] %= 256;
            if (i > 0)
                lastIPOctets[i - 1] += carry;
        }
    }

    cout << "First IP: " << firstIPOctets[0] << "." << firstIPOctets[1] << "." << firstIPOctets[2] << "." << firstIPOctets[3] << endl;
    cout << "Last IP: " << lastIPOctets[0] << "." << lastIPOctets[1] << "." << lastIPOctets[2] << "." << lastIPOctets[3] << endl;
    cout << "Network Address: " << networkAddressOctets[0] << "." << networkAddressOctets[1] << "." << networkAddressOctets[2] << "." << networkAddressOctets[3] << endl;
}

int main() {
    string ipAddress;
    cout << "Enter The IP Address: ";
    cin >> ipAddress;

    vector<int> ipAddressOctets = splitIPAddress(ipAddress);

    cout << "\nGiven IP is " << getIPAddressType(ipAddressOctets) << endl;
    cout << "This IP Address Belongs to Class: " << getIPAddressClass(ipAddressOctets) << endl;

    // For classful addressing
    cout << "\nFor Classful Addressing:" << endl;
    calculateClassfulInfo(ipAddressOctets);

    // For classless addressing
    int subnetMask;
    cout << "\nFor Classless Addressing:" << endl;
    cout << "Enter the subnet mask value (/ Value): ";
    cin >> subnetMask;
    calculateClasslessInfo(ipAddressOctets, subnetMask);

    return 0;
}
