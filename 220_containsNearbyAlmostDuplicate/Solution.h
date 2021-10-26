//
// Created by timeC on 2021/4/17.
//

#ifndef INC_220_CONTAINSNEARBYALMOSTDUPLICATE_SOLUTION_H
#define INC_220_CONTAINSNEARBYALMOSTDUPLICATE_SOLUTION_H

#include <queue>
#include <set>
#include <unordered_set>

using namespace std;

typedef struct {
    bool operator()(const int &a, const int &b) {
        return a > b;
    }
} cmp;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        multiset<int, cmp> l;
        // 取更大的值的更小区间
        multiset<int> great;
        unordered_set<int> toDel;
        l.insert(1);
        l.insert(3);
        l.insert(3);
        l.insert(2);
        cout << *l.begin() << endl;
        l.erase(3);
        cout << *l.begin() << endl;
        l.erase(3);
        cout << *l.begin() << endl;
        return false;
    }
};


#endif //INC_220_CONTAINSNEARBYALMOSTDUPLICATE_SOLUTION_H
