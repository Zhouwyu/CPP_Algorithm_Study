//
// Created by zhou on 2023/10/16.
//
#include "../utils/common.h"

/**
 * 双闭区间
 */
int binarySearch(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
        // 防止 low + high 的值溢出，固定公式
        int mid = low + (high - low) / 2;
        // 目标值处于右区间
        if(nums[mid] < target) low = mid + 1;
        // 目标值处于左区间
        else if(nums[mid] > target) high = mid - 1;
        // 否则刚好就是目标值
        else return mid;
    }
    // 没找到
    return -1;
}