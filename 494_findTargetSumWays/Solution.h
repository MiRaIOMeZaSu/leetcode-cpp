//
// Created by timeC on 2021/6/7.
//

#ifndef INC_494_FINDTARGETSUMWAYS_SOLUTION_H
#define INC_494_FINDTARGETSUMWAYS_SOLUTION_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        // 回溯法?
        // 使用迭代,在集合中存储中间状态合并相同的情况以剪枝
        // 状压?
        // 求的是数量
        // 往前找可能性?
        // 广度优先遍历!
        unordered_map<int, int> *curr = new unordered_map<int, int>;
        unordered_map<int, int> *next = new unordered_map<int, int>;
        int num = nums[0];
        if(num==0){
            curr->insert(make_pair(0, 2));
        }else{
            for (int i = -num; i <= num; i += 2 * num) {
                if (!curr->count(i)) {
                    curr->insert(make_pair(i, 0));
                }
                curr->at(i)++;
            }
        }
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if (num == 0) {
                for (auto it = curr->begin(); it != next->end(); it++) {
                    int temp = curr->at(it->first);
                    curr->at(it->first) += temp;
                }
                continue;
            }
            for (auto it = curr->begin(); it != next->end(); it++) {
                int lastKey = it->first;
                for (int j = -num; j <= num; j += 2 * num) {
                    int key = j + lastKey;
                    if (!next->count(key)) {
                        next->insert(make_pair(key, 0));
                    }
                    next->at(key) += curr->at(lastKey);
                }
            }
            curr = next;
            next = new unordered_map<int, int>;
        }
        if (!curr->count(target)) {
            return 0;
        }
        return curr->at(target);
    }
};


#endif //INC_494_FINDTARGETSUMWAYS_SOLUTION_H
