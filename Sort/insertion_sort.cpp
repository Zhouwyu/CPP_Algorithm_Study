//
// Created by zhou on 2023/10/17.
//
#include "../utils/common.h"

/**
 * 插入排序
 */
void insertionSort(vector<int> &nums) {
    for(int i = 1; i < nums.size(); i++) {
        // 记录基准值
        int base = nums[i];
        // j指向基准值的前一个值
        int j = i - 1;
        // 若下标未越界且对应的值大于基准值
        while (j >= 0 && nums[j] > base) {
            // 则向后移，让出前面的位置给基准值插入
            nums[j + 1] = nums[j];
            j--;
        }
        // 插入基准值到已有序的区间
        nums[j + 1] = base;
    }
}