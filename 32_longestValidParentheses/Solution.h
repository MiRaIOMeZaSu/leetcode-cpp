//
// Created by timeC on 2021/4/13.
//

#ifndef INC_32_LONGESTVALIDPARENTHESES_SOLUTION_H
#define INC_32_LONGESTVALIDPARENTHESES_SOLUTION_H

using namespace std;

class Solution {
public:
    string str;
    int ret = 0;
    int left = 0;
    int right = 0;
    int leftC = 0;
    int rightC = 0;
    int pivot;

    int longestValidParentheses(string s) {
        str = s;
        pivot = s.size();
        solve_l();
        pivot = left;
        right--;
        left = right;
        leftC = 0;
        rightC = 0;
        solve_r();
        return ret;
    }

    void solve_l() {
        while (right < pivot) {
            if (str[right] == '(') {
                leftC++;
            } else {
                rightC++;
            }
            while (leftC < rightC) {
                if (str[left] == '(') {
                    leftC--;
                    left++;
                } else {
                    rightC--;
                    left++;
                }
            }
            if (leftC == rightC) {
                ret = max(right - left + 1, ret);
            }
            right++;
        }
    }

    void solve_r() {
        while (left > pivot) {
            if (str[left] == '(') {
                leftC++;
            } else {
                rightC++;
            }
            while (leftC > rightC) {
                if (str[right] == '(') {
                    leftC--;
                } else {
                    rightC--;
                }
                right--;
            }
            if (leftC == rightC) {
                ret = max(right - left + 1, ret);
            }
            left--;
        }
    }
};

#endif //INC_32_LONGESTVALIDPARENTHESES_SOLUTION_H
