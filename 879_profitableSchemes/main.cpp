#include <iostream>

#include "Solution.h"

using namespace std;

int main() {
    vector<int> input1{2, 3, 5};
    vector<int> input2{6, 7, 8};
    Solution solution;
    solution.profitableSchemes(10, 5, input1, input2);
    return 0;
}
