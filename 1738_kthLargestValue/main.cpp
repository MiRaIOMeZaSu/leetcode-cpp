#include <iostream>

#include "Solution.h"

using namespace std;

int main() {
    vector<vector<int>> graph{{5,2},{1,6}};

    Solution solution;
    solution.kthLargestValue(graph,1);
    return 0;
}
