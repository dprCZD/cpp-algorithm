#include "common.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (int num : nums) {
            set.insert(num);
        }
        int maxSeq = 0;
        for (int num : nums) {
            //> ���num-1������set�У�˵����ǰ����Ĳ����������������
            if (set.count(num - 1) == 0) {
                int curSeq = 1;
                while (set.count(num + 1) != 0) {
                    ++curSeq;
                    ++num;
                }
                maxSeq = max(maxSeq, curSeq);
            }
        }
        return maxSeq;
    }
};