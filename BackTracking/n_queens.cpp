//
// Created by zhou on 2023/11/5.
// 经典N皇后问题

#include "../utils/common.h"

bool isValid(int row, int col, vector<vector<string>> &state, int n) {
    // 看每一列上是否有皇后
    for(int i = 0; i < row; i++) {
        if (state[i][col] == "Q") return false;
    }
    // 检查左上方，即主对角线
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0 ; --i, --j) {
        if (state[i][j] == "Q") return false;
    }
    // 检查右上方，即次对角线
    for (int i = row - 1, j = col + 1; i >= 0 && j <= n-1 ; --i, ++j) {
        if (state[i][j] == "Q") return false;
    }
    // 都没有，说明符合要求
    return true;
}


void backtrack(vector<vector<string>> &state, int row, int n, vector<vector<vector<string>>> &res) {
    // 放置完所有行，记录解
    if (row == n) {
        res.push_back(state);
        return;
    }
    // 遍历所有列，列的索引是[0,n-1]
    for (int col = 0; col < n; ++col) {
        // 如果是符合要求的，合法位置
        if(isValid(row, col, state, n)) {
            // 尝试放置皇后
            state[row][col] = "Q";
            // 找下一行
            backtrack(state, row + 1, n, res);
            // 回溯，回到原样
            state[row][col] = ".";
        }
    }
}
