#include "common.h"
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(),0));
        int maxSide = 0;

        for (int i = 0; i < matrix.size(); ++i) {
            dp[i][0] = matrix[i][0] == '1'?1:0;
            maxSide = max(maxSide, dp[i][0]);
        }

        for (int i = 0; i < matrix[0].size(); ++i) {
            dp[0][i] = matrix[0][i] == '1' ? 1 : 0;
            maxSide = max(maxSide, dp[0][i]);
        }

        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '0') {
                    continue;
                }
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                maxSide = max(maxSide, dp[i][j]);

            }
        }

        return maxSide * maxSide;

    }

    int min(int a, int b, int c) {
        if (a <= b) {
            if (a <= c) {
                return a;
            }
            else {
                return c;
            }
        }
        else {
            if (c <= b) {
                return c;
            }
            else {
                return b;
            }
        }
    }
};