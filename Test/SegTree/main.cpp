#include <iostream>
#include "Solution.h"

using namespace std;

int main() {
    Solution solution;
    vector<int> input{1, 3, 3, 3, 2, 4, 2, 1, 2};
    solution.createSortedArray(input);
    return 0;
}
