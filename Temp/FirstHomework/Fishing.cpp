/**
 * 某人想在h小时内钓到数量最多的鱼。这时他已经在一条路边，从他所在的地方开始，放眼望去，n个湖一字排开，
 * 湖编号依次是1.2…n。他已经知道，从湖i走到湖i+1需要花5*ti分钟;他在湖i钓鱼,第一个5分钟可钓到数量为fi的鱼，
 * 若他继续在湖i钓鱼,每过5分钟,钓鱼量将减少di。请给他设计一个最佳钓鱼方案。
 */
#include <iostream>
#include <vector>

#define MAX 30

using namespace std;

int n = 2;
int h = 1;
int fi[MAX] = {0, 10, 1};
int di[MAX] = {0, 2, 5};
int ti[MAX] = {0, 2};
int cfi[MAX];

struct NodeType{
    int num[MAX];
    int max;
} Lake[MAX];
int maxList;

int getMax(int p[], int i, int j) {
    int maxi = i;
    for(int k = i + 1; k <= j; k++) {
        if(p[maxi] < p[k]) {
            maxi = k;
        }
    }
    return maxi;
}

void solve() {
    int i, j, t, restT;
    int T = 60 * h;
    for(j = 1; j <= i; j++) {
        cfi[]
    }
}

