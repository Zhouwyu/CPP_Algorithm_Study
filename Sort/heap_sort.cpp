//
// Created by zhou on 2023/10/18.
// 堆排序

#include "../utils/common.h"

void swap(int &i, int &j) {
    int temp = i;
    i = j;
    j = temp;
}

/**
 * 大根堆。和之前堆化代码逻辑一致，自顶向下堆化
 */
void siftDown(vector<int> &nums, int n, int i) {
    while(true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int max = i;
        if(left < n && nums[left] > nums[max]) max = left;
        if(right < n && nums[right] > nums[max]) max = right;
        if (max == i) break;
        swap(nums[i], nums[max]);
        i = max;
    }
}

void heap_sort(vector<int> &nums) {
    // 建立最大堆，首先将所有元素入堆，然后从最后一个叶子节点的父节点（nums.size() - 1 - 1） / 2出发，开始堆化操作
    for(int i = (nums.size() - 2) / 2; i >= 0; i--) {
        siftDown(nums, nums.size(), i);
    }
    // 每次从堆中提出最大的元素，之所以不用=0，是因为堆中的最后一个元素无需操作
    for(int i = nums.size() - 1; i > 0; i--) {
        // 把最后一个元素与根节点元素互换
        swap(nums[i], nums[0]);
        // 然后从根节点开始堆化操作，注意这里堆中的元素个数使用了i，因为每提出一个最大的元素，堆的长度都应该需要-1
        siftDown(nums, i, 0);
    }
}



