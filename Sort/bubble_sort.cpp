//
// Created by zhou on 2023/10/17.
//
#include "../utils/common.h"

void bubbleSort(vector<int> &nums) {
    // 轮数，未排序空间[0, i]
    for(int i = nums.size() - 1; i > 0; i--) {
        // 将未排序空间中的元素两两互相比较，大的就不断往后移
        for(int j = 0; j < i; j++) {
            if(nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

void swap(int &i, int &j) {
    int temp = i;
    i = j;
    j = temp;
}