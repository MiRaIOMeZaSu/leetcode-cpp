//
// Created by timeC on 2021/6/4.
//

#ifndef INC_160_GETINTERSECTIONNODE_SOLUTION_H
#define INC_160_GETINTERSECTIONNODE_SOLUTION_H

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 先算出两条链表的长度即可
        int lenA = getLen(headA);
        int lenB = getLen(headB);
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; i++) {
                headA = headA->next;
            }
        } else {
            for (int i = 0; i < lenB - lenA; i++) {
                headB = headB->next;
            }
        }
        while (headA != nullptr) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }

    int getLen(ListNode *head) {
        ListNode *curr = head;
        int ret = 0;
        while (curr != nullptr) {
            ret++;
            curr = curr->next;
        }
        return ret;
    }
};


#endif //INC_160_GETINTERSECTIONNODE_SOLUTION_H
