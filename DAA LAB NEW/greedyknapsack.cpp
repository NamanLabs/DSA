#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
    double ratio;
};

// Comparator function to sort items based on value/weight ratio
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double knapsackGreedy(int W, vector<Item>& items, int n) {
    // Sorting items based on value/weight ratio in descending order
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (W >= items[i].weight) {
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    cin >> n >> W;

    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    double result = knapsackGreedy(W, items, n);
    cout << "Maximum value in Knapsack = " << result << endl;
    
    return 0;
}
