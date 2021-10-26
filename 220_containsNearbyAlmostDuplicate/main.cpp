#include <iostream>
#include "Solution.h"

using namespace std;

int main() {
    Solution solution;
    vector<int> arr{1,2,3,1};
    solution.containsNearbyAlmostDuplicate(arr,3,0);
    return 0;
}
