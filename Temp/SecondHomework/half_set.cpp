//
// Created by zhou on 2023/12/6.
//

/**
 *  给定一个自然数n，由n开始可以依次产生半数集set(n)中的数如下：
 *  1、n属于set(n)
 *  2、在n的左边加上一个自然数，但该自然数不能超过最近添加的数的一半
 *  3、按此规则进行处理，直到不能再添加自然数为止
 *
 *  有式子f(1)=1，f(n) = 1+∑f(i) (1<=i<=n/2)
 *
 *  求给定n时对应半数集中元素的个数
 */
#include <iostream>
#include "vector"

using namespace std;

/**
 * 动态规划实现
 * @param n 自然数n
 * @return 半数集中元素个数
 */
int generateHalfSetDP(int n) {
    // 定义一个n+1长度的列表，方便下标从1开始，用于存储每一次求得的半数集中元素的个数，即f(n)
    // 另外初始化所有值为1，其实就是式子中的1，每次求和后都+1
    vector<int> dp(n + 1, 1);
    // 从第二个开始
    for (int i = 2; i <= n; ++i) {
        // 状态转移方程
        for (int j = 1; j <= i / 2; ++j) {
            dp[i] += dp[j];
        }
    }
    // 最终dp数组中最后一个值就是所求
    return dp[n];
}

/**
 * 可以利用滚动数组进行空间优化
 * 还存在问题未解决
 */
int generateHalfSetScrollDP(int n) {
    vector<int> dp(2);
    // 初始化dp
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[0] = 1;
        // 状态转移方程, 利用dp[0]进行运算
        for (int j = 1; j <= i / 2; ++j) {
            dp[0] += dp[0];
        }
        // 对应函数和存于dp[1]中
        dp[1] = dp[0];
    }
    return dp[1];
}

int main() {
    int n = 5;
    int size = generateHalfSetDP(n);
    cout << "The size of set(" << n << ") is " << size << endl;
    size = generateHalfSetScrollDP(n);
    cout << "\nThe size of set(" << n << ") is " << size << endl;
    return 0;
}
