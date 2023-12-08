//
// Created by zhou on 2023/11/17.
//
#include "../utils/common.h"

int knapsack(vector<int> &weight, vector<int> &value, int capacity) {
    // 确定行数
    int n = weight.size();
    // 初始化dp表，其实此处dp表是个方阵，先初始化首行首列均为0，则索引直接从1开始即可
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    // 状态转移，其实就是填充dp表
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= capacity; ++j) {
            // 假如所选物品重量超过背包容量，不放入，从剩余i-1个物品中选择
            if (weight[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // 否则就在放入或不放入之间选最优解
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
            }
        }
    }
    return dp[n][capacity];
}