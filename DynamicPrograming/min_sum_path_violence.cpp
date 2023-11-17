//
// Created by zhou on 2023/11/16.
// 最小路径和：暴力搜索
#include "../utils/common.h"
int minSumPath(vector<vector<int>> &grid, int i, int j) {
    // 首个单元格
    if (i == 0 && j == 0) return grid[0][0];
    // 越界
    if (i < 0 || j < 0) return INT_MAX;
    // 左边往右走
    int left = minSumPath(grid, i, j - 1);
    // 上边往下走
    int up = minSumPath(grid, i - 1, j);
    // 两者取最小加上当前单元格的代价即最小路径和
    return min(left, up) != INT_MAX ? min(left, up) + grid[i][j] : INT_MAX;
}
