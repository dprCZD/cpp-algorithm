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
    * �㷨����������㷨���ƣ���һ�εݹ�����У����Ƚ���partition���̣�������һ��Ԫ�ؽ�ԭ���黮��Ϊ���������飬Ȼ����һԪ�ط�����������֮�䡣�����������ڿ��������������Ҫ������������������еݹ飬������ѡ��ֻ��Ҫ��һ����������еݹ飬���Կ���ѡ���ʱ�临�Ӷ�ΪO(n)����ϸԭ����Բο��й����ϣ��˴�����׸����
    * ��C++�У�������STL��nth_element()�������п���ѡ����һ������Ч���ǽ������е�nС��Ԫ�ط�������ĵ�n��λ�ã�ͬʱ��֤�����Ԫ�ز����������Ҳ�Ԫ�ز�С������
    * �ҵ���λ����������Ҫ����3-way-partition�㷨����λ�����������в���ͬʱ��С����λ������������࣬������λ�����������Ҳࡣ���㷨����������partition����Ҳ�����ƣ�ֻ��Ҫ�ڿ��������partition���̵Ļ����ϣ����һ��ָ��k���ڶ�λ����
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