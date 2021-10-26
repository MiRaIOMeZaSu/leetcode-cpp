#include <iostream>
#include "Solution.h"
#include <vector>

int main() {
    vector<int> num;
    // [-2,-1]
    // [4,10,4,3,8,9]
    // [1,3,6,7,9,4,10,5,6]
    num.push_back(1);
    num.push_back(3);
    num.push_back(6);
    num.push_back(7);
    num.push_back(9);
    num.push_back(4);
    num.push_back(10);
    num.push_back(5);
    num.push_back(6);

    Solution solution;
    cout <<"result: "<< solution.lengthOfLIS(num);
    return 0;
}
