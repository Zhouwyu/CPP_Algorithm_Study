//
// Created by zhou on 2023/10/17.
//
#include "../utils/common.h"

int partition(vector<int> &nums, int left, int right) {
    int i = left, j = right;
    // 基准值
    int base = nums[left];
    while (i < j) {
        // 当大于其基准值时，保留在右边不动，继续往前遍历
        while (i < j && nums[j] > base) j--;
        // 小于基准值时，保留在左边不动，继续往后遍历
        while (i < j && nums[i] < base) i++;
        // 不符合上述情况的，交换两元素
        swap(nums[i], nums[j]);
    }
    // 循环结束，说明基本已经划分成两部分，将基准值放到正确位置
    swap(base, nums[i]);
    // 划分边界的索引
    return i;
}

void quickSort(vector<int> &nums, int left, int right) {
    // 只剩一个元素时，无需再递归划分
    if (left >= right) return;
    // 获取划分边界的索引（划分的同时完成排序）
    int pivot = partition(nums, left, right);
    // 递归处理左右子数组，类似二分查找
    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1, right);
}

int main() {
    vector<int> nums{5,2,8,3,9};
    quickSort(nums, 0, nums.size() - 1);
    for (int num : nums) {
        cout << num  << endl;
    }
}