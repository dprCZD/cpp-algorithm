#include"common.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums, k, 0, nums.size() - 1);
    }

    int find(vector<int>& nums, int k, int start, int end) {
        if (start > end) {
            return -1;
        }
        int j = partition(nums, start, end);
        if (j < nums.size() - k) {
            return find(nums, k, j + 1, end);
        }
        else if (j > nums.size() - k) {
            return find(nums, k, start, j - 1);
        }
        else {
            return nums[j];
        }
    }

    int partition(vector<int>& nums, int start, int end) {
        int i = start;
        int j = end;
        while (i < j) {
            ++i;
            while (i < end && nums[i] <= nums[start]) {
                ++i;
            }
            while (j >= start && nums[j] > nums[start]) {
                --j;
            }
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[start], nums[j]);
        return j;
    }
};

//int main() {
//    Solution su;
//    vector<int> data{ 7,6,5,4,3,2,1 };
//    su.findKthLargest(data, 5);
//}