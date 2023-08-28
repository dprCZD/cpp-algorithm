#include "common.h"

class Solution {
public:
    //ͨ����򣬰�������������һ�飻�ڰ�0-n���һ�飬�������Ŀ�������
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