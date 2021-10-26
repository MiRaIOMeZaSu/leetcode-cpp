//
// Created by timeC on 2021/3/4.
//

#ifndef INC_142_DETECTCYCLE_SOLUTION_H
#define INC_142_DETECTCYCLE_SOLUTION_H

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 寻找链表的环头
        // 快慢指针
        if (head == NULL) {
            return NULL;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != NULL) {
            if (fast->next->next != NULL) {
                fast = fast->next->next;
                slow = slow->next;
                if (slow == fast) {
                    // 此时使新的指针从head开始和slow同速度出发,相同时即是结果
                    fast = head;
                    while (slow != fast) {
                        slow = slow->next;
                        fast = fast->next;
                    }
                    return slow;
                }
            } else{
                return NULL;
            }
        }
        return NULL;
    }
};


#endif //INC_142_DETECTCYCLE_SOLUTION_H
