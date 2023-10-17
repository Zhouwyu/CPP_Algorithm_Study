//
// Created by zhou on 2023/10/10.
//
#include "../utils/common.h"

// 头文件functional，模板：template <class T, class Container = vector,class Compare = less >
// 小根堆
priority_queue<int, vector<int>, greater<int>> minHeap;
// 大根堆
priority_queue<int, vector<int>, less<int>> maxHeap;

void testHeap() {
    maxHeap.push(1);
    maxHeap.push(3);
    maxHeap.push(2);
    maxHeap.push(5);
    maxHeap.push(4);
    // 获取堆顶元素
    int topNum = maxHeap.top();
    // 获取大小
    int size = maxHeap.size();
    // 判断是否为空
    bool isEmpty = maxHeap.empty();
    // 出堆,会由大到小
    maxHeap.pop();
}

// 初始化建堆
vector<int> input{1, 3, 2, 4, 5};
priority_queue<int, vector<int>, less<int>> maxHeap2 (input.begin(), input.end());