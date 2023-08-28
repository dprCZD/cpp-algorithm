#include "common.h"
class Solution {
public:
    //»¬¶¯´°¿Ú
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();
        if (sLen < pLen) {
            return {};
        }
        vector<int> res;
        vector<int>sArray(26);
        vector<int>pArray(26);
        for (int i = 0; i < pLen; ++i) {
            ++sArray[s[i] - 'a'];
            ++pArray[p[i] - 'a'];
        }
        if (sArray == pArray) {
            res.emplace_back(0);
        }
        for (int i = 0; i <sLen - pLen; ++i) {
            --sArray[s[i] - 'a'];
            ++sArray[s[i + pLen] - 'a'];
            if (sArray == pArray) {
                res.emplace_back(i + 1);
            }
        }
        return res;

    }
};