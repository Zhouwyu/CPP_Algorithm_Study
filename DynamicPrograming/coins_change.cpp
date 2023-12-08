//
// Created by zhou on 2023/11/18.
//
#include "../utils/common.h"

int coinsChange(vector<int> &coins, int amt, int n) {
    int MAX = amt + 1; // 用于表示无硬币时无解的情况
    // 初始化dp表，默认全为0，首列表示目标金额为0时，硬币个数就是0
    vector<vector<int>> dp(n + 1, vector<int>(amt + 1, 0));
    // 初始化首行，即无硬币时，目标金额>0的情况下无解
    for (int i = 1; i <= amt; ++i) {
        dp[0][i] = MAX;
    }
    // 填充dp表剩下的部分行列
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= amt; ++j) {
            // 若硬币面值大于目标金额，则不选，从剩下的i-1个硬币继续做选择
            if (coins[i - 1] > j) dp[i][j] = dp[i - 1][j];
            // 选与不选中做选择：选的话，目标金额应该减少，硬币数+1
            else dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
        }
    }
    return dp[n][amt] == MAX ? -1 : dp[n][amt];
}