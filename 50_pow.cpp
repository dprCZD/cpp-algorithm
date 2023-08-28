#include "common.h"
class Solution {
public:

    double quickMul(double x, int64_t N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(y, N / 2);
        return N % 2 == 1 ? y * y * x : y * y;
    }
    double myPow(double x, int n) {
        int64_t N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }

    double pow(double x, int64_t N) {
        double ans = 1.0;
        // 贡献的初始值为 x
        double x_con = x;
        // 在对 N 进行二进制拆分的同时计算答案
        while (N > 0) {
            if (N % 2 == 1) {
                // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
                ans *= x_con;
            }
            // 将贡献不断地平方
            x_con *= x_con;
            // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
            N /= 2;
        }
        return ans;
    }
};