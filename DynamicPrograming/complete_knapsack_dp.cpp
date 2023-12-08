//
// Created by zhou on 2023/11/18.
//

#include "../utils/common.h"

int completeKnapsack(vector<int> &weight, vector<int> &value, int capacity) {
    int n = weight.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= capacity; ++j) {
            // 所选物品超重，只能从i-1个物品继续选择
            if (weight[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            // 物品不超重，可以选择放入或不放入
            else {
                // 不放入：dp[i - 1][j] 容量不变，继续从剩余i-1个物品做选择
                // 放入：dp[i][j - weight[i - 1]] ，容量减少，但因为物品可重复选择，故依然为i(这就是与0-1背包不同的地方)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i - 1]]) + value[i - 1];
            }
        }
    }
    return dp[n][capacity];
}