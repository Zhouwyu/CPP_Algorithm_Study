//
// Created by zhou on 2023/11/9.
//
#include "../utils/common.h"

int climbStairsDPOptimize(int n) {
    if (n == 1 || n == 2) return n;
    // 初始状态，预设最小问题的解
    int a = 1,b = 2;
    // 变量向后滚动
    for (int i = 3; i <= n ; ++i) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return b;
}

int main() {
    cout << climbStairsDPOptimize(6) << endl;
}
