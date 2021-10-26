//
// Created by timeC on 2021/3/13.
//

#ifndef INC_1_TWOSUM_SOLUTION_H
#define INC_1_TWOSUM_SOLUTION_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int other = target - nums[i];
            if (map.count(other) && map[other] != i) {
                result.push_back(i);
                result.push_back(map[other]);
                return result;
            }
        }
        return result;
    }
};


#endif //INC_1_TWOSUM_SOLUTION_H
