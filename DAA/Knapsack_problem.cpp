 #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int value;

    Item(int weight, int value) : weight(weight), value(value) {}
};

// Function to solve the 0/1 knapsack problem
int knapsack(int capacity, const vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int capacity = 50; // Knapsack capacity
    vector<Item> items = {
        Item(10, 60),  // Item 1: weight = 10, value = 60
        Item(20, 100), // Item 2: weight = 20, value = 100
        Item(30, 120)  // Item 3: weight = 30, value = 120
    };

    int maxValue = knapsack(capacity, items);
    cout << "Maximum value in knapsack: " << maxValue << endl;

    return 0;
}
