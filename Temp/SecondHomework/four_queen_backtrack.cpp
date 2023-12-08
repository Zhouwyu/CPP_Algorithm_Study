//
// Created by zhou on 2023/12/6.
//
/**
 * 利用回溯算法解决4皇后问题
 */

#include "string"
using namespace std;

// 最大皇后数
#define N 20

// N表示行，q[N]表示列
int q[N];
// 统计解的数量
int solution_count = 0;

/**
 * 打印解
 */
void displaySolution(int n) {
    printf("%d solution:", ++solution_count);
    for (int i = 1; i <= n; ++i) {
        printf("(%d, %d)",i,q[i]);
    }
    printf("\n");
}

/**
 * 判断此位置放置皇后是否合法
 * @param i 第i行
 * @return true可放，否则不能放
 */
bool isValid(int i) {
    // 第一行无论什么时候都能放置
    if (i == 1) return true;
    // 用于与i比较
    int k = 1;
    // 因为皇后是从上往下放置的，故 k 无论什么时候都是1~(i-1)
    while (k < i) {
        // （同列 || 主/次对角线）都已有皇后，则不能放置
        if (q[i] == q[k] || abs(q[k] - q[i]) == abs(k - i)) {
            return false;
        }
        // 否则就继续往下试探是否可以放置皇后
        k++;
    }
    // 最终表明当前第i行可以放置
    return true;
}

/**
 * n皇后核心算法
 * @param n n个皇后
 */
void queens(int n) {
    // 当前行，也是第i个皇后
    int i = 1;
    // 初始化列从0开始
    q[i] = 0;
    while (i >= 1) {
        // 列向后移动
        q[i]++;
        // 未越界但位置不合法
        while (q[i] <= n && !isValid(i)) {
            // 列继续后移试探
            q[i]++;
        }
        // 合法位置且未越界
        if (q[i] <= n) {
            // 最后一行，直接输出解
            if (i == n) {
                displaySolution(n);
            }
            // 当前行处理完毕，处理下一行，重新初始化列从0开始
            else {
                i++;
                q[i]=0;
            }
        }
        // 证明此行遍历所有列都没有合适的位置，回溯到上一行（即上一个皇后）
        else{
            i--;
        }
    }
}
int main() {
    queens(4);
    return 0;
}