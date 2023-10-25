//
// Created by zhou on 2023/10/24.
// 利用分治方法处理二分查找

#include "../utils/common.h"

int dfs(vector<int> &nums, int target, int low, int high) {
    // 区间为空，无目标元素，返回-1
    if(low > high) return -1;
    // 临界点
    int mid = low + (high - low) / 2;
    // 递归左半部分[low, mid - 1]
    if(nums[mid] > target) return dfs(nums, target, low, mid - 1);
    // 递归右半部分[mid + 1, high]
    else if(nums[mid] < target) return dfs(nums, target, mid + 1, high);
    // 找到返回索引
    else return mid;
}

