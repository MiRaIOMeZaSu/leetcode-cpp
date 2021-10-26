//
// Created by timeC on 2021/4/14.
//

#ifndef INC_718_FINDLENGTH_SOLUTION_H
#define INC_718_FINDLENGTH_SOLUTION_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // 排序过后使用双指针
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

    }
};


#endif //INC_718_FINDLENGTH_SOLUTION_H
