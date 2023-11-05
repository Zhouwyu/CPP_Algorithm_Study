//
// Created by zhou on 2023/11/5.
//
#include "../utils/common.h"

void backtrack(vector<int> &state, int start, int target, vector<int> &choices, vector<vector<int>> &res) {
    if(target == 0) {
        res.push_back(state);
        return;
    }
    // 用start变量表示初始的遍历起点，实现重复子集的剪枝操作。因为当你选择了xi后，下一轮就应该从索引i处开始遍历
    for(int i = start; i < choices.size(); i++) {
        int choice = choices[i];
        // 因为元素已有序，故choice大于target时，证明此次循环可以结束了，因为之后的都会比他大
        if(target - choice < 0) break;
        state.push_back(choice);
        backtrack(state, i, target - choice, choices, res);
        state.pop_back();
    }
}

vector<vector<int>> subSetSum(vector<int> &nums, int target) {
    vector<int> state;
    vector<vector<int>> res;
    // 提前排序，其中的一个优化步骤
    sort(nums.begin(), nums.end());
    backtrack(state, 0, target, nums, res);
    return res;
}