//
// Created by timeC on 2021/5/2.
//

#ifndef INC_554_LEASTBRICKS_SOLUTION_H
#define INC_554_LEASTBRICKS_SOLUTION_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>> &wall) {
        unordered_map<int, int> table;
        int maxCount = 0;
        for (int i = 0; i < wall.size(); i++) {
            if (wall[i].size() != 1) {
                int len = 0;
                for (int j = 0; j < wall[i].size() - 1; j++) {
                    len += wall[i][j];
                    if (!table.count(len)) {
                        table.insert(make_pair(len, 0));
                    }
                    table[len]++;
                    maxCount = max(table[len], maxCount);
                }
            }
        }
        return wall.size() - maxCount;
    }
};

#endif //INC_554_LEASTBRICKS_SOLUTION_H
