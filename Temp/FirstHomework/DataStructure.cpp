//
// 编写一个程序，设计一种好的数据结构，尽可能高效地实现以下功能：
// 1.插入若干整数序列
// 2.获得该序列的中位数，并估计时间复杂度
//
#include "vector"
#include "iostream"
using std::vector;
using std::cin;
using std::cout;
using std::endl;

// 定义全局数组，用于存储插入的元素
vector<int> arrs;
/**
 * 插入操作
 */
void insert(int num, int index) {
    arrs.insert(arrs.begin() + index, num);
}

/**
 * 利用二分法查找元素插入位置
 * @param nums 数组，用于存储插入的元素
 * @param num 要插入的元素
 * @return 返回插入位置索引（从0开始）
 */
int findInsertion(vector<int> &nums, int num) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        // 左半区间
        if(nums[mid] > num) right = mid - 1;
        // 右半区间
        else if (nums[mid] < num) left = mid + 1;
        else return mid;
    }
    return left;
}

/**
 * 求中位数
 */
int middle(vector<int> &nums) {
    int mid = (int)(nums.size() - 1) / 2;
    return nums[mid];
}

int main(){
    insert( 2, findInsertion(arrs, 2));
    insert( 6, findInsertion(arrs, 6));
    insert(1, findInsertion(arrs, 1));
    insert(1, findInsertion(arrs, 1));
    insert(1, findInsertion(arrs, 1));
    insert(3, findInsertion(arrs, 3));
    insert(4, findInsertion(arrs, 4));
    for (const auto &item: arrs) {
        cout << item << endl;
    }
    cout << middle(arrs) << endl;
}