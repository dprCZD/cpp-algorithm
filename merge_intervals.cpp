#include "common.h"


/**
* Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto isShorter = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), isShorter);
        vector<vector<int>> res;
        vector<int> cur = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            // 有重合，进行合并
            if (cur[1] >= intervals[i][0]) {
                cur[1] = max(cur[1], intervals[i][1]);
            }
            //无重合则将当前interval加入结果集。
            else {
                res.push_back(cur);
                cur = intervals[i];
            }
        }
        res.push_back(cur);
        return res;
    }
};