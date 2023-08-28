#include "common.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int imax = 1;
        int imin = 1;
        for (int i = 0; i < nums.size(); ++i) {
            //>如果当前是负数，则最大和最小值会转换。
            if (nums[i] < 0) {
                swap(imax, imin);
            }
            imax = max(imax * nums[i], nums[i]);
            imin = min(imin * nums[i],nums[i]);
            ans = max(imax, ans);

        }
        return ans;
    }
};