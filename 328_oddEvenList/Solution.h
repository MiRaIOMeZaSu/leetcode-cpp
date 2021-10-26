//
// Created by timeC on 2021/4/14.
//

#ifndef INC_328_ODDEVENLIST_SOLUTION_H
#define INC_328_ODDEVENLIST_SOLUTION_H

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        // 至少数量为4的指针
        // 只移动奇数结点即可
        if (head == nullptr) {
            return head;
        }
        ListNode *oddTail = head;
        ListNode *evenHead = head->next;
        ListNode *pre = head->next;
        ListNode *curr = head->next;
        if (curr != nullptr) {
            curr = curr->next;
        }
        while (curr != nullptr) {
            pre->next = curr->next;
            curr->next = evenHead;
            oddTail->next = curr;
            oddTail = curr;
            pre = pre->next;
            if (pre != nullptr) {
                curr = pre->next;
            }else{
                return head;
            }
        }
        return head;
    }
};


#endif //INC_328_ODDEVENLIST_SOLUTION_H
