#include <iostream>

#include "Solution.h"

int main() {
    Solution solution;
    vector<string> input{"i", "love", "leetcode", "i", "love", "coding"};
    solution.topKFrequent(input,2);
    return 0;
}
