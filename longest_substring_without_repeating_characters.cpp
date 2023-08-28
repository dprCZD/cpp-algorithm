#include"common.h"

/**
* Given a string s, find the length of the longest substring without repeating characters.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int right = 0;
        int res = 0;
        unordered_set<char> occured;
        for (int i = 0; i < len; ++i) {
            if (i != 0) {
                occured.erase(s[i-1]);
            }
            while (right < len && occured.count(s[right]) == 0) {
                occured.insert(s[right]);
                ++right;
            }
            res = max(res, right - i);
        }
        return res;
    }
};