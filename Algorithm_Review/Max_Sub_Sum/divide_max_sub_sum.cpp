//
// Created by zhou on 2023/12/14.
//
// 求最大连续子序列和 分治法

#include "vector"
#include "iostream"

using namespace std;

int maxSubSum(int nums[], int left, int right) {
    int i, j;
    long leftMaxSum, rightMaxSum;
    long leftBorderSum, rightBorderSum;
    long leftBorderMaxSum, rightBorderMaxSum;
    // 当只有一个元素的时候
    if (left == right) {
        // 大于0直接返回当前元素
        if (nums[left] > 0) return nums[left];
        // 小于或等于0的情况
        else return 0;
    }
    // 中间索引，分界点
    int mid = (left + right) / 2;
    // 求左边子序列最大值（即只落在左半部分）
    leftMaxSum = maxSubSum(nums, left, mid);
    // 求右边子序列最大值（即只落在右半部分）
    rightMaxSum = maxSubSum(nums, mid + 1, right);
    // 假如是跨越了分界点的
    leftBorderSum = 0; leftBorderMaxSum = 0;
    // 从分界点往前遍历
    for (i = mid; i >= left; i--) {
        // 计算分界点左半部分的和
        leftBorderSum += nums[i];
        // 记录最大和
        if (leftBorderSum > leftBorderMaxSum) leftBorderMaxSum = leftBorderSum;
    }
    // 从分界点往右遍历
    rightBorderSum = 0; rightBorderMaxSum = 0;
    for (j = mid + 1; j <= right; j++) {
        rightBorderSum += nums[j];
        if (rightBorderSum > rightBorderMaxSum) rightBorderMaxSum = rightBorderSum;
    }
    // 取三种可能之中的最大值
    return max(max(leftMaxSum, rightMaxSum), leftBorderMaxSum + rightBorderMaxSum);
}

int main() {
    int nums[] = {-2, 11, -4, 13, -5, -2};
    int n = 6;
    cout << maxSubSum(nums, 0, n - 1) << endl;
    return 0;
}
