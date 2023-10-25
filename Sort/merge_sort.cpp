//
// Created by zhou on 2023/10/18.
// 归并排序
#include "../utils/common.h"

/**
 * 合并操作
 */
void merge(vector<int> &nums, int left, int mid, int right) {
    // i为左子数组的第一个元素索引，j为右子数组的第一个元素索引
    int i = left, j = mid + 1;
    // 用于遍历临时数组
    int k = left;
    // 临时数组，初始化大小与nums数组一致
    vector<int> temp(nums.begin() + left, nums.begin() + right + 1);
    // 分别遍历左右子数组，并两两互相比较，更小的那个添加进临时数组中
    while (i <= mid && j <= right) {
        if(nums[i] < nums[j]) temp[k++] = nums[i++];
        if(nums[i] > nums[j]) temp[k++] = nums[j++];
    }
    // 左/右子数组还有残余的元素尚未入数组中的，留下来的肯定是最大的，无需比较，直接入组即可
    while(i <= mid) temp[k++] = nums[i++];
    while(j <= right) temp[k++] = nums[j++];

    // 将临时数组的元素复制到nums数组中
    while (left <= right) {
        nums[left] = temp[left];
        left++;
    }
}

void merge_sort(vector<int> &nums, int left, int right) {
    // 只有一个元素时，无需再划分
    if(left >= right) return;
    // 中间点作为划分边界
    int mid = left + (right - left) / 2;
    // 划分左子数组
    merge_sort(nums, left, mid);
    // 划分右子数组
    merge_sort(nums, mid + 1, right);
    // 不断合并
    merge(nums, left, mid, right);
}



int main() {
    vector<int> nums{5,2,8,3,9};
    merge_sort(nums, 0, nums.size() - 1);
    for (int num : nums) {
        cout << num  << endl;
    }
    return 1;
}