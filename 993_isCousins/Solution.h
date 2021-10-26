//
// Created by timeC on 2021/5/17.
//

#ifndef INC_993_ISCOUSINS_SOLUTION_H
#define INC_993_ISCOUSINS_SOLUTION_H


#include <unordered_set>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode *root, int x, int y) {
        // 遍历并存储深度
        unordered_set<int> target;
        target.insert(x);
        target.insert(y);
        queue<pair<pair<int, int>, TreeNode *>> q;
        q.push(make_pair(make_pair(1, root->val), root));
        int targetDepth = INT_MAX;
        int depth = 1;
        int lastFather = -1;
        while (!q.empty() && depth <= targetDepth) {
            pair<pair<int, int>, TreeNode *> pivot = q.front();
            q.pop();
            depth = pivot.first.first;
            if (target.count(pivot.second->val)) {
                if (targetDepth == INT_MAX) {
                    targetDepth = pivot.first.first;
                    lastFather = pivot.first.second;
                } else if (targetDepth == pivot.first.first) {
                    return lastFather != pivot.first.second;
                }
            }
            if (pivot.second->left != nullptr) {
                q.push(make_pair(make_pair(pivot.first.first + 1, pivot.second->val), pivot.second->left));
            }
            if (pivot.second->right != nullptr) {
                q.push(make_pair(make_pair(pivot.first.first + 1, pivot.second->val), pivot.second->right));
            }
        }
        return false;
    }
};


#endif //INC_993_ISCOUSINS_SOLUTION_H
