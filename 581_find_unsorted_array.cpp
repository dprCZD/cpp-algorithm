#include "common.h"

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        //����ArrayC�ĵ�Ԫ��nums[i]Ӧ�ô����������Ԫ�ء�
        int leftMax = INT_MIN;
        //����ArrayA�ĵ�Ԫ��nums[i]Ӧ��С���Ҳ�����Ԫ�ء�
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