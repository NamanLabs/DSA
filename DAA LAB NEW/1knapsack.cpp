#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cin >> n >> W;  // n: number of items, W: capacity of knapsack

    vector<int> values(n), weights(n);

    cout << "Enter the values and weights of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }

    int maxValue = knapsack(W, weights, values, n);
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}
