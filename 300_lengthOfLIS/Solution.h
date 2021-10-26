//
// Created by timeC on 2021/3/5.
//

#ifndef INC_300_LENGTHOFLIS_SOLUTION_H
#define INC_300_LENGTHOFLIS_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        // dp table: 以每个下标记录相应index的数字为最后一位时最长递增子序列的长度
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        int dp[len];
        for (int i = 0; i < len; i++) {
            dp[i] = 1;
        }
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                } else if (nums[i] == nums[j]) {
                    dp[i] = max(dp[j], dp[i]);
                }
            }
        }
//        for (int i = 0; i < len; i++) {
//            cout << dp[i] << " ";
//        }
//        cout << endl;
        int result = 1;
        for (int i = 0; i < len; i++) {
            result = max(result, dp[i]);
        }
        return result;
    }
};


#endif //INC_300_LENGTHOFLIS_SOLUTION_H
