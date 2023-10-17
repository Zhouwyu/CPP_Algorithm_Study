//
// Created by zhou on 2023/10/6.

// 数组实现哈希表

#include "../utils/common.h"


/**
 * 基于数组实现的哈希表
 */
class ArrayHashMap{
    private:
        vector<Pair *> buckets;

    public:
        ArrayHashMap(){
            // 初始化数组，包含100个桶
            buckets = vector<Pair *>(100);
        }

        ~ArrayHashMap() {
            // 释放内存
            for(const auto &bucket : buckets) {
                delete bucket;
            }
            buckets.clear();
        }

    /**
     * 哈希函数
     */
    int hashFunc(int key) {
        int index = key % 100;
        return index;
    }

    /**
     * 查询
     */
    string get(int key) {
        int index = hashFunc(key);
        Pair *pair = buckets[index];
        if (pair == nullptr) return nullptr;
        return pair->value;
    }

    /**
     * 添加
     */
    void put(int key, string value) {
        int index = hashFunc(key);
        Pair *pair = new Pair(key, value);
        buckets[index] = pair;
    }

    /**
     * 删除
     */
     void remove(int key) {
        int index = hashFunc(key);
        // 释放内存并置为空指针
        delete buckets[index];
        buckets[index] = nullptr;
     }

     /**
      * 获取所有键值对
      */
      vector<Pair *> pairSet() {
         vector<Pair *> pairSet;
         for (Pair *pair : buckets) {
             if (pair != nullptr) {
                 pairSet.push_back(pair);
             }
         }
         return pairSet;
      }

      /**
       * 获取所有键
       */
       vector<int> keySet() {
           vector<int> keySet;
          for (Pair *pair : buckets) {
              if (pair != nullptr) {
                  keySet.push_back(pair->key);
              }
          }
          return keySet;
       }

    /**
    * 获取所有值
    */
    vector<string> valueSet() {
        vector<string> valueSet;
        for (Pair *pair : buckets) {
            if (pair != nullptr) {
                valueSet.push_back(pair->value);
            }
        }
        return valueSet;
    }

    /**
     * 打印哈希表
     */
     void print() {
        for (Pair *kv : buckets) {
            cout << kv->key << "->" << kv->value << endl;
        }
     }
};