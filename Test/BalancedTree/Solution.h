//
// Created by timeC on 2021/4/19.
//

#ifndef BALANCEDTREE_SOLUTION_H
#define BALANCEDTREE_SOLUTION_H

#include <vector>
#include <random>

using namespace std;

// 重复结点通过已存在相应值结点数量记录存储
class BalancedTree {
private:
    struct BalancedNode {
        int val;
        int seed;
        int count;
        int size;
        BalancedNode* left;
        BalancedNode* right;

        BalancedNode(int _val, int _seed): val(_val), seed(_seed), count(1), size(1), left(nullptr), right(nullptr) {}
        // 用于维护平衡二叉树的左旋转
        BalancedNode* left_rotate() {
            int prev_size = size;
            int curr_size = (left ? left->size : 0) + (right->left ? right->left->size : 0) + count;
            BalancedNode* root = right;
            right = root->left;
            root->left = this;
            root->size = prev_size;
            size = curr_size;
            return root;
        }
        // 用于维护平衡二叉树的右旋转
        BalancedNode* right_rotate() {
            int prev_size = size;
            int curr_size = (right ? right->size : 0) + (left->right ? left->right->size : 0) + count;
            BalancedNode* root = left;
            left = root->right;
            root->right = this;
            root->size = prev_size;
            size = curr_size;
            return root;
        }
    };

private:
    BalancedNode* root;
    int size;
    mt19937 gen;
    uniform_int_distribution<int> dis;

private:
    // 插入,并检查平衡性,如不平衡则进行旋转
    BalancedNode* insert_(BalancedNode* node, int x) {
        if (!node) {
            return new BalancedNode(x, dis(gen));
        }
        // 此操作保证无论是否是重复的,相应值的结点本身和所有父节点的大小记录值都加一
        ++node->size;
        if (x < node->val) {
            node->left = insert_(node->left, x);
            if (node->left->seed > node->seed) {
                node = node->right_rotate();
            }
        }
        else if (x > node->val) {
            node->right = insert_(node->right, x);
            if (node->right->seed > node->seed) {
                node = node->left_rotate();
            }
        }
        else {
            ++node->count;
        }
        return node;
    }

public:
    BalancedTree(): root(nullptr), size(0), gen(random_device{}()), dis(INT_MIN, INT_MAX) {}

    int get_size() const {
        return size;
    }

    void insert(int x) {
        ++size;
        root = insert_(root, x);
    }
    // 寻找比输入x小的最大值
    int lower_bound(int x) const {
        BalancedNode* node = root;
        int ans = INT_MAX;
        while (node) {
            if (x == node->val) {
                return x;
            }
            if (x < node->val) {
                ans = node->val;
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
        return ans;
    }
    // 寻找比输入的y大的最小值
    int upper_bound(int x) const {
        BalancedNode* node = root;
        int ans = INT_MAX;
        while (node) {
            if (x < node->val) {
                ans = node->val;
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
        return ans;
    }
    // 由于是平衡二叉搜索树,通过相应值可以直接通过获取相应左子树的大小得到比相应值小的数字的数量
    pair<int, int> rank(int x) const {
        BalancedNode* node = root;
        int ans = 0;
        while (node) {
            if (x < node->val) {
                node = node->left;
            }
            else {
                ans += (node->left ? node->left->size : 0) + node->count;
                if (x == node->val) {
                    return {ans - node->count + 1, ans};
                }
                node = node->right;
            }
        }
        return {INT_MIN, INT_MAX};
    }
};

class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int createSortedArray(vector<int>& instructions) {
        BalancedTree treap;
        long long ans = 0;
        for (int i = 0; i < instructions.size(); ++i) {
            int x = instructions[i];
            // 寻找左边界
            int lb = treap.lower_bound(x);
            int smaller = (lb == INT_MAX ? i : treap.rank(lb).first - 1);
            // 寻找右边界
            int rb = treap.upper_bound(x);
            int larger = (rb == INT_MAX ? 0 : i - treap.rank(rb).first + 1);
            ans += min(smaller, larger);
            // 插入新值
            treap.insert(x);
        }
        return ans % mod;
    }
};


#endif //BALANCEDTREE_SOLUTION_H
