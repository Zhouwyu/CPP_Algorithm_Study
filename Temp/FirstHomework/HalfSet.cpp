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

using namespace std;

int generateHalfSet(int n) {
    // 定义n+1长度的数组，因为索引0位置不用，从索引1开始，用于存储对应的f(n)的值
    int res[n + 1];
    // 默认f(1)=1
    res[1] = 1;
    // 从f(2)开始，这个i对应的是res中的索引范围
    for (int i = 2; i <= n; i++) {
        // 式子中最开始的1
        int sum = 1;
        // 求和运算f(1)+f(2)+···+f(n/2)
        for (int j = 1; j <= i / 2; j++) {
            sum += res[j];
        }
        // 将和存进对应的索引中
        res[i] = sum;
    }
    // 需要求哪个直接取出来即可
    return res[n];
}

int main() {
    int n = 6;
    int size = generateHalfSet(n);
    cout << "The size of set(" << n << ") is " << size << endl;
    return 0;
}
