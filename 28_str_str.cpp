#include "common.h"

class Solution {
public:
    //暴力解法
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for (int i = 0; i <= n - m; ++i) {
            int j = i; int k = 0;
            while (k < m && haystack[j] == needle[k]) {
                j++;
                k++;
            }
            if (k == m) {
                return i;
            }
        }
        return -1;
    }


    //KMP解法
    int kmpr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> next = getNext(needle);
        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++i;
                ++j;
            }
            else {
                j = next[j];
            }
        }
        return j == m ? i - j : -1;

    
    }
    vector<int> getNext(string& p) {
        int m = p.size();
        vector<int>next(m);
        next[0] = -1;
        int i = 0; int j = -1;
        while (i < m - 1) {
            //如果相等则继续前进；如果不相等，则找到最近匹配模式的点构造next数据
            if (j == -1 || p[i] == p[j]) {
                ++i;
                ++j;
                next[i] = j;
            }
            else {
                j = next[j];
            }
        }
        return next;
    }
};