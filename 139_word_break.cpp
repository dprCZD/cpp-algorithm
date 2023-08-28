#include "common.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        size_t maxWordLen = 0;
        for (string& word : wordDict) {
            set.insert(word);
            maxWordLen = max(maxWordLen, word.size());
        }
        
        vector<bool>dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i < s.size()+1; ++i) {
            for (int j = i-1; j >=0 ; --j) {
                if (dp[j] && set.count(s.substr(j, i - j)) != 0) {
                    dp[i] = true;
                    break;
                }
                if (i - j > maxWordLen) {
                    break;
                }
            }
        }
        return dp[s.size()];

    }
};