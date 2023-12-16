//
// Created by zhou on 2023/12/15.
//
// 0-1背包问题 动态规划
#include <cstdio>
#include "iostream"

using namespace std;

int n = 5;
int W = 10;
int w[20] = {0, 2, 2, 6, 5, 4};
int v[20] = {0, 6, 3, 5, 4, 6};
int dp[20][20];
int x[20];
int maxv;

/**
 * dp核心算法
 */
void knap() {
    // i表示第几个物品，r表示当前背包的重量
    int i, r;
    // 边界条件初始化，首列即背包容量为空的时候，价值为0
    for (i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    // 首行即无物品可放的时候，价值为0
    for (r = 0; r <= W; r++) {
        dp[0][r] = 0;
    }
    // 填充dp数组
    for (i = 1; i <= n; i++) {
        for (r = 1; r <= W; r++) {
            // 若当前物品重量已超过当前背包容量，则不能放入，背包容量将由剩下可能的i-1个物品填充
            if (r < w[i]) {
                dp[i][r] = dp[i - 1][r];
            } else {
                // 当前物品容量<当前背包容量，则有两种选择，放或不放
                // 不放：背包容量不变，将由i-1个物品填充；放：背包容量变化，剩下的容量将由i-1个物品填充，加上当前所选物品的价值
                dp[i][r] = max(dp[i - 1][r], dp[i - 1][r - w[i]] + v[i]);
            }
        }
    }
}

/**
 * 自底向上求最优解
 */
void buildX() {
    int i = n, r = W;
    maxv = 0;
    while (i >= 0) {
        // 即都是选了物品的
        if (dp[i][r] != dp[i-1][r]) {
            // 标记选了哪个物品，索引i表示第i个
            x[i] = 1;
            // 记录其价值
            maxv += v[i];
            // 背包容量变化
            r -= w[i];
        } else {
            // 不选
            x[i] = 0;
        }
        i--;
    }
}

int main() {
    knap();
    buildX();
    printf("所选物品：");
    for (int i = 1; i <= n; ++i) {
        if (x[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n总价值：%d", maxv);
}
