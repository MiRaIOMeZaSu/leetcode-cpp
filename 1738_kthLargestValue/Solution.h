//
// Created by timeC on 2021/5/20.
//

#ifndef INC_1738_KTHLARGESTVALUE_SOLUTION_H
#define INC_1738_KTHLARGESTVALUE_SOLUTION_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>> &matrix, int k) {
        // 必须计算出所有坐标下的结果?
        int m = matrix.size();
        int n = matrix[0].size();
        int graph[m][n];
        vector<int> ret;
        graph[0][0] = matrix[0][0];
        ret.emplace_back(matrix[0][0]);
        for (int i = 1; i < m; i++) {
            graph[i][0] = graph[i - 1][0] ^ matrix[i][0];
            ret.emplace_back(graph[i][0]);
        }
        for (int i = 1; i < n; i++) {
            graph[0][i] = graph[0][i - 1] ^ matrix[0][i];
            ret.emplace_back(graph[0][i]);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                graph[i][j] = graph[i - 1][j - 1] ^ graph[i][j - 1] ^ graph[i - 1][j] ^ matrix[i][j];
                ret.emplace_back(graph[i][j]);
            }
        }
        sort(ret.rbegin(), ret.rend());
        return ret[k - 1];
    }
};


#endif //INC_1738_KTHLARGESTVALUE_SOLUTION_H
