#include <iostream>
#include "Solution.h"

using namespace std;
int main() {
    Solution solution;
    vector<char> a{'1','1','1','1','0'};
    vector<char> b{'1','1','0','1','0'};
    vector<char> c{'1','1','0','0','0'};
    vector<char> d{'0','0','0','0','0'};
    vector<vector<char>> input{a, b, c, d};
    solution.numIslands(input);
    return 0;
}
