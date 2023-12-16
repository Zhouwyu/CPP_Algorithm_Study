//
// Created by zhou on 2023/12/14.
//
// 蛮力法-最大连续子序列和


#include "vector"
#include "iostream"

using namespace std;

int maxSubSum(vector<int> &nums) {
    int maxSum = 0;
    for(int i = 0; i < nums.size(); i++) {
        int thisSum = 0;
        for (int j = i; j < nums.size(); ++j) {
            thisSum += nums[j];
            if (thisSum > maxSum) maxSum = thisSum;
        }
    }
    return maxSum;
}

int main() {
    vector<int> nums{-2, 11, -4, 13, -5, -2};
    cout << maxSubSum(nums) << endl;
    return 0;
}