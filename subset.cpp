#include"common.h"
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, res, cur, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, int idx) {
        if (idx == nums.size()) {
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[idx]);
        dfs(nums, res, cur, idx + 1);
        cur.pop_back();
        dfs(nums, res, cur, idx + 1);
    }
};