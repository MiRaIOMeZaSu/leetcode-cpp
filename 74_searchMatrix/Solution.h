//
// Created by timeC on 2021/4/22.
//

#ifndef INC_74_SEARCHMATRIX_SOLUTION_H
#define INC_74_SEARCHMATRIX_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    int m;
    int n;
    int i;
    int j;

    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        m = matrix.size();
        n = matrix[0].size();
        int size = m * n;
        int left = 0;
        int right = size - 1;
        while (left < right && right < size) {
            int mid = left + (right - left) / 2;
            getPos(mid);
            int midNum = matrix[i][j];
            if (midNum < target) {
                left = mid + 1;
            } else if (midNum > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        int leftNum = INT_MAX;
        int rightNum = INT_MAX;
        if (left >= 0 && left < size) {
            getPos(left);
            leftNum = matrix[i][j];
        }
        if (left != right) {
            if (right >= 0 && right < size) {
                getPos(right);
                rightNum = matrix[i][j];
            }
        } else {
            rightNum = leftNum;
        }
        return leftNum == target || rightNum == target;
    }

    void getPos(int id) {
        i = id / n;
        j = id % n;
    }
};

#endif //INC_74_SEARCHMATRIX_SOLUTION_H
