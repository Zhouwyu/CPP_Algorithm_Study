//
// Created by zhou on 2023/11/8.
// 记忆化搜索
#include "../utils/common.h"

int dfs(int n, vector<int> &memo) {
    if (n == 1 || n == 2) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = dfs(n - 1, memo) + dfs(n - 2, memo);
    return memo[n];
}

int climbingStairsDFSMem(int n) {
    // mem[i] 记录爬到第 i 阶的方案总数， -1 代表无记录
    vector<int> mem(n + 1, -1);
    return dfs(n, mem);
}

int main() {
    int count = climbingStairsDFSMem(6);
    cout << count << endl;
    return 0;
}