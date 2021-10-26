//
// Created by timeC on 2021/6/5.
//

#ifndef INC_203_REMOVEELEMENTS_SOLUTION_H
#define INC_203_REMOVEELEMENTS_SOLUTION_H


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        while (head != nullptr && head->val == val) {
            head = head->next;
        }
        if (head == nullptr) {
            return head;
        }
        ListNode *last = head;
        if(head->next== nullptr){
            return head;
        }
        ListNode *curr = head->next;
        while (curr != nullptr) {
            if (curr->val == val) {
                last->next = curr->next;
            } else {
                last = curr;
            }
            curr = last->next;
        }
        return head;
    }
};


#endif //INC_203_REMOVEELEMENTS_SOLUTION_H
