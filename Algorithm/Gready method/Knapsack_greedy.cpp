#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
    double ratio;
};

// Comparator for sorting by ratio
bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;

    for (auto& item : items) {
        if (W == 0) break;

        if (item.weight <= W) {
            // Take the whole item
            totalValue += item.value;
            W -= item.weight;
        } else {
            // Take fraction of the item
            totalValue += item.ratio * W;
            W = 0;
        }
    }
    return totalValue;
}

int main() {
    int W = 50; // Capacity
    vector<Item> items = {
        {60, 10},  // value=60, weight=10
        {100, 20}, // value=100, weight=20
        {120, 30}  // value=120, weight=30
    };

    // Pre-calculate ratios
    for (auto &item : items) {
        item.ratio = (double)item.value / item.weight;
    }

    cout << "Maximum value in Knapsack = " 
         << fractionalKnapsack(W, items) << endl;

    return 0;
}
