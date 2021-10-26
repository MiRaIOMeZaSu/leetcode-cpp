//
// Created by timeC on 2021/6/20.
//

#ifndef INC_5791_COUNTSUBISLANDS_SOLUTION_H
#define INC_5791_COUNTSUBISLANDS_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    int global1 = 2;
    vector<vector<bool> *> *visit1;
    vector<vector<bool> *> *visit2;
    vector<vector<int>> graph1;
    vector<vector<int>> graph2;
    int m, n;
    vector<vector<int>> items{{0,  1},
                              {0,  -1},
                              {-1, 0},
                              {1,  0}};
    int ret = 0;

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        // 需要重合的除形状外还有绝对位置
        graph1 = grid1;
        graph2 = grid2;
        m = grid1.size();
        n = grid1[0].size();
        visit1 = new vector<vector<bool> *>(m);
        for (int i = 0; i < grid1.size(); i++) {
            visit1->at(i) = new vector<bool>(n);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit1->at(i)->at(j) && graph1[i][j] == 1) {
                    fillDiffColor(i, j);
                    global1++;
                }
                visit1->at(i)->at(j) = true;
            }
        }
        visit2 = new vector<vector<bool> *>(graph2.size());
        for (int i = 0; i < grid1.size(); i++) {
            visit2->at(i) = new vector<bool>(n);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit2->at(i)->at(j) && graph2[i][j] == 1) {
                    if (solve(i, j, graph1[i][j])) {
                        ret++;
                    }
                }
                visit2->at(i)->at(j) = true;
            }
        }
        return ret;
    }

    void fillDiffColor(int i, int j) {
        if (visit1->at(i)->at(j)) {
            return;
        }
        visit1->at(i)->at(j) = true;
        if (graph1[i][j] == 1) {
            graph1[i][j] = global1;
            for (int s = 0; s < 4; s++) {
                int y = i + items[s][0];
                int x = j + items[s][1];
                if (y >= 0 && x >= 0 && y < m && x < n) {
                    fillDiffColor(y, x);
                }
            }
        }
    }

    bool solve(int i, int j, int color) {
        if (visit2->at(i)->at(j)) {
            return true;
        }
        visit2->at(i)->at(j) = true;
        bool temp = true;
        if (graph2[i][j] == 1) {
            if (graph1[i][j] != color || graph1[i][j] == 0) {
                temp = false;
            }
            for (int s = 0; s < 4; s++) {
                int y = i + items[s][0];
                int x = j + items[s][1];
                if (y >= 0 && x >= 0 && y < m && x < n) {
                    temp &= solve(y, x, color);
                }
            }
        }
        return temp;
    }
};

#endif //INC_5791_COUNTSUBISLANDS_SOLUTION_H
