//
// Created by timeC on 2021/4/13.
//

#ifndef INC_86_PARTITION_SOLUTION_H
#define INC_86_PARTITION_SOLUTION_H

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
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *curr = head;
        ListNode *pivot = nullptr;
        ListNode *prePivot = nullptr;
        while (curr != nullptr) {
            if (curr->val >= x) {
                pivot = curr;
                break;
            }else{
                prePivot = curr;
                curr = curr->next;
            }
        }
        if(pivot== nullptr){
            return head;
        }
        curr = pivot->next;
        ListNode *preCurr = pivot;
        while (curr != nullptr) {
            if(curr->val < x){
                preCurr->next = curr->next;
                if(prePivot!= nullptr){
                    prePivot->next = curr;
                }else{
                    head = curr;
                }
                curr->next = pivot;
                prePivot =curr;
                curr = preCurr->next;
            }else{
                preCurr = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};


#endif //INC_86_PARTITION_SOLUTION_H
