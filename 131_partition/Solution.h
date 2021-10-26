//
// Created by timeC on 2021/4/24.
//

#ifndef INC_131_PARTITION_SOLUTION_H
#define INC_131_PARTITION_SOLUTION_H

#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> ret;
    bool dp[16][16];
    string string1;

    vector<vector<string>> partition(string s) {
        // 使用过动态规划寻找所有的回文
        string1 = s;
        memset(dp, false, sizeof(dp));
        for (int i = 0; i < s.size() - 1; i++) {
            dp[i][i] = true;
            dp[i][i + 1] = (s[i] == s[i + 1]);
        }
        dp[s.size() - 1][s.size() - 1] = true;
        for (int i = 3; i <= s.size(); i++) {
            // 要找的长度为3到s.size()-1
            for (int j = 0; j + i - 1 <= s.size() - 1; j++) {
                dp[j][j + i - 1] = dp[j + 1][j + i - 1 - 1] && (s[j] == s[i + j - 1]);
            }
        }
        vector<string> temp;
        solve(0, temp);
        return ret;
    }

    void solve(int index, vector<string> &r) {
        if (index == string1.size()) {
            vector<string> temp(r);
            ret.emplace_back(temp);
            return;
        }
        for (int i = index; i < string1.size(); i++) {
            if (dp[index][i]) {
                r.emplace_back(string1.substr(index, i - index + 1));
                solve(i + 1, r);
                r.pop_back();
            }
        }
    }
};


#endif //INC_131_PARTITION_SOLUTION_H
