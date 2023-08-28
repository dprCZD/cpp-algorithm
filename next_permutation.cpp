#include "common.h"
/**
* A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
* The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
* More formally, if all the permutations of the array are sorted in one container according to their lexicographical order,
* then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible,
* the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }
        // find i when nums[i]<nums[i+1]
        int i = nums.size() - 2;
        while (i>=0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        //find j when nums[i]<nums[j]
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j > i && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};