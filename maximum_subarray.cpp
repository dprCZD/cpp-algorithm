#include "common.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int sum;
        int cur;
        for (int num : nums) {
            cur += num;
            sum = max(cur, sum);
            if (cur < 0) {
                cur = 0;
            }
        }
        return sum;
    }
};