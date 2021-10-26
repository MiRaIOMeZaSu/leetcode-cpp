#include <iostream>
#include "Solution.h"

using namespace std;

int main() {
    Solution solution;
    vector<int> input{3,2,3,1,2,4,5,5,6};
    solution.findKthLargest(input, 8);
    return 0;
}
