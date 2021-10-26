#include <iostream>
#include "Solution.h"

using namespace std;


int main() {
    Solution solution;
    vector<vector<int>> input{{1,2,2,1},{3,1,2},{1,3,2},{2,4},{3,1,2},{1,3,1,1}};
    solution.leastBricks(input);
    return 0;
}
