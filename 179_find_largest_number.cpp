#include "common.h"

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](const int& a, const int& b) {
            int64_t sa = 10;
            int64_t sb = 10;
            while (sa <= a) {
                sa *= 10;
            }
            while (sb <= b) {
                sb *= 10;
            }
            return sb * a + b > sa * b + a;
            });
        if (nums[0] == 0) {
            return "0";
        }
        string res;
        for (int& num : nums) {
            res += to_string(num);
        }
        return res;
    }
};