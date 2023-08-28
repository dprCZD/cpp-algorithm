#include "common.h"
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int s = x ^ y;
        while (s) {
            res += s & 1;
            s >>= 1;
        }
        return res;

    }
};