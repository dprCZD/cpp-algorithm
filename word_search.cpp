#include "common.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board,string &word, int i, int j, int charIdx) {
        if (charIdx == word.size()-1) {
            return true;
        }
        char temp = board[i][j];
        board[i][j] = '0';
        bool match = false;
        if (i > 0 &&board[i-1][j]!='0' && word[charIdx + 1] == board[i - 1][j]) {
            match = match||dfs(board, word, i - 1, j, charIdx + 1);
        }
        if (i < board.size()-1 && board[i+1][j] != '0' && word[charIdx+1] == board[i+1][j]) {
            match = match||dfs(board, word, i + 1, j, charIdx + 1);
        }
        if (j > 0 && board[i][j-1] != '0' && word[charIdx+1] == board[i][j-1]) {
            match = match||dfs(board, word, i, j - 1, charIdx + 1);
        }
        if (j < board[0].size()-1 && board[i][j+1] != '0' && word[charIdx+1] == board[i][j+1]) {
            match = match||dfs(board, word, i, j + 1, charIdx + 1);
        }
        board[i][j] = temp;
        return match;
    }


};
//int main() {
//    Solution so;
//    vector<vector<char>> board{ {'A','B','C','E'} ,{'S','F','C','S'},{'A','D','E','E'} };
//    so.exist(board, "ABCCED");
//}