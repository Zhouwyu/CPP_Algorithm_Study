/**
 * 某人想在h小时内钓到数量最多的鱼。这时他已经在一条路边，从他所在的地方开始，放眼望去，n个湖一字排开，
 * 湖编号依次是1.2…n。他已经知道，从湖i走到湖i+1需要花5*ti分钟;他在湖i钓鱼,第一个5分钟可钓到数量为fi的鱼，
 * 若他继续在湖i钓鱼,每过5分钟,钓鱼量将减少di。请给他设计一个最佳钓鱼方案。
 */
#include<bits/stdc++.h>

using namespace std;
#define NUM 30
// 每5分钟为一个周期
// 表示每个湖初始可钓鱼数量
int fi[NUM];
// 表示经过一个周期后fi[i]对应湖里鱼减少的数量
int di[NUM];
// 表示从湖i到湖i+1需要的时间
int ti[NUM];
// 最优钓鱼计划
int plan[NUM];
// 最多的钓鱼数量
int best;

/**
 * 利用贪心算法
 * @param pos 第几个湖
 * @param time 剩余的时间
 */
void greedy(int pos, int time) {
    // 没时间了直接结束
    if (time <= 0) return;
    int i, j;
    // 用于存储在每个湖中钓到的鱼的数量
    int tempFish[NUM];
    // 临时计划数组，避免影响原plan数组内容
    int tempPlan[NUM];
    // 总钓鱼数
    int total = 0;
    // 将每个湖中鱼的数量复制到临时数组tempFish中进行初始化
    for (i = 0; i < pos; ++i)
        tempFish[i] = fi[i];
    // 在剩余的时间内
    for (i = 0; i < time; ++i) {
        int max = 0;
        int id = -1;
        // 找到捕获量最大的湖和鱼
        for (j = 0; j < pos; ++j)
            if (tempFish[j] > max) {
                max = tempFish[j];
                id = j;
            }
        // 更新计划和总量和鱼剩余的数量
        if (id != -1) {
            ++tempPlan[id];
            tempFish[id] -= di[id];
            total += max;
        } else ++tempPlan[0];
    }
    // 如果目前钓到的鱼比目前最优的更好，更新最优解
    if (total > best) {
        best = total;
        for (i = 0; i < pos; ++i)
            plan[i] = tempPlan[i];
    }
}

/*
输入示例：
2 1
10 1
2 5
2
*/
int main() {
    int n, h;
    cout << "请输入湖数与可用小时数，以空格为间隔：" << endl;
    cin >> n >> h;
    cout << "请输入初始鱼的数量：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> fi[i];
    }
    cout << "请输入一个周期鱼减少的数量：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> di[i];
    }
    cout << "请输入从湖i到湖i+1花费的时间（以分钟为计量单位）：" << endl;
    for (int i = 0; i < n - 1; i++) {
        cin >> ti[i];
    }
    // 一小时60分钟，5分钟一个周期，则一小时有12个周期，这样记录为钓一次鱼
    h = h * 12;
    int time = 0;
    // 最多钓鱼数量初始化为-1
    best = -1;
    for (int i = 1; i <= n && h - time; i++) {
        greedy(i, h - time);
        time += ti[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cout << plan[i] * 5 << endl;
    }
    cout << plan[n - 1] * 5 << endl;
    cout << "总的钓鱼数量:" << best << endl;
}
