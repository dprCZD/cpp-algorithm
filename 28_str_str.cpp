#include "common.h"

class Solution {
public:
    //�����ⷨ
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


    //KMP�ⷨ
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
            //�����������ǰ�����������ȣ����ҵ����ƥ��ģʽ�ĵ㹹��next����
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