#include <iostream>
#include "Solution.h"

using namespace std;


int main() {
    Solution solution;
    TreeNode *root = new TreeNode(3);
    TreeNode *_2 = new TreeNode(5);
    TreeNode *_3 = new TreeNode(1);
    TreeNode *_4 = new TreeNode(6);
    TreeNode *_5 = new TreeNode(2);
    TreeNode *_6 = new TreeNode(0);
    TreeNode *_7 = new TreeNode(8);
    TreeNode *_8 = new TreeNode(7);
    TreeNode *_9 = new TreeNode(4);
    root->left = _2;
    root->right = _3;
    _2->left = _4;
    _2->right = _5;
    _5->left = _8;
    _5->right = _9;
    _3->left = _6;
    _3->right = _7;
    solution.lowestCommonAncestor(root, _2, _9);
    return 0;
}
