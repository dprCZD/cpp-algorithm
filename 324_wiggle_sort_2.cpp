#include"common.h"


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto arr = nums;
        std::sort(arr.begin(), arr.end());
        int x = (n + 1) / 2;
        for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, --j, --k) {
            nums[i] = arr[j];
            if (i + 1 < n) {
                nums[i + 1] = arr[k];
            }
        }
    }
    /**
    * 算法与快速排序算法类似，在一次递归调用中，首先进行partition过程，即利用一个元素将原数组划分为两个子数组，然后将这一元素放在两个数组之间。两者区别在于快速排序接下来需要对左右两个子数组进行递归，而快速选择只需要对一侧子数组进行递归，所以快速选择的时间复杂度为O(n)。详细原理可以参考有关资料，此处不做赘述。
    * 在C++中，可以用STL的nth_element()函数进行快速选择，这一函数的效果是将数组中第n小的元素放在数组的第n个位置，同时保证其左侧元素不大于自身，右侧元素不小于自身。
    * 找到中位数后，我们需要利用3-way-partition算法将中位数放在数组中部，同时将小于中位数的数放在左侧，大于中位数的数放在右侧。该算法与快速排序的partition过程也很类似，只需要在快速排序的partition过程的基础上，添加一个指针k用于定位大数
    */
    void wiggleSort2(vector<int>& nums) {
        auto miditer = nums.begin() + nums.size() / 2;
        std::nth_element(nums.begin(), miditer, nums.end());
        int mid = *miditer;

        //3-way-partition
        int i = 0; int j = 0; int k = nums.size() - 1;
        while (j < k) {
            if (nums[j] > mid) {
                std::swap(nums[j], nums[k]);
                --k;
            }
            else if (nums[j] < mid) {
                std::swap(nums[j], nums[i]);
                ++i;
                ++j;
            }
            else {
                ++j;
            }
        }
        if (nums.size() % 2) {
            ++miditer;
        }
        vector<int>temp1(nums.begin(), miditer);
        vector<int>temp2(miditer, nums.end());
        for (int i = 0; i < temp1.size(); ++i) {
            nums[2 * i] = temp1[temp1.size()-1-i];
        }
        for (int i = 0; i < temp2.size(); ++i) {
            nums[2 * i+1] = temp2[temp2.size() - 1 - i];
        }
    }
};