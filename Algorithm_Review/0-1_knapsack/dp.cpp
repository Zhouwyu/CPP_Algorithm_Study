//
// Created by zhou on 2023/12/15.
//
// 0-1�������� ��̬�滮
#include <cstdio>
#include "iostream"

using namespace std;

int n = 5;
int W = 10;
int w[20] = {0, 2, 2, 6, 5, 4};
int v[20] = {0, 6, 3, 5, 4, 6};
int dp[20][20];
int x[20];
int maxv;

/**
 * dp�����㷨
 */
void knap() {
    // i��ʾ�ڼ�����Ʒ��r��ʾ��ǰ����������
    int i, r;
    // �߽�������ʼ�������м���������Ϊ�յ�ʱ�򣬼�ֵΪ0
    for (i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    // ���м�����Ʒ�ɷŵ�ʱ�򣬼�ֵΪ0
    for (r = 0; r <= W; r++) {
        dp[0][r] = 0;
    }
    // ���dp����
    for (i = 1; i <= n; i++) {
        for (r = 1; r <= W; r++) {
            // ����ǰ��Ʒ�����ѳ�����ǰ�������������ܷ��룬������������ʣ�¿��ܵ�i-1����Ʒ���
            if (r < w[i]) {
                dp[i][r] = dp[i - 1][r];
            } else {
                // ��ǰ��Ʒ����<��ǰ������������������ѡ�񣬷Ż򲻷�
                // ���ţ������������䣬����i-1����Ʒ��䣻�ţ����������仯��ʣ�µ���������i-1����Ʒ��䣬���ϵ�ǰ��ѡ��Ʒ�ļ�ֵ
                dp[i][r] = max(dp[i - 1][r], dp[i - 1][r - w[i]] + v[i]);
            }
        }
    }
}

/**
 * �Ե����������Ž�
 */
void buildX() {
    int i = n, r = W;
    maxv = 0;
    while (i >= 0) {
        // ������ѡ����Ʒ��
        if (dp[i][r] != dp[i-1][r]) {
            // ���ѡ���ĸ���Ʒ������i��ʾ��i��
            x[i] = 1;
            // ��¼���ֵ
            maxv += v[i];
            // ���������仯
            r -= w[i];
        } else {
            // ��ѡ
            x[i] = 0;
        }
        i--;
    }
}

int main() {
    knap();
    buildX();
    printf("��ѡ��Ʒ��");
    for (int i = 1; i <= n; ++i) {
        if (x[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n�ܼ�ֵ��%d", maxv);
}