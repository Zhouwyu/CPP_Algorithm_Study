//
// Created by zhou on 2023/10/26.
// 复杂的回溯问题通常包含一个或多个约束条件，约束条件通常可用于“剪枝”。

// 在二叉树中搜索所有值为 7 的节点，请返回根节点到这些节点的路径，并要求路径中不包含值为 3 的节点。

#include "../utils/common.h"

void preOrder(TreeNode *root, vector<vector<TreeNode *>> &nodeList, vector<TreeNode *> &path) {
    // 剪枝，不能包含值为3的节点，则找到3的直接结束即可
    if (root == nullptr || root->val == 3) return;
    // 尝试
    path.push_back(root);
    // 记录解
    if (root->val == 7) nodeList.push_back(path);
    // 下一轮操作
    preOrder(root->left, nodeList, path);
    preOrder(root->right, nodeList, path);
    //回退
    path.pop_back();
}
