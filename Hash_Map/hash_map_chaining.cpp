//
// Created by zhou on 2023/10/6.

// 哈希冲突与扩容
//


#include "../utils/common.h"

class HashMapChaining {
private:
    // 键值对数量
    int size;
    // 哈希表容量
    int capacity;
    // 触发扩容的负载因子阈值
    double loadThres;
    // 扩容倍数
    int extendRatio;
    // 桶数组
    vector<vector<Pair *>> buckets;

public:
    // 成员初始化列表
    HashMapChaining() : size(0), capacity(4), loadThres(2.0 / 3), extendRatio(2) {
        buckets.resize(capacity);
    }

    // 析构函数
    ~HashMapChaining() {
        for(auto &bucket : buckets) {
            for(Pair *pair : bucket) {
                // 释放内存
                delete pair;
            }
        }
    }

    int hashFunc(int key) {
        return key % capacity;
    }

    // 负载因子 = 哈希表元素数量 / 哈希表容量
    double loadFactor(){
        return (double)size / (double) capacity;
    }

    /**
     * 查询
     */
    string get(int key) {
        int index = hashFunc(key);
        // 相当于找到头节点
        auto &bucket = buckets[index];
        // 类似往后遍历链表
        for(Pair *pair : bucket) {
            if(pair->key == key) {
                return pair->value;
            }
        }
        return nullptr;
    }

    /**
     * 添加
     */
    void put(int key, string value) {
        // 负载因子超过阈值，需要扩容
        if(loadThres < loadFactor()) {
            extend();
        }
        int index = hashFunc(key);
        // 若已有key，则更新对应的值
        for (auto &pair: buckets[index]) {
            if (pair->key == key) {
                pair->value = value;
                return;
            }
        }
        // 新key则添加进来
        buckets[index].push_back(new Pair(key, value));
        size++;
    }

    /**
     * 删除
     */
    void remove(int key) {
        int index = hashFunc(key);
        auto &bucket = buckets[index];
        for (int i = 0; i < bucket.size(); ++i) {
            if (bucket[i]->key == key) {
                Pair *tempPair = bucket[i];
                // 利用迭代器，删除键值对
                bucket.erase(bucket.begin() + i);
                // 释放内存
                delete tempPair;
                size--;
                return;
            }
        }
    }

    /**
     * 扩容
     */
    void extend() {
        // 暂存旧的桶
        vector<vector<Pair *>> bucketTemp = buckets;
        // 准备扩容大小
        capacity *= extendRatio;
        // 清除桶的内容
        buckets.clear();
        // 正式扩容
        buckets.resize(capacity);
        // 元素计数清零
        size = 0;
        // 将原哈希表中的键值对搬运到新的哈希表中
        for(auto &bucket : bucketTemp) {
            for(Pair *pair : bucket) {
                // put()函数已有size++，故此处无需size++
                put(pair->key, pair->value);
                // 释放内存
                delete pair;
            }
        }
    }
};