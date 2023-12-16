//
// Created by zhou on 2023/12/14.
//
// ������-0-1��������

#include "vector"
#include <cstdio>

using namespace std;

// ����ݼ�
vector<vector<int>> ps;
/**
 * ��1~n���ݼ�ps����ʵ���Ǳ���װ��Ʒ�����з�������
 */
void PSet(int n) {
    // ���ݼ�����������
    vector<vector<int>> ps1;
    // �ݼ�������
    vector<vector<int>>::iterator it;
    // ��ʼ�ռ�
    vector<int> s;
    // ���ȼ���ռ�{}
    ps.push_back(s);
    for (int i = 1; i <= n; ++i) {
        // ps1�����һ�εõ��ķ�������
        ps1 = ps;
        // ��ʼ��������ps1��ÿ���������������i������Ӧ����Ʒ��ţ�
        for(it = ps1.begin(); it != ps1.end(); it++) {
            (*it).push_back(i);
        }
        // ��ps1�е�ÿ������Ԫ�ؼ���ps��
        for(it = ps1.begin(); it != ps1.end(); it++) {
            ps.push_back(*it);
        }
    }
}

/**
 * 0-1��������
 * @param w ��Ʒ�����б�
 * @param v ��Ʒ��ֵ�б�
 * @param W ��������
 */
void knap(int w[], int v[], int W) {
    // �������
    int count = 0;
    // ��ǰ���������������ܼ�ֵ
    int sumw, sumv;
    //���Ž�ķ�����ţ������ͼ�ֵ
    int maxi, maxsumw = 0, maxsumv = 0;
    // �ݼ�������
    vector<vector<int>>::iterator it;
    // �ݼ�����Ԫ�ص�����
    vector<int>::iterator sit;
    printf("���\tѡ����Ʒ\t������\t�ܼ�ֵ\t�ܷ�װ��\n");
    // �����ݼ�����ʵ���Ǳ�������
    for(it = ps.begin(); it != ps.end(); it++) {
        // �ڼ�������
        printf("%d\t", count + 1);
        // Ĭ�ϵ�ǰ����������ֵ����0
        sumv = sumw = 0;
        printf("{");
        // ��ÿ����������ȡ��Ӧ����Ʒ
        for(sit = (* it).begin(); sit != (* it).end(); sit++) {
            // �ڼ�����Ʒ
            printf("%d", *sit);
            // ��ȡ����Ʒ���ֵ�������ۼ�
            sumv += v[* sit - 1];
            sumw += w[* sit - 1];
        }
        printf("}\t\t%d\t%d\t", sumw, sumv);
        // ���統ǰ��������<��������ʱ��˵���˷�������
        if (sumw <= W) {
            printf("��\n");
            // ��¼���Ž⣬����еĻ�
            if (sumv > maxsumv) {
                maxsumv = sumv;
                maxsumw = sumw;
                maxi = count;
            }
        } else printf("��\n");
        // ��һ������
        count++;
    }
    printf("��ѷ���Ϊ��");
    printf("ѡ����Ʒ");
    printf("{");
    // ��ӡ���Ž�
    for(sit = ps[maxi].begin(); sit != ps[maxi].end(); sit++) {
        printf("%d ", *sit);
    }
    printf("}��");
    printf("��������%d���ܼ�ֵ��%d\n", maxsumw, maxsumv);
}

int main() {
    int n = 4, W = 6;
    int w[] = {5, 3, 2, 1};
    int v[] = {4, 4, 3, 1};
    PSet(n);
    printf("0/1������ⷽ����\n");
    knap(w, v, W);
}