//
// Created by zhou on 2023/10/6.
//

#ifndef C___ALGORITHM_COMMON_H
#define C___ALGORITHM_COMMON_H

#include "iostream"
#include "string"
#include "vector"
#include "queue"
#include "functional"
#include "unordered_set"

using namespace std;

using std::string;
using std::vector;
using std::queue;
using std::priority_queue;
using std::greater;
using std::less;
using std::cin;
using std::cout;
using std::endl;

/**
 * 哈希表键值对
 */
struct Pair{
public:
    int key;
    string value;
    Pair(int key, string value){
        this->key = key;
        this->value = value;
    }
};

/**
 * 二叉树
 */
struct TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * 图顶点
 */
 struct Vertex{
 public:
     int val;
     Vertex(int x) : val(x){}
 };

#endif //C___ALGORITHM_COMMON_H
