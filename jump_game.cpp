#include "common.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // can't jump
            if (maxJump < i) {
                return false;
            }
            else if (maxJump >= n - 1) {
                return true;
            }
            maxJump = max(maxJump, i + nums[i]);
        }
        return true;
    }
};