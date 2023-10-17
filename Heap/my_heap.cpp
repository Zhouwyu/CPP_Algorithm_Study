//
// Created by zhou on 2023/10/11.
//
#include "../utils/common.h"

// 利用数组模拟堆（完全二叉树）
vector<int> maxHeap;

// 封装对应的索引映射公式
int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

int parent(int i) {
    return (i - 1) / 2;
}

/**
 * 获取堆顶元素。即数组首个元素
 */
int peek() {
    return maxHeap[0];
}

/**
 * 元素个数
 */
int size() {
    return maxHeap.size();
}

/**
 * 交换两值
 */
void swap(int &i, int &j) {
    int temp = i;
    i = j;
    j = temp;
}

/**********************元素入堆*********************************/

/**
 * 由堆底向顶部不断堆化
 */
void siftUp(int i) {
    while (true) {
        // 先找出父节点的索引
        int parentIndex = parent(i);
        // 若是索引越界或当前插入的值并不比其父节点的值大，则无需操作，直接结束
        if (parentIndex < 0 || maxHeap[i] <= maxHeap[parentIndex]) break;
        // 比父节点的值大，需要交换
        swap(maxHeap[i], maxHeap[parentIndex]);
        // 更新索引（不断往上堆化）
        i = parentIndex;
    }
}

/**
 * 元素入堆
 * 先将新元素放堆底（即数组末尾），然后再进行堆化
 */
void push(int val) {
    int index = size() - 1;
    // 放堆底
    maxHeap[index] = val;
    // 堆化
    siftUp(index);
}

/***********************元素出堆*********************************/
/**
 * 自上向下堆化
 */
void siftDown(int i) {
    while (true) {
        // 记录左孩子索引
        int leftIndex = left(i);
        // 右孩子索引
        int rightIndex = right(i);
        // 用于记录最大值的索引
        int maxIndex = i;
        // 左孩子索引不越界且其值大于父节点的值，则先记录其索引
        if(leftIndex < size() && maxHeap[leftIndex] > maxHeap[maxIndex]) maxIndex = leftIndex;
        // 右孩子同理
        if (rightIndex < size() && maxHeap[rightIndex] > maxHeap[maxIndex]) maxIndex = rightIndex;
        // 此时maxIndex记录的就是比较后最大值的索引，若maxIndex没有变化，说明父节点就是最大值，则无需堆化。跳出循环
        if (maxIndex == i) break;
        // maxIndex值有变化，故进行交换，确保父节点的值是最大的
        swap(maxHeap[i], maxHeap[maxIndex]);
        // 向下堆化
        i = maxIndex;
    }

}

void pop() {
    if (maxHeap.empty()) return;
    // 将最尾元素与头元素互换位置
    swap(maxHeap[0], maxHeap[size() - 1]);
    // 将头元素出堆，实现元素出堆操作
    maxHeap.pop_back();
    // 自上向下堆化
    siftDown(0);
}


