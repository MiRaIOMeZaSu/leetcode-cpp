//
// Created by timeC on 2021/5/20.
//

#ifndef INC_692_TOPKFREQUENT_SOLUTION_H
#define INC_692_TOPKFREQUENT_SOLUTION_H

#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        int maxCount = 0;
        unordered_map<string, int> dict;
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            if (!dict.count(word)) {
                dict.insert(make_pair(word, 0));
            }
            dict[word]++;
            maxCount = max(dict[word], maxCount);
        }
        vector<vector<string>> arr(maxCount + 1);
        for (auto it = dict.begin(); it != dict.end(); it++) {
            arr[it->second].emplace_back(it->first);
        }
        vector<string> ret;
        for (int i = arr.size() - 1; i > 0; i--) {
            if (arr[i].size() > 0) {
                sort(arr[i].begin(),arr[i].end());
                for (int j = 0; j < arr[i].size(); j++) {
                    ret.emplace_back(arr[i][j]);
                    if (ret.size() >= k) {
                        return ret;
                    }
                }
            }

        }
        return ret;
    }
};


#endif //INC_692_TOPKFREQUENT_SOLUTION_H
