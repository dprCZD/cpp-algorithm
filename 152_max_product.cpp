#include "common.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int imax = 1;
        int imin = 1;
        for (int i = 0; i < nums.size(); ++i) {
            //>�����ǰ�Ǹ�������������Сֵ��ת����
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