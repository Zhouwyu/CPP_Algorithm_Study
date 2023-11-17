//
// Created by zhou on 2023/11/17.
// 最小路径和：记忆化搜索
#include "../utils/common.h"
int minSumPath(vector<vector<int>> &grid, vector<vector<int>> &memory, int i, int j) {
    // 边界条件处理
    if (i == 0 && j == 0) return grid[0][0];
    if (i < 0 || j < 0) return INT_MAX;
    // 类似使用缓存，若已有记录，直接返回，剪枝
    if (memory[i][j] != -1) return memory[i][j];
    // 同暴力搜索逻辑一致
    int left = minSumPath(grid, memory, i, j - 1);
    int up = minSumPath(grid, memory, i - 1, j);
    // 将该单元格代价记录
    memory[i][j] = min(left, up) != INT_MAX ? min(left, up) + grid[i][j] : INT_MAX;
    return memory[i][j];
}
