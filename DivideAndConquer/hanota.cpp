//
// Created by zhou on 2023/10/26.
// 汉诺塔问题

#include "../utils/common.h"

// 移动一个圆盘
void move(vector<int> &src, vector<int> &tar) {
    // 先从src柱取出顶部的圆盘，back()方法返回的是最后一个元素引用
    int pan = src.back();
    src.pop_back();
    // 放入tar柱
    tar.push_back(pan);
}

// 求解汉诺塔问题，f(i)的问题
void dfs(int nums, vector<int> &src, vector<int> &buf, vector<int> &tar) {
    // 只有一个圆盘时，直接移动到tar柱即可（相当于递归结束条件）
    if(nums == 1) {
        move(src, tar);
        return;
    }
    // f(n - 1)，借助tar柱，移动到buf柱
    dfs(nums - 1, src, tar, buf);
    // f(1)，直接移动到tar柱
    move(src, tar);
    // f(n - 1)，借助src柱，移动到tar柱
    dfs(nums - 1, buf, src, tar);
}

// 解决汉诺塔的问题
void solveHanota(vector<int> &src, vector<int> &buf, vector<int> &tar) {
    int size = src.size();
    // src柱的所有圆盘借助buf柱移动到tar柱
    dfs(size, src, buf, tar);
}
