#include <iostream>
#include "Solution.h"

int main() {
    Solution solution;
    ListNode *head = new ListNode(1);
    ListNode *_1 = new ListNode(4);
    ListNode *_2 = new ListNode(2);
    ListNode *_3 = new ListNode(3);
    ListNode *_4 = new ListNode(2);
    ListNode *_5 = new ListNode(3);
    ListNode *_6 = new ListNode(5);
    ListNode *_7 = new ListNode(2);
    head->next = _1;
    _1->next = _2;
    _2->next = _3;
    _3->next = _4;
    _4->next = _5;
    _5->next = _6;
    _6->next = _7;
    solution.partition(head,3);
    return 0;
}
