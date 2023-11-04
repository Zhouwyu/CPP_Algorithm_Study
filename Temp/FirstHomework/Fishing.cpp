/**
 * ĳ������hСʱ�ڵ������������㡣��ʱ���Ѿ���һ��·�ߣ��������ڵĵط���ʼ��������ȥ��n����һ���ſ���
 * �����������1.2��n�����Ѿ�֪�����Ӻ�i�ߵ���i+1��Ҫ��5*ti����;���ں�i����,��һ��5���ӿɵ�������Ϊfi���㣬
 * ���������ں�i����,ÿ��5����,������������di����������һ����ѵ��㷽����
 */
#include<bits/stdc++.h>

using namespace std;
#define NUM 30
// ÿ5����Ϊһ������
// ��ʾÿ������ʼ�ɵ�������
int fi[NUM];
// ��ʾ����һ�����ں�fi[i]��Ӧ��������ٵ�����
int di[NUM];
// ��ʾ�Ӻ�i����i+1��Ҫ��ʱ��
int ti[NUM];
// ���ŵ���ƻ�
int plan[NUM];
// ���ĵ�������
int best;

/**
 * ����̰���㷨
 * @param pos �ڼ�����
 * @param time ʣ���ʱ��
 */
void greedy(int pos, int time) {
    // ûʱ����ֱ�ӽ���
    if (time <= 0) return;
    int i, j;
    // ���ڴ洢��ÿ�����е������������
    int tempFish[NUM];
    // ��ʱ�ƻ����飬����Ӱ��ԭplan��������
    int tempPlan[NUM];
    // �ܵ�����
    int total = 0;
    // ��ÿ����������������Ƶ���ʱ����tempFish�н��г�ʼ��
    for (i = 0; i < pos; ++i)
        tempFish[i] = fi[i];
    // ��ʣ���ʱ����
    for (i = 0; i < time; ++i) {
        int max = 0;
        int id = -1;
        // �ҵ����������ĺ�����
        for (j = 0; j < pos; ++j)
            if (tempFish[j] > max) {
                max = tempFish[j];
                id = j;
            }
        // ���¼ƻ�����������ʣ�������
        if (id != -1) {
            ++tempPlan[id];
            tempFish[id] -= di[id];
            total += max;
        } else ++tempPlan[0];
    }
    // ���Ŀǰ���������Ŀǰ���ŵĸ��ã��������Ž�
    if (total > best) {
        best = total;
        for (i = 0; i < pos; ++i)
            plan[i] = tempPlan[i];
    }
}

/*
����ʾ����
2 1
10 1
2 5
2
*/
int main() {
    int n, h;
    cout << "��������������Сʱ�����Կո�Ϊ�����" << endl;
    cin >> n >> h;
    cout << "�������ʼ���������" << endl;
    for (int i = 0; i < n; i++) {
        cin >> fi[i];
    }
    cout << "������һ����������ٵ�������" << endl;
    for (int i = 0; i < n; i++) {
        cin >> di[i];
    }
    cout << "������Ӻ�i����i+1���ѵ�ʱ�䣨�Է���Ϊ������λ����" << endl;
    for (int i = 0; i < n - 1; i++) {
        cin >> ti[i];
    }
    // һСʱ60���ӣ�5����һ�����ڣ���һСʱ��12�����ڣ�������¼Ϊ��һ����
    h = h * 12;
    int time = 0;
    // ������������ʼ��Ϊ-1
    best = -1;
    for (int i = 1; i <= n && h - time; i++) {
        greedy(i, h - time);
        time += ti[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cout << plan[i] * 5 << endl;
    }
    cout << plan[n - 1] * 5 << endl;
    cout << "�ܵĵ�������:" << best << endl;
}
