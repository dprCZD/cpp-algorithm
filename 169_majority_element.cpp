#include "common.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int data : nums) {
            if (count == 0) {
                candidate = data;
            }
            if (candidate == data) {
                ++count;
            }
            else {
                --count;
            }
        }
        return candidate;
    }
};