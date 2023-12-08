//
// Created by zhou on 2023/12/7.
//
/**
 * 贪心法，利用unordered_map
 */
#include <cstdio>
#include <iostream>
#include "vector"
#include "unordered_map"
#include "algorithm"

using namespace std;

// 键值对，用于存储map中的key-value，方便排序
typedef pair<int, int> Pair;

/**
 * 重写比较器，自定义比较规则
 */
int compare(const Pair &x, const Pair &y) {
    // map中value由小到大排列
    return x.second <= y.second;
}
/**
 * 打印出现次数由小到大的元素排列，每个仅输出一次
 */
void displayOrderNums(vector<Pair> &res) {
    cout<< "The order of elements from least to most is:" << endl;
    for (const auto &item: res) {
        printf("%d\t", item.first);
    }
    printf("\n");
}

/**
 * 寻找出现次数最多的元素
 */
int findNum(vector<int> &nums) {
    // 定义一个map，其key为nums序列里的值，value是其出现的次数
    unordered_map<int, int> map;
    // 将nums中的元素按照上述规则放入map中
    for (int & num : nums) {
        // 若map中尚未存在该key，则添加一个
        if (map.count(num) == 0) {
            map.emplace(num, 1);
        }
        // 若已存在该key，则对应value（即出现次数+1）
        map.at(num)++;
    }
    // 最终元素存储在此列表中
    vector<Pair> result;
    // 分配内存
    result.reserve(map.size());
    // 遍历map，将其键值对加入列表中
    for (const auto &item: map) {
        result.emplace_back(item);
    }
    // 根据出现次数由小到大的次序进行排序
    sort(result.begin(), result.end(), compare);
    // 按照出现次数由少到多的次序输出所有元素，重复元素只会出现一次
    displayOrderNums(result);
    // 最终列表中最后一个键值对对应的key就是出现次数最多的元素
    return result[result.size() - 1].first;
}



int main() {
    vector<int> nums{2,3,1,2,4,3,3};
    int num = findNum(nums);
    cout << "\nThe most frequently occurring element is:" << endl;
    printf("%d", num);
}
