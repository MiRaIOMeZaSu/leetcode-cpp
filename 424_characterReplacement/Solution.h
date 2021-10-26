//
// Created by timeC on 2021/4/22.
//

#ifndef INC_424_CHARACTERREPLACEMENT_SOLUTION_H
#define INC_424_CHARACTERREPLACEMENT_SOLUTION_H

#include <vector>
#include <algorithm>

using namespace std;

struct alp {
    int key;
    int count;

    alp(int x) : key(x), count(0) {};

    alp() : key(0), count(0) {};

    bool operator<(alp o) const {
        return count > o.count;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        // 动态规划,存储还能够改变的次数和计数的单词
        // 对26个字母都来一次?
        // 滑动窗口?
        // 先统计字母出现次数
        if (k == s.size()) {
            return s.size();
        }
        int ret = 0;
        struct alp apls[26];
        for (int i = 0; i < 26; i++) {
            apls[i].key = i;
        }
        for (int i = 0; i < s.size(); i++) {
            int key = s[i] - 'A';
            apls[key].count++;
        }
        sort(apls, apls + 26);
        if (apls[0].count + k >= s.size()) {
            return s.size();
        }
        for (int i = 0; i < 26; i++) {
            if (apls[i].count + k <= ret) {
                break;
            }
            // 正式开始滑动
            int left = 0;
            int right = 0;
            int rest = k;
            while (right < s.size()) {
                if (s[right] - 'A' != apls[i].key) {
                    ret = max(ret, right - left);
                    if (rest > 0) {
                        rest--;
                    } else {
                        while (left <= right) {
                            if (s[left] - 'A' == apls[i].key) {
                                left++;
                            } else {
                                left++;
                                break;
                            }
                        }
                    }
                }
                right++;
            }
            ret = max(ret, right - left);
        }
        return ret;
    }
};


#endif //INC_424_CHARACTERREPLACEMENT_SOLUTION_H
