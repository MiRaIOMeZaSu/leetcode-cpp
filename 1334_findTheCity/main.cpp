#include <iostream>

#include "Solution.h"

using namespace std;

int main() {
    Solution solution;
    vector<vector<int>> input{{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    int ret = solution.findTheCity(4,input, 4);
    cout << ret << endl;
    return 0;
}
