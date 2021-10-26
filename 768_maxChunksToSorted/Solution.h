//
// Created by timeC on 2021/5/12.
//

#ifndef INC_768_MAXCHUNKSTOSORTED_SOLUTION_H
#define INC_768_MAXCHUNKSTOSORTED_SOLUTION_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int> &arr) {
        // 提前记录某大小区间内应该有的数字数量
        // 最多能分的块
        // 大小相同的元素必然在同一区间内
        // 使用集合同时记录最大值和最小值
        int orderMax[arr.size()];
        int reverseMin[arr.size()];
        orderMax[0] = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            orderMax[i] = max(orderMax[i - 1], arr[i]);
        }
        reverseMin[arr.size() - 1] = arr[arr.size() - 1];
        for (int i = arr.size() - 2; i >= 0; i--) {
            reverseMin[i] = min(reverseMin[i + 1], arr[i]);
        }
        int ret = 1;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (orderMax[i] <= reverseMin[i + 1]) {
                ret += 1;
            }
        }
        return ret;
    }
};

#endif //INC_768_MAXCHUNKSTOSORTED_SOLUTION_H
