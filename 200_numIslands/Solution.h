//
// Created by timeC on 2021/4/22.
//

#ifndef INC_200_NUMISLANDS_SOLUTION_H
#define INC_200_NUMISLANDS_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    int ret = 0;
    int items[4][2] = {
            {1,  0},
            {0,  1},
            {-1, 0},
            {0,  -1}
    };
    int m;
    int n;
    vector<vector<char>> nums;

    int numIslands(vector<vector<char>> &grid) {
        nums = grid;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (nums[i][j] == '1') {
                    ret++;
                    nums[i][j] = '0';
                    solve(i, j);
                }
            }
        }
        return ret;
    }

    void solve(int i, int j) {
        for (int x = 0; x < 4; x++) {
            int nextI = i + items[x][0];
            int nextJ = j + items[x][1];
            if (nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n) {
                if (nums[nextI][nextJ] == '1') {
                    nums[nextI][nextJ] = '0';
                    solve(nextI, nextJ);
                }
            }
        }
    }
};


#endif //INC_200_NUMISLANDS_SOLUTION_H
