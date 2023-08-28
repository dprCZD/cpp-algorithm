#pragma once
#include "common.h"


class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int result = 0;
        int64_t multiple = 1;
        for (int i = n - 1; i >= 0;--i) {
            result += (columnTitle[i] - 'A' + 1) * multiple;
            multiple *= 26;
        }
        return result;

    }
};

int main() {
    Solution su;
    su.titleToNumber("ABC");
}