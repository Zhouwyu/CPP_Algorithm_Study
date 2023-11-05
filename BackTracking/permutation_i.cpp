//
// Created by zhou on 2023/11/4.
//

#include "../utils/common.h"

void backtrack(vector<int> &state, const vector<int> &choices,
               vector<bool> &selected, vector<vector<int>> &res) {
    // 当最终状态长度和元素数量相等时，说明选择已经完成，记录解
    if(state.size() == choices.size()) {
        res.push_back(state);
        return;
    }
    // 遍历所有选择
    for (int i = 0; i < choices.size(); ++i) {
        // 选其一
        int choice = choices[i];
        // 当未被选过的，剪枝操作
        if (!selected[i]) {
            // 做出尝试，选择当前的更新状态
            selected[i] = true;
            state.push_back(choice);
            // 下一次选择
            backtrack(state, choices, selected, res);
            // 此次选择完成，需要回溯（撤销当前选择），进行另一边的选择（参考树的前序遍历较好理解）
            selected[i] = false;
            state.pop_back();
        }
    }
}

vector<vector<int>> permutationI(vector<int> nums){
    vector<int> state;
    vector<bool> selected(nums.size(), false);
    vector<vector<int>> res;
    backtrack(state, nums, selected, res);
    return res;
}