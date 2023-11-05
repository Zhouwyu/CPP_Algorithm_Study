//
// Created by zhou on 2023/11/4.
//
#include "../utils/common.h"

void backtrack(vector<int> &state, vector<int> &choices,
               vector<bool> &selected, vector<vector<int>> &res) {
    if(state.size() == choices.size()) {
        res.push_back(state);
        return;
    }
    // set中元素不能重复，每一个都是唯一的
    // 定义在函数体中是确保每一轮选择都不能重复，保证相等元素在每一轮选择时都只是被选择了一次
    unordered_set<int> duplicated;
    for(int i = 0; i < choices.size(); i++) {
        int choice = choices[i];
        // 每次选择完的元素都加入到set中
        duplicated.emplace(choice);
        // 剪枝操作，未被选择的且不是重复元素的，就做出选择
        // find函数，当能够找到时返回对应迭代器，不能找到时，返回最尾元素后一位迭代器
        if(!selected[i] && duplicated.find(choice) == duplicated.end()) {
            selected[i] = true;
            state.push_back(choice);
            backtrack(state, choices, selected, res);
            selected[i] = false;
            state.pop_back();
        }
    }
}