//
// Created by zhou on 2023/10/23.
//
#include "../utils/common.h"

void bucketSort(vector<float> &nums) {
    // 桶的数量
    int k = nums.size() / 2;
    // 初始化桶
    vector<vector<float>> buckets(k);
    // 元素范围[0,1)，则num * k可以限定索引在[0, k-1]
    for(float num : nums) {
        int i = num * k;
        // 把元素入到对应的桶，整体有序
        buckets[i].push_back(num);
    }

    // 桶内排序
    for(vector<float> &bucket : buckets) {
        sort(bucket.begin(), bucket.end());
    }

    // 桶元素取出，合并结果
    int index = 0;
    for(vector<float> &bucket : buckets) {
        for(int num : bucket) {
            nums[index++] = num;
        }
    }
}

