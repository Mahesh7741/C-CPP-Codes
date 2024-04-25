#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int value;
    double density; // Value per unit weight

    Item(int weight, int value) : weight(weight), value(value) {
        density = (double)value / weight;
    }
};

// Comparison function to sort items by density in descending order
bool compareItems(const Item& item1, const Item& item2) {
    return item1.density > item2.density;
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(int capacity, const vector<Item>& items) {
    // Sort items by density in descending order
    vector<Item> sortedItems = items;
    sort(sortedItems.begin(), sortedItems.end(), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    // Iterate through sorted items and add them to knapsack until capacity is reached
    for (const Item& item : sortedItems) {
        if (currentWeight + item.weight <= capacity) {
            // Take the whole item
            totalValue += item.value;
            currentWeight += item.weight;
        } else {
            // Take fraction of the item to fill the remaining capacity
            int remainingCapacity = capacity - currentWeight;
            totalValue += item.density * remainingCapacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity = 50; // Knapsack capacity
    vector<Item> items = {
        Item(10, 60),  // Item 1: weight = 10, value = 60
        Item(20, 100), // Item 2: weight = 20, value = 100
        Item(30, 120)  // Item 3: weight = 30, value = 120
    };

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in knapsack: " << maxValue << endl;

    return 0;
}
