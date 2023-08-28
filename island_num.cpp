#include"common.h"

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++num;
                    find(grid, i, j);
                }
            }
        }
        return num;
    }

    void find(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }
        grid[i][j] = '2';
        find(grid, i + 1, j);
        find(grid, i - 1, j);
        find(grid, i, j + 1);
        find(grid, i, j - 1);
    }
};