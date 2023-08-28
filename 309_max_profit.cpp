#include "common.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);//i-1天持有股票或者当天买入
            dp[i][1] = dp[i - 1][0] + prices[i];//i-1天一定持有股票并且卖出
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);//可能是之前卖出或者前一天是冷冻期
        }
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);

    }
};