#include <iostream>
#include "Solution.h"

using namespace std;

int main() {
    Solution solution;
    vector<int> result = solution.findAnagrams("", "a");
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
