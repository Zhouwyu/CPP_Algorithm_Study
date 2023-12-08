//
// Created by zhou on 2023/11/19.
//
#include "../utils/common.h"

int editDistance(string s, string t) {
    // 字符串s的长度
    int n = s.length();
    // 字符串t的长度
    int m = t.length();
    // 初始化dp表
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // 首列初始化。当t为空时，则需要对s进行删除，其最小编辑距离就是s的长度
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = i;
    }
    // 首行初始化。当s为空时，则需要对s进行添加操作，其最小编辑距离就是t的长度
    for (int j = 1; j <= m; ++j) {
        dp[0][j] = j;
    }
    // 填充dp表其余行列
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // 字符相等，无需操作
            if (s[i - 1] == t[j - 1]) {
                // 待匹配字符都减1即可
                dp[i][j] = dp[i - 1][j - 1];
            }
            // 字符不等
            else {
                // 三种情况：
                // 1. 添加操作。s添加一字符，t待比较字符减少，s原需要比较字符不变
                // 2. 替换操作。s和t需匹配字符都少一个
                // 3. 删除操作。s删除了一个字符，t不变化
                // 执行一个操作，操作数就+1，取三种情况最优情况即可
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j - 1]), dp[i - 1][j]) + 1;
            }
        }
    }
    return dp[n][m];
}

