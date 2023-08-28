#include "common.h"
class Solution {
public:
    bool isValid(string s) {
        stack<char> cstk;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                cstk.push(c);
            }
            else {
                if (cstk.empty()) {
                    return false;
                }
                char l = cstk.top();
                if (c == ')' &&  l != '(') {
                    return false;
                }
                if (c == ']' && l != '[') {
                    return false;
                }
                if (c == '}' && l != '{') {
                    return false;
                }
                cstk.pop();
            }
        }
        return cstk.empty();

    }
};