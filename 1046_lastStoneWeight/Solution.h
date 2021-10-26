//
// Created by timeC on 2021/6/8.
//

#ifndef INC_1046_LASTSTONEWEIGHT_SOLUTION_H
#define INC_1046_LASTSTONEWEIGHT_SOLUTION_H

#include <vector>
#include <set>
#include <queue>

using namespace std;


class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        int size = stones.size();
        priority_queue<int> nums;
        for (int i = 0; i < size; i++) {
            nums.push(stones[i]);
        }
        while (nums.size() > 1) {
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();
            int c = abs(a - b);
            if (c != 0) {
                nums.push(c);
            }
        }
        if (nums.empty()) {
            return 0;
        }
        return nums.top();
    }
};


#endif //INC_1046_LASTSTONEWEIGHT_SOLUTION_H
