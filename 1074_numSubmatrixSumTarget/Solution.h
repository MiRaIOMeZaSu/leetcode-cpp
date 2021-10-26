//
// Created by timeC on 2021/5/29.
//

#ifndef INC_1074_NUMSUBMATRIXSUMTARGET_SOLUTION_H
#define INC_1074_NUMSUBMATRIXSUMTARGET_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
        // 找到所有的矩阵
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m][n];
        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(matrix[i][j]==target){
                    ret++;
                }
            }
        }
        dp[0][0] = matrix[0][0];
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1] + matrix[0][i];
            int temp = dp[0][i];
            if (temp == target) {
                ret++;
            }
        }
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + matrix[i][0];
            int temp = dp[i][0];
            if (temp == target) {
                ret++;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + matrix[i][j] - dp[i - 1][j - 1];
                int temp = dp[i][j];
                if (temp == target) {
                    ret++;
                }
            }
        }
        // 初始化结束
        for (int iGap = 0; iGap < m; iGap++) {
            for (int jGap = 0; jGap < n; jGap++) {
                if (iGap == 0 && jGap == 0) {
                    continue;
                }
                for (int i = 0; i < m - iGap; i++) {
                    for (int j = 0; j < n - jGap; j++) {
                        if (i == 0 && j == 0) {
                            continue;
                        }
                        bool bool1 = i > 0;
                        bool bool2 = j > 0;
                        int a = bool1 ? dp[i - 1][j + jGap] : 0;
                        int b = bool2 ? dp[i + iGap][j - 1] : 0;
                        int c = bool1 && bool2 ? dp[i - 1][j - 1] : 0;
                        int temp = dp[i + iGap][j + jGap] - a - b + c;
                        if (temp == target) {
                            ret++;
                        }
                    }
                }
            }
        }
        return ret;
    }
};

#endif //INC_1074_NUMSUBMATRIXSUMTARGET_SOLUTION_H
