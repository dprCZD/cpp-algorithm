#include "common.h"



/**
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n, n, "", res);
        return res;

    }

    void generate(int left, int right, string cur, vector<string>& res) {
        if (left == 0 && right == 0) {
            res.push_back(cur);
            return;
        }
        if (left > right) {
            return;
        }
        if (left != 0) {
            generate(left - 1, right, cur+'(', res);
        }
        if (right != 0&&left<right) {
            generate(left, right-1, cur + ')', res);
        }
    }
};