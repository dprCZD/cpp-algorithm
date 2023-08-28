
#include "common.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        while (true) {
            int sum = digits[i] + 1;
            if (sum == 10) {
                digits[i] = 0;
                if (i == 0) {
                    digits.insert(digits.begin(), 1);
                    break;
                }
            }
            else {
                digits[i] = sum;
                break;
            }
            --i;
        }
        return digits;
    }
};