//
// Created by timeC on 2021/5/18.
//

#ifndef INC_1442_COUNTTRIPLETS_SOLUTION_H
#define INC_1442_COUNTTRIPLETS_SOLUTION_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int> &arr) {
        // 分成两段,两段的异或值相同
        vector<int> trie(arr.size());
        vector<unordered_map<int, int>> order(arr.size());
//        trie[0] = arr[0];
//        for (int i = 1; i < arr.size(); i++) {
//            trie[i] = trie[i - 1] ^ arr[i];
//        }
        order[0].insert(make_pair(arr[0], 1));
        int lastTemp = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            int temp = lastTemp ^arr[i];
            lastTemp = temp;
            if (!order[0].count(temp)) {
                order[0].insert(make_pair(temp, 0));
            }
            order[0][temp]++;
        }
        for (int i = 1; i < arr.size(); i++) {
            for (auto it = order[i - 1].begin(); it != order[i - 1].end(); it++) {
                int count = it->second;
                if (it->first == arr[i - 1]) {
                    count--;
                }
                if (count > 0) {
                    int temp = it->first ^arr[i - 1];
                    order[i].insert(make_pair(temp, count));

                }
            }
        }
        // 反转
        vector<unordered_map<int, int>> reverseOrder(arr.size());
        lastTemp = arr[arr.size() - 1];
        reverseOrder[arr.size() - 1].insert(make_pair(arr[arr.size() - 1], 1));
        for (int i = arr.size() - 2; i >= 0; i--) {
            int temp = lastTemp ^arr[i];
            lastTemp = temp;
            if (!reverseOrder[arr.size() - 1].count(temp)) {
                reverseOrder[arr.size() - 1].insert(make_pair(temp, 0));
            }
            reverseOrder[arr.size() - 1][temp]++;
        }
        for (int i = arr.size() - 2; i >= 0; i--) {
            for (auto it = reverseOrder[i + 1].begin(); it != reverseOrder[i + 1].end(); it++) {
                int count = it->second;
                if (it->first == arr[i + 1]) {
                    count--;
                }
                if(count!=0){
                    reverseOrder[i].insert(make_pair(it->first ^ arr[i + 1], count));
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            unordered_map<int, int> map1;
            unordered_map<int, int> map2;
            if (reverseOrder[i].size() > order[i + 1].size()) {
                map1 = reverseOrder[i];
                map2 = order[i + 1];
            } else {
                map1 = order[i + 1];
                map2 = reverseOrder[i];
            }
            for (auto it = map2.begin(); it != map2.end(); it++) {
                if (map1.count(it->first)) {
                    ret += it->second * map1[it->first];
                }
            }
        }
        return ret;
    }
};


#endif //INC_1442_COUNTTRIPLETS_SOLUTION_H
