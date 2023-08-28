class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for (int i = n / 5; i > 0; i /= 5) {
            res += i;
        }
        return res;
    }
};