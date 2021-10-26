#include <iostream>

#include "Solution.h"

using namespace std;

int main() {
    Solution solution;
    vector<int> input = {1,1,1,1,1,2,3};
    vector<int> result = solution.nextGreaterElements(input);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    return 0;
}
