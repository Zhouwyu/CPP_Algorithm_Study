//
// Created by zhou on 2023/12/7.
//
/**
* 利用优先队列式分支限界法解决4皇后问题
*/

#include <cstdio>
#include <cstdlib>
#include "vector"
#include "queue"

using namespace std;

// 皇后个数
int n = 4;
// 用于计算队列中节点的个数
int node_count = 1;

// 队列中的节点
struct NodeType {
    // 节点编号
    int no{};
    // 当前行号
    int row{};
    // 存放已放置皇后的列号
    vector<int> cols;

    // 重载比较器，行号递增排序
    bool operator<(const NodeType &s) const {
        return row < s.row;
    }
};

/**
 * 打印节点内容
 * @param e 当前节点
 */
void displayNode(NodeType e) {
    if (e.row != -1) {
        printf("编号：%d，对应位置（%d, %d）\n", e.no, e.row, e.cols[e.row]);
    } else {
        printf("编号：%d，对应位置（%d, *）\n", e.no, e.row);
    }
}

/**
 * 判断当前位置是否合法，合法则能放置皇后
 * @param cols
 * @param i 行，要放皇后的行
 * @param j 列，要放皇后的列
 * @return true位置合法，否则非法
 */
bool isValid(vector<int> cols, int i, int j) {
    // 用于表示已放皇后的行
    int k = 0;
    // k的范围处于0~i-1
    while (k < i) {
        // 同列 || 对角线位置已有皇后
        if ((cols[k] == j) || (abs(cols[k] - j) == abs(k - i))) {
            return false;
        }
        k++;
    }
    return true;
}

/**
 * 核心算法实现
 */
void queens() {
    int i, j;
    NodeType e, el;
    priority_queue<NodeType> queue;
    // 建立根节点
    e.no = node_count++;
    // 行号初始化为-1
    e.row = -1;
    // 根节点入队
    queue.push(e);
    printf("进队：");
    displayNode(e);
    // 队列非空时
    while (!queue.empty()) {
        // 出队节点作为当前节点
        e = queue.top();
        queue.pop();
        printf("出队：");
        displayNode(e);
        // 假如当前节点是叶子节点，打印解
        if (e.row == n - 1) {
            printf("产生一个解：");
            // 行号，列号需要从1开始，所以均+1
            for (i = 0; i < n; i++) {
                printf("[%d, %d]", i + 1, e.cols[i] + 1);
            }
            printf("\n");
            return;
        }
        // 不是叶子节点
        else {
            // 遍历所有列，其实就是当前节点所有的分支
            for (j = 0; j < n; j++) {
                // 考察第 i 个皇后
                i = e.row + 1;
                // 位置合法
                if (isValid(e.cols, i, j)) {
                    // 当前节点的子节点
                    el.no = node_count++;
                    // 行号，用于放置当前皇后
                    el.row = i;
                    el.cols = e.cols;
                    // 加入当前皇后所占用的列号
                    el.cols.push_back(j);
                    // 子节点入队
                    queue.push(el);
                    printf("进队子节点：");
                    displayNode(el);
                }
            }
        }
    }
}

int main() {
    queens();
    return 0;
}