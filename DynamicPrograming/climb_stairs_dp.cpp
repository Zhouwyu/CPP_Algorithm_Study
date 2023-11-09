//
// Created by zhou on 2023/11/8.
// 动态规划

#include "../utils/common.h"

int climbStairsDP(int n) {
    if (n == 1 || n == 2) return n;
    // 初始化 dp 表，用于存储子问题的解
    vector<int> dp(n+1);
    // 初始状态：预设最小子问题的解
    dp[1] = 1;
    dp[2] = 2;
    // 状态转移：从较小子问题逐步求解较大子问题
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    cout << climbStairsDP(6) << endl;
}
