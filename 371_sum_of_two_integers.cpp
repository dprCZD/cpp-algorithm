class Solution {
public:
    static int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }


};
int main() {
    Solution::getSum(5, 5);
}