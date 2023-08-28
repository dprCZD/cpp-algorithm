#include "common.h"


class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrimes(n,1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrimes[i]) {
                ++ans;
                for (int64_t j = (int64_t)i * i; j < n; j += i) {
                    isPrimes[j] = false;
                }
            }
        }
        return ans;
    }
};