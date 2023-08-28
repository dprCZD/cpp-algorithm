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
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);//i-1����й�Ʊ���ߵ�������
            dp[i][1] = dp[i - 1][0] + prices[i];//i-1��һ�����й�Ʊ��������
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);//������֮ǰ��������ǰһ�����䶳��
        }
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);

    }
};