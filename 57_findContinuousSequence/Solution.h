//
// Created by timeC on 2021/6/19.
//

#ifndef INC_57_FINDCONTINUOUSSEQUENCE_SOLUTION_H
#define INC_57_FINDCONTINUOUSSEQUENCE_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        // 前缀和
        // 二分法
        prefix.emplace_back(1);
        int index = 0;
        int num = 2;
        while (num <= target) {
            prefix.emplace_back(num + prefix[index]);
            index++;
            num++;
        }
        int lastStart = 0;
        for (int i = 0; i < prefix.size(); i++) {
            // 不能只包含一个
            int left = i + 1;
            int right = prefix.size() - 1;
            unsigned int a = (i != 0) ? prefix[i - 1] : 0;
            while (left < right) {
                int mid = (left + right) >> 1;
                int temp = prefix[mid] - a;
                if (temp > target) {
                    right = mid - 1;
                } else if (temp < target) {
                    left = mid + 1;
                } else {
                    fill(i + 1, mid + 1);
                    lastStart = i + 1;
                    break;
                }
            }
            if(left >= prefix.size()){
                continue;
            }
            int temp = prefix[left] - a;
            if (temp == target) {
                if (i + 1 != lastStart) {
                    fill(i + 1, left + 1);
                }
            }
        }
        return ret;
    }

private:
    vector<vector<int>> ret;
    vector<unsigned int> prefix;

    void fill(int start, int end) {
        vector<int> temp;
        for (int i = start; i <= end; i++) {
            temp.emplace_back(i);
        }
        ret.emplace_back(temp);
    }
};

#endif //INC_57_FINDCONTINUOUSSEQUENCE_SOLUTION_H
