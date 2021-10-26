//
// Created by timeC on 2021/3/13.
//

#ifndef INC_225_MYSTACK_MYSTACK_H
#define INC_225_MYSTACK_MYSTACK_H

#include <queue>
using namespace std;
class MyStack {
private:
    queue<int> main;
    queue<int> second;
    queue<int> *temp;
    queue<int> *now;
public:
    /** Initialize your data structure here. */
    MyStack() {
        this->now = &this->main;
        this->temp = &this->second;
    }

    /** Push element x onto stack. */
    void push(int x) {
        this->now->push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (this->now->size()!=1){
            this->temp->push(this->now->front());
            this->now->pop();
        }
        int result = this->now->front();
        this->now->pop();
        // 交换指针
        queue<int> *ex = this->now;
        this->now = this->temp;
        this->temp = ex;
        return result;
    }

    /** Get the top element. */
    int top() {
        while (this->now->size()!=1){
            this->temp->push(this->now->front());
            this->now->pop();
        }
        int result = this->now->front();
        this->temp->push(result);
        this->now->pop();
        // 交换指针
        queue<int> *ex = this->now;
        this->now = this->temp;
        this->temp = ex;
        return result;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return this->now->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


#endif //INC_225_MYSTACK_MYSTACK_H
