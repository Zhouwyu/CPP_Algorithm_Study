//
// Created by zhou on 2023/11/17.
//
#include "../utils/common.h"

int minSumPath(vector<vector<int>> &grid) {
    // 行数
    int row = grid.size();
    // 列数
    int col = grid[0].size();
    // 初始化dp列表，长度为列数大小
    vector<int> dp(col);
    dp[0] = grid[0][0];
    // 先处理首行，确保dp[row - 1]有值
    for (int i = 1; i < col; ++i) {
        dp[i] = dp[i - 1] + grid[0][i];
    }
    // 状态转移
    for (int i = 1; i < row; ++i) {
        // 一行一行往下操作，每次先处理行首元素，确保dp[col - 1]有值，也可以理解成处理首列
        dp[0] = dp[0] + grid[i][0];
        // 处理其余列
        for (int j = 1; j < col; ++j) {
            dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
        }
    }
    // 最终列表最后一个元素值就是最小代价
    return dp[col - 1];
}