//
// Created by timeC on 2021/3/4.
//

#ifndef INC_167_TWOSUM_SOLUTION_H
#define INC_167_TWOSUM_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // 使用双指针法
        vector<int> result;
        int left = 0;
        int right = numbers.size() - 1;
        while (left != right) {
            if (numbers[left] + numbers[right] == target) {
                result.push_back(left + 1);
                result.push_back(right + 1);
                return result;
            } else if (numbers[left] + numbers[right] > target) {
                right--;
            } else if (numbers[left] + numbers[right] < target) {
                left++;
            }
        }
        return result;
    }
};


#endif //INC_167_TWOSUM_SOLUTION_H
