//
// Created by zhou on 2023/12/16.
//
// 0-1背包 分支限界法-队列式
#include "iostream"
#include "queue"

using namespace std;

#define MAXN 20

// 编号，也用作累计节点数
int total = 1;
// 3个物品，背包可容纳总重量30
int n = 3, W = 30;
// 物品重量列表
int w[] = {0, 16, 15, 15};
// 价值列表
int v[] = {0, 45, 25, 25};
// 最大价值
int maxv = -9999;
// 最优解集存放
int bestx[MAXN];

/**
 * 队列中的结点类型
 */
struct NodeType {
    // 节点编号，从1开始
    int no;
    // 当前节点在搜索树中的层次
    int i;
    // 当前节点的总重量
    int w;
    // 当前节点的总价值
    int v;
    // 临时存放解集
    int x[MAXN];
    // 上界
    double ub;
};
/**
 * 求上界
 * @param e 当前节点
 */
void bound(NodeType &e) {
    // 下一层次
    int i = e.i + 1;
    // 当前节点总重量
    int sumw = e.w;
    // 当前节点总价值
    double sumv = e.v;
    // 当背包还能容纳且还没到叶子节点的时候，继续拿
    while ((sumw + w[i]) <= W && i <= n) {
        sumw += w[i];
        sumv += v[i];
        i++;
    }
    // 最后再加会超重但还没到叶子节点的时候
    if (i <= n) {
        // 已有的总价值加上剩余重量再取部分物品装入填充的价值
        e.ub = sumv + (W - sumw) * (v[i] / w[i]);
    }
    // 已到叶子节点，直接取当前总价值
    else e.ub = sumv;
}
/**
 * 入队操作
 */
void enqueue(NodeType &e, queue<NodeType> &qu) {
    // 到达叶子节点
    if (e.i == n) {
        // 记录最优解
        if (e.v > maxv) {
            maxv = e.v;
            for (int j = 1; j <= n; j++) {
                bestx[j] = e.x[j];
            }
        }
    }
    // 未到则继续入队
    else {
        qu.push(e);
    }
}
/**
 * 核心算法
 */
void bfs() {
    int j;
    // 三个节点，根，左，右
    NodeType e, e1, e2;
    // 普通队列
    queue<NodeType> qu;
    // 根节点开始，初始化，层次从0开始
    e.i = 0;
    e.w = e.v = 0;
    // 第一个节点
    e.no = total++;
    // 将所有解集初始化为0
    for (j = 1; j <= n; j++) {
        e.x[j] = 0;
    }
    // 求根节点的上界
    bound(e);
    // 根节点入队
    qu.push(e);
    // 队列非空，循环持续
    while (!qu.empty()) {
        // 获取队头节点
        e = qu.front();
        // 出队
        qu.pop();
        // 若出队节点重量+下一层节点重量还小于背包容量时，可加入
        if (e.w + w[e.i + 1] <= W) {
            // 其实这就是开始构建左节点了
            // 编号
            e1.no = total++;
            // 表示在根节点的下一层
            e1.i = e.i + 1;
            // 计算左节点当前总重量
            e1.w = e.w + w[e1.i];
            // 计算左节点当前总价值
            e1.v = e.v + v[e1.i];
            // 将解集复制
            for (j = 1; j <= n; j++) {
                e1.x[j] = e.x[j];
            }
            // 标记为1，即选取了物品i
            e1.x[e1.i] = 1;
            // 计算左节点的上界
            bound(e1);
            // 左节点入队
            enqueue(e1, qu);
        }
        // 构建右节点的过程
        // 编号
        e2.no = total++;
        // 表示在根节点的下一层
        e2.i = e.i + 1;
        // 计算右节点当前总重量，右边是不选，所以重量和价值不变
        e2.w = e.w;
        // 计算右节点当前总价值
        e2.v = e.v;
        // 复制解集
        for (j = 1; j <= n; j++) {
            e2.x[j] = e.x[j];
        }
        // 表示不选物品i
        e2.x[e2.i] = 0;
        // 计算右节点的上界
        bound(e2);
        // 若最大价值还没达到上限，右节点入队
        if (e2.ub > maxv) {
            enqueue(e2, qu);
        }
    }
}

int main() {
    bfs();
    for (int i = 1; i <= n; ++i) {
        printf("%2d", bestx[i]);
    }
    printf("\tmaxvalue is: %d", maxv);
}
