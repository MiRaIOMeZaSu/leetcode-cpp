//
// Created by timeC on 2021/6/11.
//

#ifndef INC_805_SPLITARRAYSAMEAVERAGE_SOLUTION_H
#define INC_805_SPLITARRAYSAMEAVERAGE_SOLUTION_H

#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int> &nums) {
        // 只要求均值相同,和并不需要相同
        // 求出加和,则可以通过当前加和获得剩余数的加和(此种方法无法获得数量)
        // 01背包问题
        // 存储并遍历数量?
        // 范围:0~300000
        // 直接使用哈希表代替数组
        // 只统计平均值(不行,因为存在无法整除的情况!)
        int maxNum = *max_element(nums.begin(), nums.end());
        // 最大平均值是maxNum,最大数量是nums.size() - 1
        int dp[maxNum + 1][nums.size()];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < nums.size(); i++) {
            for (int j = maxNum; j >= 0; j--) {
                for (int x = nums.size() - 2; x >= 0; x++) {
                    int OriginSum =  x * j + nums[i]
                }
            }
        }
    }
};


#endif //INC_805_SPLITARRAYSAMEAVERAGE_SOLUTION_H
