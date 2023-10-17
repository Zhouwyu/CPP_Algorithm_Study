//
// Created by zhou on 2023/10/17.
//
#include "../utils/common.h"

/**
 * 选择排序
 */
void selectionSort(vector<int> &nums) {
    // 未排序区间[i , n - 1]
    for (int i = 0; i < nums.size(); ++i) {
        // 用于记录最小值索引
        int min = i;
        // 在未排序区间中寻找最小的
        for (int j = i + 1; j < nums.size(); ++j) {
            if(nums[j] < nums[min]) {
                min = j;
            }
        }
        // 找到最小的与未排序区间的首个元素进行交换
        swap(nums[i], nums[min]);
    }
}

void swap(int &i, int &j) {
    int temp = i;
    i = j;
    j = temp;
}

int main() {
    vector<int> nums{5,2,8,3,9};
    selectionSort(nums);
    for (int num : nums) {
        cout << num  << endl;
    }
}