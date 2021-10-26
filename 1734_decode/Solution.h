//
// Created by timeC on 2021/5/11.
//

#ifndef INC_1734_DECODE_SOLUTION_H
#define INC_1734_DECODE_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int> &encoded) {
        int n = encoded.size() + 1;
        vector<int> ret(n);
        int total = 0;
        for (int i = 1; i <= n; i++) {
            total ^= i;
        }
        int otherTotal = 0;
        for (int i = 0; i < n - 1; i += 2) {
            otherTotal ^= encoded[i];
        }
        ret[n - 1] = total ^ otherTotal;
        for (int i = n - 2; i >= 0; i--) {
            ret[i] = ret[i + 1] ^ encoded[i];
        }
        return ret;
    }
};

#endif //INC_1734_DECODE_SOLUTION_H
