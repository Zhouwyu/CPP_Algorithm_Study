//
// Created by zhou on 2023/11/19.
//
#include "../utils/common.h"

class Item {
public:
    int weight;
    int value;

    Item(int w, int v) : weight(w), value(v) {}
};

int fractionalKnapsack(vector<int> &weg, vector<int> &val, int cap) {
    int n = weg.size() - 1;
    // 物品列表
    vector<Item> items;
    // 初始化物品列表，将重量和价值都初始化好
    for (int i = 0; i <= n; ++i) {
        items.push_back(Item(weg[i], val[i]));
    }
    // 按照单位价值由高到低排好序
    sort(items.begin(), items.end(), [](Item &a, Item &b){
       return (double (a.value) / a.weight) > (double (b.value) / b.weight);
    });
    // 结果，最终的价值
    int res = 0;
    // 遍历所有物品
    for (const auto &item: items) {
        // 当前物品重量小于或等于容量时，全部放入背包即可，背包容量减少
        if (item.weight <= cap) {
            res += item.value;
            cap -= item.weight;
        } else {
            // 当前物品重量大于背包容量时，选取一定比例放入背包即可
            res += (double)(item.value / item.weight) * cap;
            // 此时背包肯定装满了，跳出循环
            break;
        }
    }
    return res;
}