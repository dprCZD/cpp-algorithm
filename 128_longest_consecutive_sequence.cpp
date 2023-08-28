#include "common.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (int num : nums) {
            set.insert(num);
        }
        int maxSeq = 0;
        for (int num : nums) {
            //> 如果num-1存在在set中，说明当前计算的不是最长连续，跳过。
            if (set.count(num - 1) == 0) {
                int curSeq = 1;
                while (set.count(num + 1) != 0) {
                    ++curSeq;
                    ++num;
                }
                maxSeq = max(maxSeq, curSeq);
            }
        }
        return maxSeq;
    }
};