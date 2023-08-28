#include "common.h"
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& p1, vector<int>& p2) {
            return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] > p2[1]);
            });
        int n = people.size();
        vector<vector<int>> ans(n);
        for (auto& person : people) {
            int space = person[1] + 1;
            for (int i = 0; i < n; ++i) {
                if (ans[i].empty()) {
                    space--;
                    if (!space) {
                        ans[i] = person;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};