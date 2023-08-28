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
        // ���׵ĳ�ʼֵΪ x
        double x_con = x;
        // �ڶ� N ���ж����Ʋ�ֵ�ͬʱ�����
        while (N > 0) {
            if (N % 2 == 1) {
                // ��� N �����Ʊ�ʾ�����λΪ 1����ô��Ҫ���빱��
                ans *= x_con;
            }
            // �����ײ��ϵ�ƽ��
            x_con *= x_con;
            // ���� N �����Ʊ�ʾ�����λ����������ÿ��ֻҪ�ж����λ����
            N /= 2;
        }
        return ans;
    }
};