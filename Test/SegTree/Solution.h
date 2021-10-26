//
// Created by timeC on 2021/4/19.
//

#ifndef SEGTREE_SOLUTION_H
#define SEGTREE_SOLUTION_H

#include <vector>
#include <algorithm>

using namespace std;

class SegTree {
private:
    int n;
    // 存储的是下标
    vector<int> segnode;

private:
    void update_(int id, int l, int r, int x) {
        // id为用于存储的区间的下标,l-r为此时的区间,x为终止条件,当x不再在[l,r]区间内时结束
        if (l > x || r < x) {
            return;
        }
        ++segnode[id];
        if (l == r) {
            return;
        }
        // 向下取整
        int mid = (l + r) >> 1;
        // 二分,更新指定区间在数组中指定id下标的值
        update_(id * 2 + 1, l, mid, x);
        update_(id * 2 + 2, mid + 1, r, x);
    }

    int query_(int id, int l, int r, int ql, int qr) const {
        if (l > qr || r < ql) {
            // 如果区间没有重合部分则无视
            return 0;
        }
        if (ql <= l && r <= qr) {
            // 当搜索的范围包含此二分划分的区间时,返回
            return segnode[id];
        }
        int mid = (l + r) >> 1;
        // 如果区间仍然过大,大于要搜索的区间,进行二分
        return query_(id * 2 + 1, l, mid, ql, qr) + query_(id * 2 + 2, mid + 1, r, ql, qr);
    }

public:
    SegTree(int _n): n(_n), segnode(_n * 4) {}

    void update(int x) {
        update_(0, 1, n, x);
    }

    int query(int left, int right) const {
        return query_(0, 1, n, left, right);
    }
};

class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int createSortedArray(vector<int>& instructions) {
        int ub = *max_element(instructions.begin(), instructions.end());
        SegTree tree(ub);
        long long ans = 0;
        for (int i = 0; i < instructions.size(); ++i) {
            int x = instructions[i];
            // 寻找的是下标
            int smaller = tree.query(1, x - 1);
            int larger = tree.query(x + 1, ub);
            ans += min(smaller, larger);
            tree.update(x);
        }
        return ans % mod;
    }
};

#endif //SEGTREE_SOLUTION_H
