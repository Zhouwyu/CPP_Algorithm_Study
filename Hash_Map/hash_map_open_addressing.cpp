//
// Created by zhou on 2023/10/6.
//

#include "../utils/common.h"

class HashMapOpenAddressing {
private:
    // 元素数量
    int size;
    // 桶数组容量
    int capacity;
    // 负载因子阈值
    double loadThres;
    // 扩容倍数
    int extendRatio;
    // 桶数组
    vector<Pair *> buckets;
    // 移除标记
    Pair* removed;

public:
    HashMapOpenAddressing() {
        size = 0;
        capacity = 4;
        loadThres = 2.0 / 3.0;
        extendRatio = 2;
        // 初始化桶
        buckets = vector<Pair *>(capacity, nullptr);
        // 初始化removed标记
        removed = new Pair(-1, "-1");
    }

    int hashFunc(int key) {
        return key % capacity;
    }

    // static_cast 用于将size类型转换成double
    double loadFactor() {
        return static_cast<double>(size) / capacity;
    }

    /**
     * 查询
     */
    string get(int key) {
        int index = hashFunc(key);
        // 线性探测
        for (int i = 0; i < capacity; ++i) {
            // 找到最尾回到头部
            int j = (index + i) % capacity;
            // 若然是空桶，则没找到
            if(buckets[j] == nullptr) {
                return nullptr;
            }
            // 若找到了而且对应位置上元素未被移除，则是所找
            if(buckets[j]->key == key && buckets[j] != removed) {
                return buckets[j]->value;
            }
        }
        return nullptr;
    }

    /**
     * 添加
     */
    void put(int key, string value) {
        // 负载因子超出阈值，需要扩容
        if (loadThres < loadFactor()) {
            extend();
        }
        int index = hashFunc(key);
        for (int i = 0; i < capacity; ++i) {
            int j = (index + i) % capacity;
            // 若是空桶或已被移除，则直接添加新的即可
            if (buckets[j] == nullptr || buckets[j] == removed) {
                buckets[j] = new Pair(key, value);
                size++;
                return;
            }
            // 若已有相同的key，则更新对应的值
            if (buckets[j]->key == key) {
                buckets[j]->value = value;
                return;
            }
        }
    }

    /**
     * 删除
     */
    void remove(int key) {
        int index = hashFunc(key);
        for (int i = 0; i < capacity; ++i) {
            int j = (index + i) % capacity;
            // 空桶，没找到，不用删
            if (buckets[j] == nullptr) return;
            // 找到，移除，并做标记
            if(buckets[j]->key == key) {
                delete buckets[j];
                buckets[j] = removed;
                size--;
                return;
            }
        }
    }

    /**
     * 扩容
     */
    void extend() {
        // 暂存在临时桶
        vector<Pair *> tempBucket = buckets;
        // 扩容
        capacity *= extendRatio;
        // 初始化新桶
        buckets = vector<Pair *>(capacity, nullptr);
        size = 0;
        // 将元素移入新桶
        for (auto &pair: tempBucket) {
            // 如果不是空的而且没有移除标记的，则是需要移入的元素
            if (pair != nullptr && pair != removed) {
                put(pair->key, pair->value);
            }
        }
    }
};
