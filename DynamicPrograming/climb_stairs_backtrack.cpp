//
// Created by zhou on 2023/11/8.
// 给定一个共有 𝑛 阶的楼梯，你每步可以上 1 阶或者 2 阶，请问有多少种方案可以爬到楼顶。

#include "../utils/common.h"

void backtrack(vector<int> &choices, int state, int n, vector<int> &res) {
    // 当爬到第n阶，说明此次爬楼结束，方案加一
    if(state == n) {
        res[0]++;
        return;
    }
    // 遍历所有的爬楼选择
    for (int i = 0; i < choices.size(); ++i) {
        // 超出n阶直接跳出循环
        if(state + choices[i] > n) break;
        // 未超，则做出选择
        state += choices[i];
        // 下一轮的选择
        backtrack(choices, state, n, res);
    }
}

int climbStairsBacktrack(int n) {
    // 给一个位置存放方案数
    vector<int> res(1, 0);
    vector<int> choices = {1, 2};
    backtrack(choices, 0, n, res);
    return res[0];
}