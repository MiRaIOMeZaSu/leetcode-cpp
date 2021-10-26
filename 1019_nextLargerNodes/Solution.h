//
// Created by timeC on 2021/4/21.
//

#ifndef INC_1019_NEXTLARGERNODES_SOLUTION_H
#define INC_1019_NEXTLARGERNODES_SOLUTION_H

#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head) {
        queue<pair<int,int>> q;


    }
};

#endif //INC_1019_NEXTLARGERNODES_SOLUTION_H
