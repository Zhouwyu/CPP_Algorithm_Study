//
// Created by zhou on 2023/10/26.
// 给定一个二叉树，搜索并记录所有值为 7 的节点，请返回节点列表。

#include "../utils/common.h"

// 利用前序遍历实现
void preOrder(TreeNode *root, vector<TreeNode *> &nodeList) {
    if(root == nullptr) return;
    // 记录值为7的节点
    if(root->val == 7) {
        // 节点加入列表
        nodeList.push_back(root);
    }
    preOrder(root->left, nodeList);
    preOrder(root->right, nodeList);
}


