#include "common.h"

class Solution {
public:

    /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 mid1 = nums1[k/2-1] 和 mid2 = nums2[k/2-1] 进行比较
     * 这里的 "/" 表示整除
     * nums1 中小于等于 mid1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
     * nums2 中小于等于 mid2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
     * 取 mid = min(mid1, mid2)，两个数组中小于等于 mid 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
     * 这样 mid 本身最大也只能是第 k-1 小的元素
     * 如果 mid = mid1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
     * 如果 mid = mid2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
     * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
     */
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {

        int len1 = nums1.size();
        int len2 = nums2.size();
        int left1 = 0;
        int left2 = 0;
        while (true) {
            // 边界条件
            //如果nums1都找完了，说明在nums2中，并且为第left2+k个元素。
            if (left1 == len1) {
                return nums2[left2 + k - 1];
            }
            if (left2 == len2) {
                return nums1[left1 + k - 1];
            }
            //如果k=1说明更小的那个是目标中位数。这里的下标也应该为left1+k-1.
            if (k == 1) {
                return min(nums1[left1], nums2[left2]);
            }

            //>二分算法
            int mid1 = min(left1 + k / 2 - 1, len1 - 1);
            int mid2 = min(left2 + k / 2 - 1, len2 - 1);
            int num1 = nums1[mid1];
            int num2 = nums2[mid2];
            if (num1 <= num2) {
                //缩减k的数量
                k -= mid1 - left1 + 1;
                left1 = mid1 + 1;
            }
            else {
                k -= mid2 - left2 + 1;
                left2 = mid2 + 1;
            }

        }

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        if (len % 2 == 1) {
            return getKthElement(nums1, nums2, (len + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, len  / 2)+ getKthElement(nums1, nums2, len / 2+1))/2.0;
        }
    }
};