//
// Created by zhou on 2023/10/17.
//
#include "../utils/common.h"

/**
 * 利用哈希表key不能重复的特性实现两数之和
 * 利用哈希查找替换掉线性查找，提升效率
 */
vector<int> twoSum(vector<int> &nums, int target) {
    // 哈希表，key为数组的值，value是数组的索引
    unordered_map<int, int> dic;
    int size = nums.size();
    // 遍历数组
    for(int i = 0; i < size; i++) {
        // 当在哈希表中能够找到
        // find()方法，参数传入的是键，返回值是迭代器，若哈希表中存在该key，则返回指向该元素的迭代器，否则返回的是指向末尾的迭代器
        if(dic.find(target - nums[i]) != dic.end()) {
            return {i, dic[target - nums[i]]};
        }
        // 哈希表中没有的，则先入表
        dic.emplace(nums[i], i);
    }
    return {};
}