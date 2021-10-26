//
// Created by timeC on 2021/4/16.
//

#ifndef INC_152_MAXPRODUCT_SOLUTION_H
#define INC_152_MAXPRODUCT_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        // 双指针?前缀积?
        // 整数数组,要考虑的只有零和符号
        // 对每个小标,以该下标为尾的最大和最小乘积
        int lastMin = nums[0];
        int lastMax = nums[0];
        int ret = lastMax;
        for (int i = 1; i < nums.size(); i++) {
            int temp_lastMax = lastMax;
            lastMax = max(lastMax * nums[i], nums[i]);
            lastMax = max(lastMax, lastMin * nums[i]);
            lastMin = min(lastMin * nums[i], nums[i]);
            lastMin = min(lastMin, temp_lastMax * nums[i]);
            ret = max(lastMax, ret);
        }
        return ret;
    }
};


#endif //INC_152_MAXPRODUCT_SOLUTION_H
