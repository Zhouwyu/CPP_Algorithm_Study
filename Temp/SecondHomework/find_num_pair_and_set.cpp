//
// Created by zhou on 2023/12/7.
//
/**
* 直接利用pair对和set去重方法
*/
#include <set>
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

typedef pair<int, int> Pair;

/**
 * 重写比较器，自定义比较规则
 */
int compare(const Pair &x, const Pair &y) {
    // map中value由小到大排列
    return x.second <= y.second;
}

int findNumByArrCount(vector<int> &nums) {
    // 结果集合
    vector<Pair> result;
    // 分配内存
    result.reserve(nums.size());
    // 遍历原始元素序列，构建pair对，first为元素num,second为该元素在序列中出现次数
    for (int &num: nums) {
        int count = 0;
        for (int i : nums) {
            if (num == i) {
                count++;
            }
        }
        result.emplace_back(num, count);
    }
    // 根据元素出现次数由小到大排序
    sort(result.begin(), result.end(), compare);
    // 定义set实行去重操作
    set<int> noRepeatRes;
    // 输出,去重
    for(Pair p: result) {
        // 若set出无此元素，则插入并输出
        if(noRepeatRes.count(p.first) == 0) {
            noRepeatRes.insert(p.first);
            cout << p.first << " ";
        }
    }
    // 获取出现次数最多的元素
    return result[result.size() - 1].first;
}

int main() {
    vector<int> nums{2, 3, 1, 2, 4, 3, 3};
    cout<< "The order of elements from least to most is:" << endl;
    int num = findNumByArrCount(nums);
    cout << "\nThe most frequently occurring element is:" << endl;
    cout << num << endl;
}