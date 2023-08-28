#include "common.h"


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(1,{ 1 });
        for (int i = 1; i < numRows; ++i) {
            vector<int> cur;
            cur.push_back(1);
            for (int j = 0; j < i - 1; ++j) {
                cur.push_back(res[i - 1][j] + res[i - 1][j + 1]);
            }
            cur.push_back(1);
            res.push_back(cur);
        }
        return res;

    }
};