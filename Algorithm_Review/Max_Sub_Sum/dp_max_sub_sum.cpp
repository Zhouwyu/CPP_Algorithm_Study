//
// Created by zhou on 2023/12/14.
//
// 动态规划

#include "vector"
#include "iostream"

using namespace std;

#define MAXCAP 20

int maxSubSum(vector<int> &nums) {
    vector<int> dp(MAXCAP);
    // 初始化dp，用于记录子序列的和
    dp[0] = 0;
    // 下标从1开始
    for (int i = 1; i <= nums.size(); ++i) {
        // 若dp[i-1]>0，则继续+nums[i]，否则舍弃，直接从nums[i]开始
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    }
    // 遍历dp数组找最大值，即是最大子序列和
    int maxSum = 0;
    for (int j : dp) {
        if (j > maxSum) maxSum = j;
    }
    return maxSum;
}

int main() {
    vector<int> nums{-2, 11, -4, 13, -5, -2};
    cout << maxSubSum(nums) << endl;
    return 0;
}