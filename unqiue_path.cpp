#include "common.h"
/**
* There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
* The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
        for (int i = 0; i < m; ++i) {
            dp.emplace_back(n, 1);
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];

    }
    //can't dfs ,overtime.
    void dfs(int m, int n, int i, int j, int& paths) {
        if (i == m - 1 && j == n - 1) {
            ++paths;
            return;
        }
        if (i < m) {
            dfs(m, n, i + 1, j, paths);
        }
        if (j < n) {
            dfs(m, n, i, j + 1, paths);
        }
    }

    int uniquePaths2(int m, int n) {
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y) {
            ans = ans * x / y;
        }
        return ans;
    }

};

//int main() {
//    Solution so;
//    so.uniquePaths(3, 7);
//}