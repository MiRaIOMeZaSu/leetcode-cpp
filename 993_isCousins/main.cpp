#include <iostream>

#include "Solution.h"

using namespace std;

int main() {
    TreeNode *_1 = new TreeNode(1);
    TreeNode *_2 = new TreeNode(2);
    TreeNode *_3 = new TreeNode(3);
    _1->left = _2;
    _1->right = _3;
    TreeNode *_4 = new TreeNode(4);
    _2->left = _4;
    Solution solution;
    solution.isCousins(_1, 2, 3);
    return 0;
}
