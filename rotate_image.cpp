#include "common.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 斜对角反转
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 左右翻转
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size() / 2; ++j) {
                swap(matrix[i][j], matrix[i][matrix[0].size() - j - 1]);
            }
        }
    }
};