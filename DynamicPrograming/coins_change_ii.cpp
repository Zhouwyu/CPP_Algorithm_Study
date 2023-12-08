//
// Created by zhou on 2023/11/19.
//
#include "../utils/common.h"

int coinsChangeII(vector<int> &coins, int amt) {
    // 硬币数量
    int n = coins.size();
    // 初始化dp，默认全为0
    vector<vector<int>> dp(n + 1, vector<int>(amt + 1, 0));
    // 注意此dp表代表的是方案数量，
    // 当目标金额为0时，无需任何硬币就可达成，则方案数+1，故初始化首列均为1；
    // 当硬币数量为0时，目标金额大于0的部分无法满足，则方案数为0，故初始化首行为0
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }
    // 填充dp表其余行列
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= amt; ++j) {
            if (coins[i - 1] > amt) dp[i][j] = dp[i - 1][j];
            // 方案数为选与不选两种决策和
            else dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
        }
    }
    return dp[n][amt];
}