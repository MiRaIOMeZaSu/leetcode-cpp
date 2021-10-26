#include <iostream>

#include "MyStack.h"
int main() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.top(); // 返回 2
    myStack.pop(); // 返回 2
    myStack.empty(); // 返回 False

    return 0;
}
