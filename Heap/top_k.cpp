//
// Created by zhou on 2023/10/11.
// 给定一个长度为 𝑛 无序数组 nums ，请返回数组中前 𝑘 大的元素。

#include "../utils//common.h"
/**
 * 求前K大元素
 * @param nums 用于初始化堆
 * @param k k个元素
 * @return 前K大的元素集合
 */
priority_queue<int, vector<int>, greater<int>> getTopK(vector<int> &nums, int k) {
    // 先声明一个堆，方便后面操作
    priority_queue<int, vector<int>, greater<int>> heap;
    // 前k个元素入堆
    for(int i = 0; i < k; i++) {
        heap.push(nums[i]);
    }
    // 从第k+1个元素开始，与堆顶元素比较，大于堆顶的则堆顶出堆，新元素入堆
    for(int i = k; i < nums.size(); i++) {
        if (nums[i] > heap.top())  {
            heap.pop();
            heap.push(nums[i]);
        }
    }
    // 最后堆中的元素即为所求
    return heap;
}