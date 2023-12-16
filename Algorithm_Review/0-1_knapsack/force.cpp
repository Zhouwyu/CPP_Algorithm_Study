//
// Created by zhou on 2023/12/14.
//
// 蛮力法-0-1背包问题

#include "vector"
#include <cstdio>

using namespace std;

// 存放幂集
vector<vector<int>> ps;
/**
 * 求1~n的幂集ps，其实就是背包装物品的所有方案集合
 */
void PSet(int n) {
    // 子幂集，辅助作用
    vector<vector<int>> ps1;
    // 幂集迭代器
    vector<vector<int>>::iterator it;
    // 初始空集
    vector<int> s;
    // 首先加入空集{}
    ps.push_back(s);
    for (int i = 1; i <= n; ++i) {
        // ps1存放上一次得到的方案集合
        ps1 = ps;
        // 开始遍历，在ps1的每个集合中添加索引i（即对应的物品编号）
        for(it = ps1.begin(); it != ps1.end(); it++) {
            (*it).push_back(i);
        }
        // 将ps1中的每个集合元素加入ps中
        for(it = ps1.begin(); it != ps1.end(); it++) {
            ps.push_back(*it);
        }
    }
}

/**
 * 0-1背包核心
 * @param w 物品重量列表
 * @param v 物品价值列表
 * @param W 背包容量
 */
void knap(int w[], int v[], int W) {
    // 方案编号
    int count = 0;
    // 当前方案的总重量和总价值
    int sumw, sumv;
    //最优解的方案编号，重量和价值
    int maxi, maxsumw = 0, maxsumv = 0;
    // 幂集迭代器
    vector<vector<int>>::iterator it;
    // 幂集集合元素迭代器
    vector<int>::iterator sit;
    printf("序号\t选中物品\t总重量\t总价值\t能否装入\n");
    // 遍历幂集，其实就是遍历方案
    for(it = ps.begin(); it != ps.end(); it++) {
        // 第几个方案
        printf("%d\t", count + 1);
        // 默认当前方案重量价值都是0
        sumv = sumw = 0;
        printf("{");
        // 从每个方案中拿取对应的物品
        for(sit = (* it).begin(); sit != (* it).end(); sit++) {
            // 第几个物品
            printf("%d", *sit);
            // 拿取了物品则价值和重量累加
            sumv += v[* sit - 1];
            sumw += w[* sit - 1];
        }
        printf("}\t\t%d\t%d\t", sumw, sumv);
        // 假如当前方案重量<背包容量时，说明此方案可行
        if (sumw <= W) {
            printf("能\n");
            // 记录最优解，如果有的话
            if (sumv > maxsumv) {
                maxsumv = sumv;
                maxsumw = sumw;
                maxi = count;
            }
        } else printf("否\n");
        // 下一个方案
        count++;
    }
    printf("最佳方案为：");
    printf("选中物品");
    printf("{");
    // 打印最优解
    for(sit = ps[maxi].begin(); sit != ps[maxi].end(); sit++) {
        printf("%d ", *sit);
    }
    printf("}，");
    printf("总重量：%d，总价值：%d\n", maxsumw, maxsumv);
}

int main() {
    int n = 4, W = 6;
    int w[] = {5, 3, 2, 1};
    int v[] = {4, 4, 3, 1};
    PSet(n);
    printf("0/1背包求解方案：\n");
    knap(w, v, W);
}