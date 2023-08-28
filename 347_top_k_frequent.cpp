#include "common.h"

class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurs;
        for (int num : nums) {
            occurs[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> queue(cmp);
        for (auto& data : occurs) {
            if (queue.size() == k) {
                if (queue.top().second < data.second) {
                    queue.pop();
                    queue.push(data);
                }
            }
            else {
                queue.push(data);
            }
        }
        vector<int> res;
        while (!queue.empty()) {
            res.push_back(queue.top().first);
            queue.pop();
        }
        return res;
    }
};