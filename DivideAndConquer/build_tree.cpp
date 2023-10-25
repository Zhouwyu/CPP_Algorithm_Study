//
// Created by zhou on 2023/10/25.
// 给定一个二叉树的前序遍历 preorder 和中序遍历 inorder ，请从中构建二叉树，返回二叉树的根节点。

// 假设 i 为前序遍历中的根节点的索引，m为中序遍历中根节点的索引，[l, r]为中序遍历左子树到右子树的索引区间

#include "../utils/common.h"


// 利用一个哈希表存储中序遍历中的元素和索引的映射，即key为元素，value是对应索引
TreeNode* dfs(vector<int> &preOrder, vector<int> &inOrder, unordered_map<int, int> &hMap, int i, int l, int r) {
    // 左右子树区间为空，结束
    if(l > r) return nullptr;
    // 从前序遍历中取出，初始化根节点
    TreeNode* root = new TreeNode(preOrder[i]);
    // 取出当前根节点在中序遍历中的索引
    int m = hMap[preOrder[i]];
    // 左子树，此时前序遍历中根节点索引为 i + 1，中序遍历中左子树索引区间[l, m - 1]
    root->left = dfs(preOrder, inOrder, hMap, i + 1, l, m - 1);
    // m - l 为中序遍历中左子树中的节点个数
    // 右子树，此时前序遍历中根节点索引为 i + 1 + m - l，中序遍历中右子树索引区间[m + 1, r]
    root->right = dfs(preOrder, inOrder, hMap, i + 1 + (m - l), m + 1,  r);
    return root;
}

// 创建树，并返回根节点
TreeNode* createTree(vector<int> &preOrder, vector<int> &inOrder) {
    unordered_map<int, int> hMap;
    // 中序遍历的元素和索引映射
    for (int i = 0; i < inOrder.size(); ++i) {
        hMap[inOrder[i]] = i;
    }
    TreeNode* root = dfs(preOrder, inOrder, hMap, 0, 0, inOrder.size() - 1);
    return root;
}