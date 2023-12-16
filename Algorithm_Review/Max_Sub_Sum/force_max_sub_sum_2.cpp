//
// Created by zhou on 2023/12/14.
//
// 蛮力法解法2 优化时间复杂度

#include "vector"
#include "iostream"

using namespace std;

int maxSubSum(vector<int>&nums) {
    int maxSum = 0;
    int thisSum = 0;
    for (int num : nums) {
        thisSum += num;
        // 当前和小于0说明不可能再是最大和了，舍弃，赋值为0，重新开始求和
        if (thisSum < 0) {
            thisSum = 0;
        }
        // 更新最大值
        if (thisSum > maxSum) maxSum = thisSum;
    }
    return maxSum;
}

int main() {
    vector<int> nums{-2, 11, -4, 13, -5, -2};
    cout << maxSubSum(nums) << endl;
    return 0;
}