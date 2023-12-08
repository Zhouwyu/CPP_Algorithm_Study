//
// Created by zhou on 2023/12/7.
//
/**
* �������ȶ���ʽ��֧�޽編���4�ʺ�����
*/

#include <cstdio>
#include <cstdlib>
#include "vector"
#include "queue"

using namespace std;

// �ʺ����
int n = 4;
// ���ڼ�������нڵ�ĸ���
int node_count = 1;

// �����еĽڵ�
struct NodeType {
    // �ڵ���
    int no{};
    // ��ǰ�к�
    int row{};
    // ����ѷ��ûʺ���к�
    vector<int> cols;

    // ���رȽ������кŵ�������
    bool operator<(const NodeType &s) const {
        return row < s.row;
    }
};

/**
 * ��ӡ�ڵ�����
 * @param e ��ǰ�ڵ�
 */
void displayNode(NodeType e) {
    if (e.row != -1) {
        printf("��ţ�%d����Ӧλ�ã�%d, %d��\n", e.no, e.row, e.cols[e.row]);
    } else {
        printf("��ţ�%d����Ӧλ�ã�%d, *��\n", e.no, e.row);
    }
}

/**
 * �жϵ�ǰλ���Ƿ�Ϸ����Ϸ����ܷ��ûʺ�
 * @param cols
 * @param i �У�Ҫ�Żʺ����
 * @param j �У�Ҫ�Żʺ����
 * @return trueλ�úϷ�������Ƿ�
 */
bool isValid(vector<int> cols, int i, int j) {
    // ���ڱ�ʾ�ѷŻʺ����
    int k = 0;
    // k�ķ�Χ����0~i-1
    while (k < i) {
        // ͬ�� || �Խ���λ�����лʺ�
        if ((cols[k] == j) || (abs(cols[k] - j) == abs(k - i))) {
            return false;
        }
        k++;
    }
    return true;
}

/**
 * �����㷨ʵ��
 */
void queens() {
    int i, j;
    NodeType e, el;
    priority_queue<NodeType> queue;
    // �������ڵ�
    e.no = node_count++;
    // �кų�ʼ��Ϊ-1
    e.row = -1;
    // ���ڵ����
    queue.push(e);
    printf("���ӣ�");
    displayNode(e);
    // ���зǿ�ʱ
    while (!queue.empty()) {
        // ���ӽڵ���Ϊ��ǰ�ڵ�
        e = queue.top();
        queue.pop();
        printf("���ӣ�");
        displayNode(e);
        // ���統ǰ�ڵ���Ҷ�ӽڵ㣬��ӡ��
        if (e.row == n - 1) {
            printf("����һ���⣺");
            // �кţ��к���Ҫ��1��ʼ�����Ծ�+1
            for (i = 0; i < n; i++) {
                printf("[%d, %d]", i + 1, e.cols[i] + 1);
            }
            printf("\n");
            return;
        }
        // ����Ҷ�ӽڵ�
        else {
            // ���������У���ʵ���ǵ�ǰ�ڵ����еķ�֧
            for (j = 0; j < n; j++) {
                // ����� i ���ʺ�
                i = e.row + 1;
                // λ�úϷ�
                if (isValid(e.cols, i, j)) {
                    // ��ǰ�ڵ���ӽڵ�
                    el.no = node_count++;
                    // �кţ����ڷ��õ�ǰ�ʺ�
                    el.row = i;
                    el.cols = e.cols;
                    // ���뵱ǰ�ʺ���ռ�õ��к�
                    el.cols.push_back(j);
                    // �ӽڵ����
                    queue.push(el);
                    printf("�����ӽڵ㣺");
                    displayNode(el);
                }
            }
        }
    }
}

int main() {
    queens();
    return 0;
}