#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Node structure for the Huffman tree
struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode *left, *right;

    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Comparison function for priority queue
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

// Function to build Huffman tree and return the root
HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& freqMap) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

    // Create leaf nodes and push them into the min heap
    for (const auto& pair : freqMap) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    // Build the Huffman tree
    while (minHeap.size() != 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();

        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* parent = new HuffmanNode('$', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        minHeap.push(parent);
    }

    return minHeap.top();
}

// Function to generate Huffman codes for each character
void generateHuffmanCodes(HuffmanNode* root, const string& code, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr)
        return;

    if (root->data != '$') {
        huffmanCodes[root->data] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// Function to encode a given string using Huffman codes
string encode(const string& str, const unordered_map<char, string>& huffmanCodes) {
    string encodedString;
    for (char c : str) {
        encodedString += huffmanCodes.at(c);
    }
    return encodedString;
}

// Function to decode a given string using Huffman codes
string decode(const string& encodedString, HuffmanNode* root) {
    string decodedString;
    HuffmanNode* curr = root;
    for (char bit : encodedString) {
        if (bit == '0') {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
        if (curr->data != '$') {
            decodedString += curr->data;
            curr = root;
        }
    }
    return decodedString;
}

int main() {
    string input = "aabbbccdeeeeeff";
    unordered_map<char, int> freqMap;

    // Count frequencies of characters in the input string
    for (char c : input) {
        freqMap[c]++;
    }

    // Build Huffman tree
    HuffmanNode* root = buildHuffmanTree(freqMap);

    // Generate Huffman codes
    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Encode the input string
    string encodedString = encode(input, huffmanCodes);
    cout << "Encoded string: " << encodedString << endl;

    // Decode the encoded string
    string decodedString = decode(encodedString, root);
    cout << "Decoded string: " << decodedString << endl;

    return 0;
}
