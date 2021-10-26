#include <iostream>
#include "Solution.h"

int main() {
    Solution solution;
    // head = [3,2,0,-4], pos = 1
    /*
    ListNode *one = new ListNode(3);
    ListNode *two = new ListNode(2);
    ListNode *three = new ListNode(0);
    ListNode *four = new ListNode(-1);
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = two;
     */
    ListNode *one = new ListNode(1);
    ListNode *two = new ListNode(2);
    one->next = two;
    two->next = one;
    cout << solution.hasCycle(one);
    return 0;
}
