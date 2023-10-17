//
// Created by zhou on 2023/10/16.
//
#include "../utils/common.h"

/**
 * 左边界
 */
int binarySearchLeftEdge(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
        int mid  = low + (high - low) / 2;
        // 往左收缩
        if (nums[mid] > target || nums[mid] == target) high = mid - 1;
        else if(nums[mid] < target) low = mid + 1;
    }
    // 最后low指向的就是左边界，high = low - 1
    return low;
}

/**
 * 右边界
 */
int binarySearchRightEdge(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
        int mid  = low + (high - low) / 2;
        if (nums[mid] > target) high = mid - 1;
        // 收缩右边界
        else if(nums[mid] < target || nums[mid] == target) low = mid + 1;
    }
    // 最后high指向的就是右边界
    return high;
}

int main() {
    vector<int> nums{1,3,6,6,6,6,6,10,12,15};
    int left = binarySearchLeftEdge(nums, 6);
    int right = binarySearchRightEdge(nums, 6);
    cout << left << "\n" << endl;
    cout << right << endl;
}
