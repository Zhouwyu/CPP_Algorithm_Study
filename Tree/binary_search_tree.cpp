//
// Created by zhou on 2023/10/10.
// 基于二叉搜索树的增删查改

#include "../utils/common.h"

TreeNode * binarySearch(TreeNode *root, int val) {
    TreeNode *cur = root;
    while (cur != nullptr) {
        // 小的往左找
        if (cur->val > val) cur = cur->left;
        // 大的往右找
        else if (cur->val < val) cur = cur->right;
        // 找到跳出去
        else break;
    }
    // 最终返回结果节点
    return cur;
}

void addTreeNode(TreeNode *root, int val) {
    // 根节点为空，直接初始化为根节点
    if (root == nullptr) {
        root = new TreeNode(val);
        return;
    }

    TreeNode *cur = root;
    // 记录上一次的节点
    TreeNode *pre;
    // 不断循环直至到叶子节点为止
    while (cur != nullptr) {
        pre = cur;
        // 已存在的不准插入
        if (cur->val == val) return;
        else if (cur->val > val) cur = cur->left;
        else if (cur->val < val) cur = cur->right;
    }
    // 小的往左走，大的往右走
    if (pre->val < val) pre->right = new TreeNode(val);
    else if (pre->val > val) pre->left = new TreeNode(val);
}

void removeTreeNode(TreeNode *root, int val) {
    // 空树，直接结束
    if (root == nullptr) return;

    TreeNode *cur = root;
    TreeNode *pre;
    // 寻找需要删除的节点
    while (cur != nullptr) {
        pre = cur;
        // 找到跳出循环
        if (cur->val == val) break;
        else if (cur->val > val) cur = cur->left;
        else cur = cur->right;
    }
    // 没找到不用删
    if (cur == nullptr) return;

    // 度为0或1的操作，可能只有左孩子或右孩子，也可能两者皆有
    if (cur->left == nullptr || cur->right == nullptr) {
        // child可能是left, right, nullptr中的任一个
        TreeNode *child = cur->left != nullptr ? cur->left : cur->right;
        // 当前删除的不是根节点
        if (cur != root) {
            // 看删除的节点在左还是右，重新指向
            if (pre->left == cur) pre->left = child;
            else pre->right = child;
        } else {
            // 删除节点是根节点，则重新定义根节点
            root = child;
        }
        // 执行删除
        delete cur;
    }
    // 度为2的操作：需找左子树的最大节点或右子树的最小节点
    // 此处以找右子树的最小节点为例
    else {
        // 先从右子树着手
        TreeNode *tmp = cur->right;
        // 寻找最小节点（肯定是不断往左找，最左下角的就是）
        // 注意不要写成tmp != nullptr，这样写找到的是目标单位的左孩子，会导致空指针
        while (tmp->left != nullptr) {
            tmp = tmp->left;
        }
        // 记录下来当前值
        int tmpVal = tmp->val;
        // 最左下角的节点可能还有右子树，要把目标节点往前移相当于继续执行删除操作，因此递归
        removeTreeNode(root, tmpVal);
        // 最后把右子树的最小节点赋值给原来要删除的节点即可（通过换值完成删除）
        cur->val = tmpVal;
    }
}