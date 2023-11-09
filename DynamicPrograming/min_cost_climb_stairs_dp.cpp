//
// Created by zhou on 2023/11/9.
// 爬楼梯最小代价 给定一个楼梯，你每步可以上 1 阶或者 2 阶，每一阶楼梯上都贴有一个非负整数，表示你在
//该台阶所需要付出的代价。给定一个非负整数数组 𝑐𝑜𝑠𝑡 ，其中 𝑐𝑜𝑠𝑡[𝑖] 表示在第 𝑖 个台阶需
//要付出的代价， 𝑐𝑜𝑠𝑡[0] 为地面起始点。请计算最少需要付出多少代价才能到达顶部？

#include "../utils/common.h"

int minCostClimbStairs(vector<int> cost) {
    int n = cost.size() - 1;
    if (n == 1 || n == 2) {
        return cost[n];
    }
    vector<int> dp(n + 1);
    dp[1] = cost[1];
    dp[2] = cost[2];
    for (int i = 3; i <= n; ++i) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    return dp[n];
}