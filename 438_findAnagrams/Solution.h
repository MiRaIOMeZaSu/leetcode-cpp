//
// Created by timeC on 2021/3/3.
//

#ifndef INC_438_FINDANAGRAMS_SOLUTION_H
#define INC_438_FINDANAGRAMS_SOLUTION_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> results;
        if (s.length() < p.length()) {
            return results;
        }
        vector<int> needs(26);
        vector<int> window(26);

        for (int i = 0; i < p.length(); i++) {
            // 统计单词出现频次
            ++needs[p[i] - 'a'];
            ++window[s[i] - 'a'];
        }
        if (needs == window) {
            results.push_back(0);
        }
        for (int i = 1; i <= s.length() - p.length(); i++) {
            // 所有窗口
            --window[s[i - 1] - 'a'];
            ++window[s[i + p.length() - 1] - 'a'];
            if (needs == window) {
                results.push_back(i);
            }
        }
        // 窗口长度固定
        return results;
    }
};


#endif //INC_438_FINDANAGRAMS_SOLUTION_H
