#include <iostream>

#include "Solution.h"

int main() {
    Solution solution;
    vector<int> num;
//    numbers = [2,7,11,15], target = 9
    num.push_back(-1);
    num.push_back(0);
//    num.push_back(4);
//    num.push_back(15);
    vector<int> result = solution.twoSum(num, -1);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
