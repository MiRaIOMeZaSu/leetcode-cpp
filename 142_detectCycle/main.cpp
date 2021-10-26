#include <iostream>
#include "Solution.h"

using namespace std;

int main() {
    ListNode *one = new ListNode(3);
    ListNode *two = new ListNode(2);
//    ListNode *three = new ListNode(0);
//    ListNode *four = new ListNode(-4);
    one->next = two;
//    two->next = three;
//    three->next = four;
//    four->next = two;
    Solution solution;
    ListNode *result = solution.detectCycle(one);
    if (result == NULL) {
        cout << "with no loop" << endl;
    } else {
        cout << result->val << endl;
    }

    return 0;
}
