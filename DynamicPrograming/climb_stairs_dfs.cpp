//
// Created by zhou on 2023/11/8.
// 暴力搜索

int dfs(int n) {
    if(n == 1 || n == 2) {
        return n;
    }
    int res = dfs(n - 1) + dfs(n - 2);
    return res;
}

int climbStairs(int n) {
    return dfs(n);
}