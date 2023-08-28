#include "common.h"

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            int minSquare = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                minSquare = min(minSquare, dp[i - j * j] + 1);
            }
            dp[i] = minSquare;
        }
        return dp[n];

    }
};