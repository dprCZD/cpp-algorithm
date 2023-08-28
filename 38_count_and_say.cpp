#include "common.h"

class Solution {
public:
    string countAndSay(int n) {
        string pre = "1";
        for (int i = 2; i <= n; ++i) {
            int len = pre.size();
            string cur = "";
            int count = 0;
            for (int j = 0; j < len; ++j) {
                ++count;
                if (j == len - 1 || pre[j] != pre[j + 1]) {
                    cur.append(to_string(count)).push_back(pre[j]);
                    count = 0;
                }
            }
            pre = std::move(cur);
        }
        return pre;
    }
};