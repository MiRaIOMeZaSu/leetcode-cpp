#include <iostream>

#include "Solution.h"


int main() {
    Solution solution;
    vector<vector<int>> input1{{1, 1, 1, 0, 0},
                               {0, 1, 1, 1, 1},
                               {0, 0, 0, 0, 0},
                               {1, 0, 0, 0, 0},
                               {1, 1, 0, 1, 1}};
    vector<vector<int>> input2{{1, 1, 1, 0, 0},
                               {0, 1, 1, 1, 1},
                               {0, 0, 0, 0, 0},
                               {1, 0, 0, 0, 0},
                               {1, 1, 0, 1, 1}};
    int ret = solution.countSubIslands(input1, input2);
    cout << ret << endl;
    return 0;
}
