//
// Created by timeC on 2021/3/8.
//

#ifndef INC_28_STRSTR_SOLUTION_H
#define INC_28_STRSTR_SOLUTION_H

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // 先实现dp表的创建和填充
        int size_need = needle.size();
        if (size_need == 0) {
            return 0;
        }
        int size_hay = haystack.length();
        // 只有小写字母a-z
        int dp[size_need][26];
        for (int i = 0; i < size_need; i++) {
            for (int j = 0; j < 26; j++) {
                dp[i][j] = 0;
            }
        }
        // 当处于状态1时
        dp[0][needle[0] - 'a'] = 1;
        int shadow = 0;
        int charNum;
        for (int i = 1; i < size_need; i++) {
            for (int j = 0; j < 26; j++) {
                charNum = needle[i] - 'a';
                if (charNum == j) {
                    dp[i][j] = dp[i - 1][needle[i - 1] - 'a'] + 1;
                } else {
                    // shadow的出场
                    dp[i][j] = dp[shadow][j];
                }
            }
            // 更新shadow
            shadow = dp[shadow][needle[i] - 'a'];
        }
        int state = 0;
//        cout << dp[1]['l' - 'a'] << endl;
        for (int i = 0; i < size_hay; i++) {
            state = dp[state][haystack[i] - 'a'];
//            cout << "state: " << state << "; i: " << i << endl;
            if (state == size_need) {
                return i + 1 - size_need;
            }
        }
        return -1;
    }
};


#endif //INC_28_STRSTR_SOLUTION_H
