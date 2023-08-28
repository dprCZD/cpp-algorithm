#include "common.h"

class Solution {
public:

    /* ��Ҫ˼·��Ҫ�ҵ��� k (k>1) С��Ԫ�أ���ô��ȡ mid1 = nums1[k/2-1] �� mid2 = nums2[k/2-1] ���бȽ�
     * ����� "/" ��ʾ����
     * nums1 ��С�ڵ��� mid1 ��Ԫ���� nums1[0 .. k/2-2] ���� k/2-1 ��
     * nums2 ��С�ڵ��� mid2 ��Ԫ���� nums2[0 .. k/2-2] ���� k/2-1 ��
     * ȡ mid = min(mid1, mid2)������������С�ڵ��� mid ��Ԫ�ع��Ʋ��ᳬ�� (k/2-1) + (k/2-1) <= k-2 ��
     * ���� mid �������Ҳֻ���ǵ� k-1 С��Ԫ��
     * ��� mid = mid1����ô nums1[0 .. k/2-1] ���������ǵ� k С��Ԫ�ء�����ЩԪ��ȫ�� "ɾ��"��ʣ�µ���Ϊ�µ� nums1 ����
     * ��� mid = mid2����ô nums2[0 .. k/2-1] ���������ǵ� k С��Ԫ�ء�����ЩԪ��ȫ�� "ɾ��"��ʣ�µ���Ϊ�µ� nums2 ����
     * �������� "ɾ��" ��һЩԪ�أ���ЩԪ�ض��ȵ� k С��Ԫ��ҪС���������Ҫ�޸� k ��ֵ����ȥɾ�������ĸ���
     */
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {

        int len1 = nums1.size();
        int len2 = nums2.size();
        int left1 = 0;
        int left2 = 0;
        while (true) {
            // �߽�����
            //���nums1�������ˣ�˵����nums2�У�����Ϊ��left2+k��Ԫ�ء�
            if (left1 == len1) {
                return nums2[left2 + k - 1];
            }
            if (left2 == len2) {
                return nums1[left1 + k - 1];
            }
            //���k=1˵����С���Ǹ���Ŀ����λ����������±�ҲӦ��Ϊleft1+k-1.
            if (k == 1) {
                return min(nums1[left1], nums2[left2]);
            }

            //>�����㷨
            int mid1 = min(left1 + k / 2 - 1, len1 - 1);
            int mid2 = min(left2 + k / 2 - 1, len2 - 1);
            int num1 = nums1[mid1];
            int num2 = nums2[mid2];
            if (num1 <= num2) {
                //����k������
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