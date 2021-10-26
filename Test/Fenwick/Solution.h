//
// Created by timeC on 2021/4/19.
//

#ifndef FENWICK_SOLUTION_H
#define FENWICK_SOLUTION_H

#include <vector>
#include <algorithm>

using namespace std;

class BIT {
private:
    int n;
    vector<int> tree;
public:
    BIT(int _n): n(_n), tree(_n + 1) {}

    static constexpr int lowbit(int x) {
        return x & (-x);
    }

    void update(int x) {
        while (x <= n) {
            ++tree[x];
            x += lowbit(x);
        }
    }

    int query(int x) const {
        int ans = 0;
        while (x) {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }
};

class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int createSortedArray(vector<int>& instructions) {
        int ub = *max_element(instructions.begin(), instructions.end());
        BIT bit(ub);
        long long ans = 0;
        for (int i = 0; i < instructions.size(); ++i) {
            int x = instructions[i];
            // 寻找
            int smaller = bit.query(x - 1);
            int larger = i - bit.query(x);
            ans += min(smaller, larger);
            // 插入
            bit.update(x);
        }
        return ans % mod;
    }
};


#endif //FENWICK_SOLUTION_H
