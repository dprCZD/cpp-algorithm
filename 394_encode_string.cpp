#include "common.h"

class Solution {
public:

    string getDigit(string& s, int& ptr) {
        string res;
        while (isdigit(s[ptr])) {
            res.push_back(s[ptr++]);
        }
        return res;
    }
    string getString(vector<string> &v) {
        string res;
        for (const auto& s : v) {
            res += s;
        }
        return res;
    }
    string decodeString(string s) {
        vector<string> stk;
        int ptr = 0;
        while (ptr < s.size()) {
            char cur = s[ptr];
            if (isdigit(cur)) {
                stk.push_back(getDigit(s, ptr));
            }
            else if (isalpha(cur)|| cur =='[') {
                stk.push_back(string(1, s[ptr++]));
            }
            else {
                ++ptr;
                vector<string> sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                //×óÀ¨ºÅ³öÕ»
                stk.pop_back();
                int repeat = stoi(stk.back());
                stk.pop_back();
                string t;
                string o = getString(sub);
                while (repeat--) {
                    t += o;
                }
                stk.push_back(t);
            }
        }
        return getString(stk);
    }
};