//
// Created by timeC on 2021/6/9.
//

#ifndef INC_879_PROFITABLESCHEMES_SOLUTION_H
#define INC_879_PROFITABLESCHEMES_SOLUTION_H

#include <vector>
#include <cstring>

using namespace std;

static int pivot = 1000000007;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit) {
        // 将minProfit+1位置处的值视为所有大于minProfit的值的状况
        int dp[minProfit + 2][n + 1];
        memset(dp, 0, sizeof(int) * (minProfit + 2) * (n + 1));
        dp[0][0] = 1;
        for (int i = 0; i < group.size(); i++) {
            // 在开头添加上仍旧会大于minProfit的部分,不能普通地添加,会出现重复情况!
            // 应该从n开始添加
            for (int j = minProfit + 1; j >= 0; j--) {
                int targetProfit = j + profit[i];
                bool flag = targetProfit > minProfit;
                if (flag) {
                    targetProfit = minProfit + 1;
                }
                for (int x = n; x >= 0; x--) {
                    int targetN = x + group[i];
                    if (targetN > n) {
                        continue;
                    }
                    dp[targetProfit][targetN] += dp[j][x];
                    dp[targetProfit][targetN] %= pivot;
                }
            }
        }
        int ret = 0;
        for (int i = minProfit; i < minProfit + 2; i++) {
            for (int j = 1; j <= n; j++) {
                ret += dp[i][j];
                ret %= pivot;
            }
        }
        if(minProfit==0){
            ret+=1;
        }
        return ret;
    }
};


#endif //INC_879_PROFITABLESCHEMES_SOLUTION_H
