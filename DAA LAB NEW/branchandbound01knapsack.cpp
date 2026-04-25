#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Item {
    int value;
    int weight;
};

struct Node {
    int level;
    int profit;
    int weight;
    float bound;
};

bool compare(Node a, Node b) {
    return a.bound > b.bound;
}

float bound(Node u, int n, int W, vector<Item>& items) {
    if (u.weight >= W) return 0;
    int profitBound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;
    while (j < n && totalWeight + items[j].weight <= W) {
        totalWeight += items[j].weight;
        profitBound += items[j].value;
        j++;
    }
    if (j < n) profitBound += (W - totalWeight) * items[j].value / items[j].weight;
    return profitBound;
}

int knapsack(int W, vector<Item>& items, int n) {
    priority_queue<Node, vector<Node>, decltype(&compare)> Q(compare);
    Node u, v;
    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    u.bound = 0.0;

    Q.push(u);
    int maxProfit = 0;

    while (!Q.empty()) {
        u = Q.top();
        Q.pop();
        if (u.level == n - 1) continue;

        v.level = u.level + 1;
        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].value;

        if (v.weight <= W && v.profit > maxProfit) maxProfit = v.profit;

        v.bound = bound(v, n, W, items);
        if (v.bound > maxProfit) Q.push(v);

        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, items);
        if (v.bound > maxProfit) Q.push(v);
    }

    return maxProfit;
}

int main() {
    int W, n;
    cout << "Enter the number of items and capacity of knapsack: ";
    cin >> n >> W;

    vector<Item> items(n);

    cout << "Enter the value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    int maxProfit = knapsack(W, items, n);

    cout << "Maximum profit that can be obtained: " << maxProfit << endl;

    return 0;
}
