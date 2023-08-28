#include "common.h"
class Solution {
public:
    /*
    * ���ǿ����þ���ĵ�һ�к͵�һ�д��淽��һ�е�����������飬�Դﵽ O(1) �Ķ���ռ䡣
    * �������ᵼ��ԭ����ĵ�һ�к͵�һ�б��޸ģ��޷���¼�����Ƿ�ԭ������ 0�����������Ҫ����ʹ��������Ǳ����ֱ��¼��һ�к͵�һ���Ƿ�ԭ������0��
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