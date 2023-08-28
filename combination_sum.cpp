#include "common.h"

class Solution {
public:

    /**
    * Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. 
    * You may return the combinations in any order.
    * The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
    * It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
    */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(candidates, ans, cur, 0, target);
        return ans;
    }

    void dfs(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& cur, int i, int target) {
        if (i >= candidates.size() || target < 0) {
            return;
        }
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        //not select cur
        dfs(candidates, ans, cur, i+1, target);
        //select cur
        cur.push_back(candidates[i]);
        dfs(candidates, ans, cur, i, target - candidates[i]);
        cur.pop_back();
    }
};