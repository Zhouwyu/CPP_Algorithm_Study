//
// Created by zhou on 2023/12/15.
//
// 0-1背包 回溯法 物品装入背包重量不超过背包容量，前面1，2，3均是恰好等于背包容量W

#include <cstdio>

int n = 4;
int W = 6;
int w[] = {0, 5, 3, 2, 1};
int v[] = {0, 4, 4,3, 1};
int maxv = 0;
int best[20];

/**
 * 求最大价值上界
 * @param i 子集树的第几层，从1开始
 * @param tw 当前物品重量
 * @param tv 当前物品价值
 * @return 返回上界，即理论最大价值上限
 */
int upBound(int i, int tw, int tv) {
    // 从1开始
    i++;
    // 当未到叶子节点，且重量也未达到背包容量的时候
    while (i <= n && tw + w[i] <= W) {
        // 整个物品都加入背包中
        tw += w[i];
        tv += v[i];
        // 下一层
        i++;
    }
    // 若尚未抵达叶子节点，则背包剩余容量由当前物品的部分填充
    if (i <= n) return tv + (W - tw) * (v[i] / w[i]);
    // 已达到叶子节点的直接返回对应背包中物品价值
    else return tv;
}

/**
 * 回溯算法，其解空间就是一棵子集树
 * @param i 表示树的第几层，从1开始
 * @param tw 当前的重量
 * @param tv 当前的价值
 * @param op 当前解, op[i] = 1表示选择，op[i]=0表示不选
 */
void dfs(int i, int tw, int tv, int op[]) {
    // 到达叶子节点之后
    if (i > n) {
        // 若重量刚好满足且价值有更优解
        if (tw == W && tv > maxv) {
            // 存储最优解
            maxv = tv;
            for (int j = 1; j <=n ; ++j) {
                best[j] = op[j];
            }
        }
    } else {
        // 左剪枝
        if (tw + w[i] <= W) {
            // 选择当前第i个物品
            op[i] = 1;
            // 往左孩子走，即下一层，当前重量和价值都要累加
            dfs(i + 1, tw + w[i], tv + v[i], op);
        }
        // 当前最优解尚有机会能够达到理论上限，其实就是右剪枝
        if (upBound(i, tw, tv) > maxv) {
            // 不选择当前第i个物品
            op[i] = 0;
            // 往右孩子走，即下一层，当前重量和价值不变，其实就是回溯了
            dfs(i + 1, tw, tv, op);
        }
    }
}

int main(){
    int op[20];
    dfs(1, 0, 0, op);
    printf("maxvalue is:%d", maxv);
}