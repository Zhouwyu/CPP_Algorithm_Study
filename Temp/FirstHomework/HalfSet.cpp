/**
 *  ����һ����Ȼ��n����n��ʼ�������β���������set(n)�е������£�
 *  1��n����set(n)
 *  2����n����߼���һ����Ȼ����������Ȼ�����ܳ��������ӵ�����һ��
 *  3�����˹�����д���ֱ�������������Ȼ��Ϊֹ
 *
 *  ��ʽ��f(1)=1��f(n) = 1+��f(i) (1<=i<=n/2)
 *
 *  �����nʱ��Ӧ��������Ԫ�صĸ���
 */
#include <iostream>

using namespace std;

int generateHalfSet(int n) {
    // ����n+1���ȵ����飬��Ϊ����0λ�ò��ã�������1��ʼ�����ڴ洢��Ӧ��f(n)��ֵ
    int res[n + 1];
    // Ĭ��f(1)=1
    res[1] = 1;
    // ��f(2)��ʼ�����i��Ӧ����res�е�������Χ
    for (int i = 2; i <= n; i++) {
        // ʽ�����ʼ��1
        int sum = 1;
        // �������f(1)+f(2)+������+f(n/2)
        for (int j = 1; j <= i / 2; j++) {
            sum += res[j];
        }
        // ���ʹ����Ӧ��������
        res[i] = sum;
    }
    // ��Ҫ���ĸ�ֱ��ȡ��������
    return res[n];
}

int main() {
    int n = 6;
    int size = generateHalfSet(n);
    cout << "The size of set(" << n << ") is " << size << endl;
    return 0;
}
