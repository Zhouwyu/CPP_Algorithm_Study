//
// Created by zhou on 2023/10/10.
//
#include "../utils/common.h"

vector<int> vec;

/**
 * 前序：根-左-右
 */
void preOrder(TreeNode *root) {
    if (root == nullptr) return;
    vec.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}

/**
 * 中序：左-根-右
 */
void inOrder(TreeNode *root) {
    if (root == nullptr) return;
    inOrder(root->left);
    vec.push_back(root->val);
    inOrder(root->right);
}

/**
 * 后序：左-右-根
 */
void postOrder(TreeNode *root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    vec.push_back(root->val);
}