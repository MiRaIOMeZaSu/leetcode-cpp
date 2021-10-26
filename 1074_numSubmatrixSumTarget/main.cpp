#include <iostream>

#include "Solution.h"

using namespace std;

int main() {
    Solution solution;
    vector<vector<int>> input{{0,1,1,1,0,1},{0,0,0,0,0,1},{0,0,1,0,0,1},{1,1,0,1,1,0},{1,0,0,1,0,0}};
    solution.numSubmatrixSumTarget(input, 0);
    return 0;
}
