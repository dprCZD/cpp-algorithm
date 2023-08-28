#include "common.h"

class Solution {
public:

    //status:
    // 0: dead->dead
    // 1: live->live
    // 2: dead->live
    // -1: live->dead
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = isLive(board, i, j);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
                if (board[i][j] == -1) {
                    board[i][j] = 0;
                }
            }
        }

    }

    int isLive(vector<vector<int>>& board,int x,int y) {
        int m = board.size();
        int n = board[0].size();
        bool isLive = board[x][y] ==1;
        int liveOthers = 0;

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (x + i < 0 || x + i >= m || y + j<0 || y + j>=n) {
                    continue;
                }
                if (board[x + i][y + j] == 1 || board[x + i][y + j] == -1) {
                    ++liveOthers;
                }
            }
        }
        if (liveOthers == 3) {
            isLive = true;
        }
        else if(liveOthers!=2)
        {
            isLive = false;
        }

        if (isLive) {
            return board[x][y] == 1 ? 1 : 2;
        }
        else {
            return board[x][y] == 0 ? 0 : -1;
        }

    }


};