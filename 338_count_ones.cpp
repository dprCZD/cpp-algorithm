#include "common.h"

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) {
            res[i] = countOnes(i);
        }
        return res;
    }
    int countOnes(int x) {
        int ones = 0;
        while (x > 0) {
            x &= (x - 1);
            ones++;
        }
        return ones;
    }

    vector<int> countBits2(int n) {
        vector<int> res(n + 1, 0);
        int highBit = 0;
        for (int i = 1; i < n + 1; ++i) {
            //find the nearest multiple of 2
            if ((i & (i - 1)) == 0) {
                highBit = i;
            }
            res[i] = res[i - highBit] + 1;
        }
        return res;
    }
};