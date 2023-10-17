//
// Created by zhou on 2023/10/16.
//
// 给定一个长度为 𝑛 的有序数组 nums 和一个元素 target ，数组不存在重复元素。现将 target
// 插入到数组 nums 中，并保持其有序性。若数组中已存在元素 target ，则插入到其左方。请返
// 回插入后 target 在数组中的索引。

#include "../utils/common.h"
/**
 * 数组元素不重复
 */
int binarySearchInsertion(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target) low = mid + 1;
        else if(nums[mid] > target) high = mid - 1;
        // 存在目标元素，插在其左方，则其索引就是原来target的位置
        else return mid;
    }
    // 不存在目标元素，low不断往大于等于target的方向靠近，high不断往小于等于target的方向靠近
    return low;
}

/**
 * 数组元素重复
 * 根据题目要求元素插在左边，故元素重复的时候，需要找到最左边那个target的索引
 */
int binarySearchInsertionWithRepeat(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) high = mid - 1;
        else if(nums[mid] < target) low = mid + 1;
        // 首个小于target的元素在[low, mid - 1]的区间中
        else high = mid - 1;
    }
    return low;
}
