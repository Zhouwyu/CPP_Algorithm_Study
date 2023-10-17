//
// Created by zhou on 2023/10/7.
// 二叉树的层序遍历

#include "../utils/common.h"

/**
 * 利用队列实现层序遍历
 */
vector<int> levelOrder(TreeNode *root) {
    queue<TreeNode *> queue;
    // 存储节点的值
    vector<int> valSet;
    // 头节点入队
    queue.push(root);
    // 队列非空
    while (!queue.empty()) {
        // 只获取队头节点，并不出队
        TreeNode *node = queue.front();
        // 出队
        queue.pop();
        // 元素值记录
        valSet.push_back(node->val);
        // 左孩子非空入队
        if (node->left != nullptr) queue.push(node->left);
        // 右孩子非空入队
        if (node->right != nullptr) queue.push(node->right);
    }
    return valSet;
}
