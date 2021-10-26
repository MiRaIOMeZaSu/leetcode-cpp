//
// Created by timeC on 2021/6/20.
//

#ifndef INC_5790_MINDIFFERENCE_SOLUTION_H
#define INC_5790_MINDIFFERENCE_SOLUTION_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries) {
        // queries数组的大小巨大
        // nums的大小同样巨大
        int dp[nums.size()][nums.size()];
        memset(dp,0,sizeof(int) * nums.size() * nums.size());

    }
};

#endif //INC_5790_MINDIFFERENCE_SOLUTION_H
