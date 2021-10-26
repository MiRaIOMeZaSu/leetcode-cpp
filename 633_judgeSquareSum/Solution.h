//
// Created by timeC on 2021/4/28.
//

#ifndef INC_633_JUDGESQUARESUM_SOLUTION_H
#define INC_633_JUDGESQUARESUM_SOLUTION_H

#include <math.h>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        // 使用双指针
        int left = 0;
        int right = sqrt(c);
        while (left <= right) {
            long goal = pow(left, 2) + pow(right, 2);
            if (goal > c) {
                right--;
            } else if (goal < c) {
                left++;
            } else {
                return true;
            }
        }
        return false;
    }
};


#endif //INC_633_JUDGESQUARESUM_SOLUTION_H
