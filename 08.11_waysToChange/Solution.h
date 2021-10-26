//
// Created by timeC on 2021/6/13.
//

#ifndef INC_08_11_WAYSTOCHANGE_SOLUTION_H
#define INC_08_11_WAYSTOCHANGE_SOLUTION_H

#include <cstring>

using namespace std;

class Solution {
public:
    int waysToChange(int n) {
        // 25分、10分、5分和1分
        int dp[n + 1];
        int coins[]{25, 10, 5, 1};
        memset(dp, 0, sizeof(int) * (n + 1));
        dp[0] = 1;
        for (int i = 0; i < 4; i++) {
            int coin = coins[i];
            for (int j = coin; j <= n; j++) {
                dp[j] += dp[j - coin];
                dp[j] %= 1000000007;
            }
        }
        return dp[n];
    }
};


#endif //INC_08_11_WAYSTOCHANGE_SOLUTION_H
