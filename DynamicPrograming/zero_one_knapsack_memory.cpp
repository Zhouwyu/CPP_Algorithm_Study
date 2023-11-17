//
// Created by zhou on 2023/11/17.
//
#include "../utils/common.h"

int knapsack(vector<int> &weight, vector<int> &value, vector<vector<int>> &memory, int capacity, int i) {
    // 边界条件处理，当没有物品可选或背包容量为空时，返回价值0
    if(i == 0 || capacity == 0) return 0;
    // 已有记录，直接返回
    if (memory[i][capacity] != -1) return memory[i][capacity];
    // 当所选物品价值大于背包容量时，该物品不放入背包，继续从剩下的物品（i - 1个物品）中做选择
    // 注意第一个i-1是索引，代表第i个物品的重量；后面i-1是表示还有i-1个物品可供选择
    if (weight[i - 1] > capacity) return knapsack(weight, value, memory, capacity, i - 1);
    // 选择不放入，继续从剩余物品中选择
    int no = knapsack(weight, value, memory, capacity, i - 1);
    // 选择放入，则背包容量减少，还剩i-1个物品可选，加上所选物品的价值
    int yes = knapsack(weight, value, memory, capacity - weight[i - 1], i - 1) + value[i - 1];
    // 做记录
    memory[i][capacity] =  max(no, yes);
    return memory[i][capacity];
}