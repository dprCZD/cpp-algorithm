#include"common.h"

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O' ) {
                mark(board,  i, 0);
            }
            if (board[i][m - 1] == 'O') {
                mark(board,  i, m - 1);
            }
        }
        for (int j = 0; j < m; ++j) {
            if (board[0][j] == 'O') {
                mark(board, 0, j);
            }
            if (board[n - 1][j] == 'O' ) {
                mark(board, n - 1, j);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j =0; j < m; ++j) {
                if (board[i][j] == 'O' ) {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
            }
        }

    }
    void mark(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != 'O') {
            return;
        }
        int n = board.size();
        int m = board[0].size();
        board[i][j] = 'A';
        if (i + 1 < n) {
            mark(board,  i + 1, j);
        }
        if (i -1 >=0) {
            mark(board,  i - 1, j);
        }
        if (j + 1 < m) {
            mark(board,  i, j+1);
        }
        if (j-1 >=0) {
            mark(board,  i, j-1);
        }
    }
};

//int main() {
//    Solution su;
//    vector<vector<char>> data = { {'X','X','X','X'},{'X','O','O','X'} ,{'X','X','O','X'} ,{'X','O','X','X'} };
//    su.solve(data);
//}