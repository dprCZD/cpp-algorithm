#include "common.h"

class Solution {
public:
    //通过异或，把数组里的数异或一遍；在把0-n异或一遍，结果就是目标的数。
    int missingNumber(vector<int>& nums) {
        int XOR = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            XOR ^= nums[i];
        }
        for (int i = 0; i <= n; ++i) {
            XOR ^= i;
        }
        return XOR;

    }
};