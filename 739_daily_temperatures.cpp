#include "common.h"

class Solution {
public:
    
    static vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> next(101,-1);
        vector<int> res(temperatures.size());
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            int nextIdx = INT32_MAX;
            for (int j = temperatures[i] + 1; j <= 100; ++j) {
                if (next[j] != -1) {
                    nextIdx = min(nextIdx, next[j]);
                }
            }
            res[i] = nextIdx == INT32_MAX ? 0 : nextIdx - i;
            next[temperatures[i]] = i;
        }
        return res;
    }
    //
    static vector<int> dailyTemperatures2(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size(),0);
        for (int i = 0; i < temperatures.size(); ++i) {
            if (stk.empty()) {
                stk.push(i);
            }
            else {
                while (!stk.empty()&&temperatures[stk.top()] < temperatures[i]) {
                    int prevIdx = stk.top();
                    res[prevIdx] = i - prevIdx;
                    stk.pop();
                }
                stk.push(i);
            }
        }
        return res;
    }
};

//int main() {
//    vector<int> temperatures{ 73,74,75,71,69,72,76,73 };
//    Solution::dailyTemperatures2(temperatures);
//}