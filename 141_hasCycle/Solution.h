//
// Created by timeC on 2021/3/4.
//

#ifndef INC_141_HASCYCLE_SOLUTION_H
#define INC_141_HASCYCLE_SOLUTION_H

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

struct ListNode {
    // 此为链表结点
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 快慢指针
        if (head == NULL) {
            return false;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        // 相遇时结束
        while (fast->next != NULL) {
            if (fast->next->next != NULL) {
                // 如果没有环,则直接走出循环
                fast = fast->next->next;
                slow = slow->next;
                if (fast == slow) {
                    return true;
                }
            }else{
                return false;
            }
        }
        return false;
    }
};


#endif //INC_141_HASCYCLE_SOLUTION_H
