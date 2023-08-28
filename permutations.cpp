#include "common.h"

/**
* Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, res, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, int first) {
        if (first == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = first; i < nums.size(); ++i) {
            swap(nums[first], nums[i]);
            dfs(nums, res, first + 1);
            swap(nums[first], nums[i]);
        }
    }
};