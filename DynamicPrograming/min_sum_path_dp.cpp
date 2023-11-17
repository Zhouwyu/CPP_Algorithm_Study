//
// Created by zhou on 2023/11/17.
// 最小路径和：动态规划

#include "../utils/common.h"

int minSumPath(vector<vector<int>> &grid) {
    // 行数
    int row = grid.size();
    // 列数
    int col = grid[0].size();
    // 初始化一个与grid表同等大小的dp表
    vector<vector<int>> dp(row, vector<int>(col));
    // 初始化dp表首个单元格元素
    dp[0][0] = grid[0][0];
    // 首行
    for (int i = 1; i < col; ++i) {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    // 首列
    for (int j = 1; j < row; ++j) {
        dp[j][0] = dp[j - 1][0] + grid[j][0];
    }
    // 除首行首列外其它行列，一行一行地初始化dp表
    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    // 最后dp表中最后的一个单元格存储的就是最小代价和
    return dp[row - 1][col - 1];
}