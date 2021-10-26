//
// Created by timeC on 2021/6/11.
//

#ifndef INC_279_NUMSQUARES_SOLUTION_H
#define INC_279_NUMSQUARES_SOLUTION_H

#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        vector<int> arrTable;
        unordered_set<int> nums;
        int curr = 1;
        int num = pow(curr, 2);
        while (num <= n) {
            arrTable.emplace_back(num);
            nums.insert(num);
            curr++;
            num = pow(curr, 2);
        }
        arrTable.emplace_back(num);
        nums.insert(num);
        if (nums.count(n)) {
            return 1;
        }
        for (int i = 2; i <= n; i++) {

            if (nums.count(i)) {
                dp[i] = 1;
                continue;
            }
            dp[i] = INT_MAX;
            int toMinusIndex = 0;
            int toMinus = arrTable[toMinusIndex];
            while (toMinus < i) {
                dp[i] = min(dp[i], dp[i - toMinus] + 1);
                toMinusIndex++;
                toMinus = arrTable[toMinusIndex];
            }
        }
        return dp[n];
    }
};


#endif //INC_279_NUMSQUARES_SOLUTION_H
