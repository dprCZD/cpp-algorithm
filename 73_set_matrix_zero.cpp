#include "common.h"
class Solution {
public:
    /*
    * 我们可以用矩阵的第一行和第一列代替方法一中的两个标记数组，以达到 O(1) 的额外空间。
    * 但这样会导致原数组的第一行和第一列被修改，无法记录它们是否原本包含 0。因此我们需要额外使用两个标记变量分别记录第一行和第一列是否原本包含0。
    */
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool isColumnZero = false;
        bool isRowZero = false;

        for (int i = 0; i < n; ++i) {
            if (!matrix[i][0]) {
                isColumnZero = true;
                break;
            }
        }
        for (int j = 0; j < m; ++j) {
            if (!matrix[0][j]) {
                isRowZero = true;
                break;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (!matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (isColumnZero) {
            for (int i = 0; i < n; ++i) {
                matrix[i][0] = 0;
            }
        }
        if (isRowZero) {
            for (int j = 0; j < m; ++j) {
                matrix[0][j] = 0;

            }
        }
    }
};