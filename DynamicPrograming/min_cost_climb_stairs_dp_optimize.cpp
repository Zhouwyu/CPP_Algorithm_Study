//
// Created by zhou on 2023/11/9.
//

#include "../utils/common.h"
int minCostClimbStairsDPOptimize(vector<int> cost) {
    int n = cost.size() - 1;
    if (n == 1 || n == 2) return cost[n];
    // 初始化状态
    int a = cost[1];
    int b = cost[2];
    // 从子问题求解原问题
    for (int i = 3; i <= n; ++i) {
        int temp = b;
        b = min(a, b) + cost[i];
        a = temp;
    }
    return b;
}