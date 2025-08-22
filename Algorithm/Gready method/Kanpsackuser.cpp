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
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> items[i].value;

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> items[i].weight;

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    // Pre-calculate ratios
    for (auto &item : items) {
        item.ratio = (double)item.value / item.weight;
    }

    double maxValue = fractionalKnapsack(W, items);

    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
