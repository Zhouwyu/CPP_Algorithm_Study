//
// Created by zhou on 2023/11/5.
//

/**
* 给定一个正整数数组 nums 和一个目标正整数 target ，请找出所有可能的组合，使得组合中的元素和等于 target 。
 * 给定数组无重复元素，每个元素可以被选取多次。请以列表形式返回这些组合，列表中不应包含重复组合。
*/

#include "../utils/common.h"
/**
 * 参考全排列的解法
 */
void backtrack(vector<int> &state, int target, int total, vector<int> &choices, vector<vector<int>> &res){
    // 结束条件
    if(target == total) {
        res.push_back(state);
        return;
    }
    // 遍历所有选择
    for(int i = 0; i < choices.size(); i++) {
        // 每次选择求和
        int choice = choices[i];
        total += choice;
        // 超出目标值跳过当前的选择（剪枝）
        if (total > target) continue;
        // 符合要求，做出选择
        state.push_back(total);
        // 进行下一轮的选择
        backtrack(state, target, total, choices, res);
        // 撤销选择，回到最初
        state.pop_back();
    }
}

vector<vector<int>> subSetSum(vector<int> &nums, int target) {
    vector<int> state;
    vector<vector<int>> res;
    int total = 0;
    backtrack(state, target, total, nums, res);
    return res;
}

int main() {
    vector<int> nums = {3, 4, 5};
    vector<vector<int>> res = subSetSum(nums, 9);
    for (const auto &items: res) {
        for (const auto &item: items){
            cout << item << endl;
        }
    }

}