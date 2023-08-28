#include "common.h"

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (auto& task : tasks) {
            ++freq[task];
        }
        int maxExec = max_element(freq.begin(), freq.end(), [](const auto& u, const auto& v) {
            return u.second < v.second;
            })->second;
        int taskCount = accumulate(freq.begin(), freq.end(),0, [=](int acc, const auto& u) {
            return acc +(maxExec == u.second);
            });
        return max((maxExec - 1) * (n + 1) + taskCount, static_cast<int>(tasks.size()));

    }
};