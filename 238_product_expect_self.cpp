#include "common.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        int product = 1;
        for (int i = 0; i < nums.size(); ++i) {
            product *= nums[i];
            left[i] = product;
        }
        product = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            product *= nums[i];
            right[i] = product;
        }

        vector<int> res(nums.size());
        res[0] = right[1];
        res[nums.size() - 1] = left[nums.size() - 2];
        for (int i = 1; i < nums.size() - 1; ++i) {
            res[i] = left[i - 1] * right[i + 1];
        }
        return res;

    }
};