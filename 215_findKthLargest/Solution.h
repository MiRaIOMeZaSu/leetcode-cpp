//
// Created by timeC on 2021/4/7.
//

#ifndef INC_215_FINDKTHLARGEST_SOLUTION_H
#define INC_215_FINDKTHLARGEST_SOLUTION_H

#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> items;
    int n;

    static bool compare(int a, int b) {
        return a > b; //升序排列，如果改为return a>b，则为降序
    }

    static bool compare_(int a, int b) {
        return a < b; //升序排列，如果改为return a>b，则为降序
    }

    int findKthLargest(vector<int> &nums, int k) {
        items = nums;
        int mid = nums.size() / 2;
        if(k<mid){
            n = k;
            vector<int> ret = solve(0, nums.size() - 1);
            return ret[n - 1];
        }else{
            n = nums.size() - k + 1;
            vector<int> ret = solve_(0, nums.size() - 1);
            return ret[n - 1];
        }
    }

    vector<int> solve_(int left, int right) {
        int size = right - left + 1;
        if (size <= n) {
            // 进行排序
            sort(items.begin() + left, items.begin() + right + 1, compare_);
            vector<int> ret(items.begin() + left, items.begin() + right + 1);
            return ret;
        } else {
            // 继续分治
            int mid = left + (right - left) / 2;
            vector<int> l = solve_(left, mid);
            vector<int> r = solve_(mid + 1, right);
            vector<int> ret;
            int indexL = 0;
            int indexR = 0;
            int index = 0;
            while (index < n && indexL < l.size() && indexR < r.size()) {
                if (l[indexL] > r[indexR]) {
                    ret.push_back(r[indexR]);
                    index++;
                    indexR++;
                } else {
                    ret.push_back(l[indexL]);
                    index++;
                    indexL++;
                }
            }
            if (index < n) {
                if (indexL < l.size()) {
                    while (index < n) {
                        ret.push_back(l[indexL]);
                        index++;
                        indexL++;
                    }
                } else {
                    while (index < n) {
                        ret.push_back(r[indexR]);
                        index++;
                        indexR++;
                    }
                }
            }
            return ret;
        }
    }

    vector<int> solve(int left, int right) {
        int size = right - left + 1;
        if (size <= n) {
            // 进行排序
            sort(items.begin() + left, items.begin() + right + 1, compare);
            vector<int> ret(items.begin() + left, items.begin() + right + 1);
            return ret;
        } else {
            // 继续分治
            int mid = left + (right - left) / 2;
            vector<int> l = solve(left, mid);
            vector<int> r = solve(mid + 1, right);
            vector<int> ret;
            int indexL = 0;
            int indexR = 0;
            int index = 0;
            while (index < n && indexL < l.size() && indexR < r.size()) {
                if (l[indexL] < r[indexR]) {
                    ret.push_back(r[indexR]);
                    index++;
                    indexR++;
                } else {
                    ret.push_back(l[indexL]);
                    index++;
                    indexL++;
                }
            }
            if (index < n) {
                if (indexL < l.size()) {
                    while (index < n) {
                        ret.push_back(l[indexL]);
                        index++;
                        indexL++;
                    }
                } else {
                    while (index < n) {
                        ret.push_back(r[indexR]);
                        index++;
                        indexR++;
                    }
                }
            }
            return ret;
        }
    }
};


#endif //INC_215_FINDKTHLARGEST_SOLUTION_H
