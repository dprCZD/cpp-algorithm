#include "common.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i <= nums.size(); ++i) {
            if (nums[i] == 0) {
                swap(nums[idx], nums[i]);
                ++idx;
            }
        }
        for (int i = idx; i <= nums.size(); ++i) {
            if (nums[i] == 1) {
                swap(nums[idx], nums[i]);
                ++idx;
            }
        }

    }
    void sortColors2(vector<int>& nums) {
        int zero = 0;
        int two = nums.size() - 1;
        int idx = 0;
        while (idx <= two) {
            if (nums[idx] == 0) {
                swap(nums[zero], nums[idx]);
                ++zero;
                ++idx;
            }
            else if (nums[idx] == 1) {
                ++idx;
            }
            else {
                swap(nums[two], nums[idx]);
                --two;
            }
        }

    }
};