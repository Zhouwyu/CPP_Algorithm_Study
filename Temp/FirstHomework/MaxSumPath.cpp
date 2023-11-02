//
// 参考二叉树中最大和的路径的实现方式，实现输出从根节点分别到所有叶子结点路径中，值为中位数的路径以及该中位数的值
//
#include "vector"
#include "iostream"
using std::vector;
using std::cin;
using std::cout;
using std::endl;

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

// 遍历二叉树时用于存储遍历过的节点，记录路径
vector<int> paths;
// 用于记录节点和最大的路径
vector<int> maxPath;
// 用于记录最大和
int maxSum = INT_MIN;
/**
 * 深度优先搜索
 */
void dfs(TreeNode *root) {
    // 递归结束条件，空树直接结束
    if (root == nullptr) return;
    // 非空，记录当前节点的值
    paths.push_back(root->val);
    // 遍历到叶子节点时，求路径上节点值的和
    if(root->left == nullptr && root->right == nullptr) {
        int tempSum = 0;
        for (const auto &item: paths) tempSum += item;
        // 记录最大路径和
        if (tempSum > maxSum) maxSum = tempSum;
        // 记录和最大的路径节点值
        maxPath.clear();
        maxPath = paths;
    }
    // 继续遍历剩余的子树
    dfs(root->left);
    dfs(root->right);
    // 回溯
    paths.pop_back();
}

/**
 * 求中位数路径
 */
vector<int> midPath(vector<int> &path) {
    int size = (int)path.size();
    vector<int> midPath;
    // 中位数索引
    int mid = (size - 1) / 2;
    if (size % 2 == 0) {
        // 数组元素个数为偶数时，中位数有两个，用于记录mid+1的索引
        int midPlus = mid + 1;
        midPath.push_back(path[midPlus]);
    }
    // 数组元素个数为奇数时，中位数只有一个
    midPath.push_back(path[mid]);
    return midPath;
}

int main() {
    TreeNode *root = new TreeNode(5);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(4);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(1);
    TreeNode *node5 = new TreeNode(6);
    root->left = node1;
    root->right = node2;
    node1->right = node3;
    node2->left = node4;
    node2->left = node5;

    dfs(root);

    cout << "最大路径：" << endl;
    for (int i = 0; i < maxPath.size(); ++i) {
        cout << maxPath[i] << endl;
    }

    cout << "中位数路径：" << endl;
    vector<int> path = midPath(maxPath);
    for (const auto &item: path) {
        cout << item << endl;
    }
}