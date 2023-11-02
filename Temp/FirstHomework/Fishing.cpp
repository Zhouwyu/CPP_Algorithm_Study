/**
 * 某人想在h小时内钓到数量最多的鱼。这时他已经在一条路边，从他所在的地方开始，放眼望去，n个湖一字排开，
 * 湖编号依次是1.2…n。他已经知道，从湖i走到湖i+1需要花5*ti分钟;他在湖i钓鱼,第一个5分钟可钓到数量为fi的鱼，
 * 若他继续在湖i钓鱼,每过5分钟,钓鱼量将减少di。请给他设计一个最佳钓鱼方案。
 */
#include <iostream>
#include <vector>
using namespace std;

// 输入数据
int n, h;

// 初始化向量
vector<int> t(n);
vector<int> f(n);
vector<int> d(n);

// 计算当前湖最大钓鱼量
int calculateMaxFish(int lake, int timeLeft, vector<int>& fishRate, vector<int>& decline) {
    int maxFish = 0;
    for(int i=0; i<timeLeft; i++) {
        maxFish += fishRate[lake-1] - i*decline[lake-1];
    }
    return maxFish;
}

// 贪心算法
int greedyFisher() {
    int currentLake = 1, totalFish = 0;

    cin >> n >> h;

    for(int i=0; i<n; i++) {
        cin >> t[i];
    }

    for(int i=0; i<n; i++) {
        cin >> f[i];
    }

    for(int i=0; i<n; i++) {
        cin >> d[i];
    }

    while(currentLake <= n) {
        int maxFish = calculateMaxFish(currentLake, h, f, d);
        totalFish += maxFish;

        if(currentLake != n) {
            totalFish -= t[currentLake-1] * d[currentLake-1];
            currentLake++;
        }
    }

    return totalFish;
}

int main() {
    int result = greedyFisher();
    cout << result << endl;
    return 0;
}

