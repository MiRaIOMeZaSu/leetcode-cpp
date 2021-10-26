//
// Created by timeC on 2021/3/12.
//

#ifndef INC_503_NEXTGREATERELEMENTS_SOLUTION_H
#define INC_503_NEXTGREATERELEMENTS_SOLUTION_H

#include<stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int size = nums.size();
//        int list[nums.size()];
        stack<int> s;
        vector<int> result(size);
        for (int i = size * 2 - 1; i >= 0; i--) {
            // 转了一圈回到开始
            while (!s.empty() && !(nums[i % size] < s.top())) {
                s.pop();
            }
            result[i % size] = !s.empty() ? s.top() : -1;
            s.push(nums[i % size]);
        }
//        vector<int> result(list, list + nums.size());
        return result;
    }
};


#endif //INC_503_NEXTGREATERELEMENTS_SOLUTION_H
