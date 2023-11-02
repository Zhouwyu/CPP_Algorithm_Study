//
// �ο������������͵�·����ʵ�ַ�ʽ��ʵ������Ӹ��ڵ�ֱ�����Ҷ�ӽ��·���У�ֵΪ��λ����·���Լ�����λ����ֵ
//
#include "vector"
#include "iostream"
using std::vector;
using std::cin;
using std::cout;
using std::endl;

/**
 * ������
 */
struct TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ����������ʱ���ڴ洢�������Ľڵ㣬��¼·��
vector<int> paths;
// ���ڼ�¼�ڵ������·��
vector<int> maxPath;
// ���ڼ�¼����
int maxSum = INT_MIN;
/**
 * �����������
 */
void dfs(TreeNode *root) {
    // �ݹ��������������ֱ�ӽ���
    if (root == nullptr) return;
    // �ǿգ���¼��ǰ�ڵ��ֵ
    paths.push_back(root->val);
    // ������Ҷ�ӽڵ�ʱ����·���Ͻڵ�ֵ�ĺ�
    if(root->left == nullptr && root->right == nullptr) {
        int tempSum = 0;
        for (const auto &item: paths) tempSum += item;
        // ��¼���·����
        if (tempSum > maxSum) maxSum = tempSum;
        // ��¼������·���ڵ�ֵ
        maxPath.clear();
        maxPath = paths;
    }
    // ��������ʣ�������
    dfs(root->left);
    dfs(root->right);
    // ����
    paths.pop_back();
}

/**
 * ����λ��·��
 */
vector<int> midPath(vector<int> &path) {
    int size = (int)path.size();
    vector<int> midPath;
    // ��λ������
    int mid = (size - 1) / 2;
    if (size % 2 == 0) {
        // ����Ԫ�ظ���Ϊż��ʱ����λ�������������ڼ�¼mid+1������
        int midPlus = mid + 1;
        midPath.push_back(path[midPlus]);
    }
    // ����Ԫ�ظ���Ϊ����ʱ����λ��ֻ��һ��
    midPath.push_back(path[mid]);
    return midPath;
}

int main() {
    TreeNode *root = new TreeNode(5);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(4);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(1);
    TreeNode *node5 = new TreeNode(6);
    root->left = node1;
    root->right = node2;
    node1->right = node3;
    node2->left = node4;
    node2->left = node5;

    dfs(root);

    cout << "���·����" << endl;
    for (int i = 0; i < maxPath.size(); ++i) {
        cout << maxPath[i] << endl;
    }

    cout << "��λ��·����" << endl;
    vector<int> path = midPath(maxPath);
    for (const auto &item: path) {
        cout << item << endl;
    }
}