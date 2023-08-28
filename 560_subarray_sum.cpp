#include "common.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j >= 0; --j) {
                sum += nums[j];
                if (sum == k) {
                    ++res;
                }
            }
        }
        return res;
    }
    int subarraySum2(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int res = 0; int pre = 0;
        // pre[i]= sum(nums[0]:nums[i]); pre[i] - pre[j-1] ==k
        for (int& num : nums) {
            pre += num;
            if (map.count(pre - k) != 0) {
                res += map[pre - k];
            }
            map[pre]++;
        }
        return res;
    }
};