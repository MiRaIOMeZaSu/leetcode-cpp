#include <iostream>

#include "Solution.h"

using namespace std;

int main() {
    Solution solution;
    string str = "(2+6* 3+5- (3*14/7+2)*5)+3";
    cout << solution.calculate(str);
    return 0;
}
