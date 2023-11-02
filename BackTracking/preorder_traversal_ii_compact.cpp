//
// Created by zhou on 2023/10/26.

// 在二叉树中搜索所有值为 7 的节点，请返回根节点到这些节点的路径。

#include "../utils/common.h"

void preOrder(TreeNode *root, vector<vector<TreeNode *>> &nodeList, vector<TreeNode *> path) {
    if (root == nullptr) return;
    // 路径建立
    path.push_back(root);
    // 若当前节点值为7，则符合要求
    if (root->val == 7) {
        // 符合要求的一个路径加入结果集
        nodeList.push_back(path);
    }
    preOrder(root->left, nodeList, path);
    preOrder(root->right, nodeList, path);
    // 遍历到叶子节点后，需要回退，因此路径集应该pop一个出来
    path.pop_back();
}