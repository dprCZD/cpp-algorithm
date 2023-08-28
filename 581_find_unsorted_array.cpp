#include "common.h"

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        //属于ArrayC的的元素nums[i]应该大于左侧的最大元素。
        int leftMax = INT_MIN;
        //属于ArrayA的的元素nums[i]应该小于右侧的最大元素。
        int rightMin = INT_MAX;
        int left = -1;
        int right = -1;
        for (int i = 0; i <nums.size(); ++i) {
            if (leftMax > nums[i]) {
                right = i;
            }
            else {
                leftMax = nums[i];
            }
            if (rightMin < nums[n - i - 1]) {
                left = n - i - 1;
            }
            else {
                rightMin = nums[n - i - 1];
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
};