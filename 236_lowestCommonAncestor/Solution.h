//
// Created by timeC on 2021/4/16.
//

#ifndef INC_236_LOWESTCOMMONANCESTOR_SOLUTION_H
#define INC_236_LOWESTCOMMONANCESTOR_SOLUTION_H

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<bool> path_p;
    vector<bool> path_q;

    bool pfinded = false;
    bool qfinded = false;
    TreeNode *pivot_p;
    TreeNode *pivot_q;

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // 搜索并存储路径,最后倒序分析路径
        // 对两条路径,其终点都应该为指定节点
        // 广度优先: 无法方便的存储路径,每一次使用的节点左右关系如何确定
        // 深度优先:
        pivot_p = p;
        pivot_q = q;
        solve(root, true);
        int i = 0;
        int size = min(path_p.size(), path_q.size());
        while (i < size) {
            if (path_p[i] != path_q[i]) {
                break;
            }
            i++;
        }
        TreeNode *ret = root;
        for (int j = 1; j < i; j++) {
            if (path_p[j]) {
                ret = ret->left;
            } else {
                ret = ret->right;
            }
        }
        return ret;
    }

    void solve(TreeNode *root, bool choiceLeft) {
        if (pfinded && qfinded) {
            return;
        } else {
            if (!pfinded) {
                path_p.emplace_back(choiceLeft);
            }
            if (!qfinded) {
                path_q.emplace_back(choiceLeft);
            }
            if (root == pivot_p) {
                pfinded = true;
            }
            if (root == pivot_q) {
                qfinded = true;
            }
            if (root->left != nullptr) {
                solve(root->left, true);
                if (!pfinded) {
                    path_p.pop_back();
                }
                if (!qfinded) {
                    path_q.pop_back();
                }
            }
            if (root->right != nullptr) {
                solve(root->right, false);
                if (!pfinded) {
                    path_p.pop_back();
                }
                if (!qfinded) {
                    path_q.pop_back();
                }
            }
        }
    }
};

#endif //INC_236_LOWESTCOMMONANCESTOR_SOLUTION_H
