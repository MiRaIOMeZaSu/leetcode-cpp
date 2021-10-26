#include <iostream>
#include "Solution.h"

using namespace std;

int main() {
    Solution solution;
    vector<int> a{1, 1};
    vector<vector<int>> input{a};
    solution.searchMatrix(input, 0);
    return 0;
}
