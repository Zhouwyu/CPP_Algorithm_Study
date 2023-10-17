//
// Created by zhou on 2023/10/10.
//
#include "../utils/common.h"



/**
 * 数组表示二叉树
 */
class ArrayBinaryTree {
private:
    vector<int> tree;

    void dfs(int index, string order, vector<int> &res) {
        if(val(index) == INT_MAX) return;
        // 前序遍历
        if(order == "pre") {
            res.push_back(val(index));
        }
        dfs(left(index), order, res);
        // 中序遍历
        if(order == "in") {
            res.push_back(val(index));
        }
        dfs(right(index), order, res);
        // 后序遍历
        if (order == "post") {
            res.push_back(val(index));
        }
    }
public:

    ArrayBinaryTree(vector<int> arr) {
        tree = arr;
    }

    /**
     * 数组长度
     */
    int size() {
        return tree.size();
    }

    /**
     * 索引对应的值
     */
    int val(int i) {
        // 越界处理
        if(i < 0 || i >= size()) {
            return INT_MAX;
        }
        return tree[i];
    }

    /**
     * 左孩子的索引
     */
    int left(int i) {
        return 2 * i + 1;
    }

    /**
     * 右孩子的索引
     */
    int right(int i) {
        return 2 * i + 2;
    }

    /**
     * 找当前索引的父索引
     */
    int parent(int i) {
        if (i == 0) return 0;
        return (i - 1) / 2;
    }

    /**
     * 直接遍历数组就是层序遍历的结果
     */
    vector<int> levelOrder() {
        vector<int> res;
        for(int i = 0; i < size(); i++) {
            // 不是空位就记录下来
            if(tree[i] != INT_MAX) {
                res.push_back(val(i));
            }
        }
        return res;
    }

    vector<int> preOrder() {
        vector<int> res;
        dfs(0, "pre", res);
        return res;
    }

    vector<int> inOrder() {
        vector<int> res;
        dfs(0, "in", res);
        return res;
    }

    vector<int> postOrder() {
        vector<int> res;
        dfs(0, "post", res);
        return res;
    }
};