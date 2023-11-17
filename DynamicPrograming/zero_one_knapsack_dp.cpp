//
// Created by zhou on 2023/11/17.
//
#include "../utils/common.h"

int knapsack(vector<int> &weight, vector<int> &value, int capacity) {
    int n = weight.size();

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= capacity; ++j) {
            if (weight[i] > capacity) dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            }
        }
    }
    return dp[n][capacity];
}