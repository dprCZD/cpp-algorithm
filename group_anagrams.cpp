#include "common.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() < 2) {
            return { strs };
        }
        map<string, vector<string>> map;
        for (string str : strs) {
            vector<int> count(26, 0);
            for (char c : str) {
                ++count[c - 'a'];
            }
            string key;
            for (int i = 0; i < 26; ++i) {
                if (count[i] != 0) {
                    key += 'a' + i;
                    key += '0' + count[i];
                }
            }
            map[key].push_back(str);
        }
        vector<vector<string>> res;
        for (auto it = map.cbegin(); it != map.cend(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};