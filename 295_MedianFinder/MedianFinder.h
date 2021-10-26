//
// Created by timeC on 2021/8/27.
//

#ifndef INC_295_MEDIANFINDER_MEDIANFINDER_H
#define INC_295_MEDIANFINDER_MEDIANFINDER_H

#include <bits/stdc++.h>

using namespace std;


class MedianFinder {
public:
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> g;
    int size = 0;

    /** initialize your data structure here. */
    MedianFinder() {
        // 应该使用一个最小堆和一个最大堆
    }

    void addNum(int num) {
        size++;
        if (l.empty()) {
            g.push(num);
        } else if (g.empty() || num <= l.top()) {
            l.push(num);
        } else {
            g.push(num);
        }
        int a = l.size() - g.size();
        if (a > 1 || a < -1) {
            for (int i = 0; i < a; i += 2) {
                g.push(l.top());
                l.pop();
            }
            for (int i = 0; i < -a; i += 2) {
                l.push(g.top());
                g.pop();
            }
        }
    }

    double findMedian() {
        if (size % 2 == 0) {
            if (size == 0) {
                return 0;
            }
            return (double) (l.top() + g.top()) / (double) 2;
        } else {
            if (l.size() > g.size()) {
                return l.top();
            } else {
                return g.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


#endif //INC_295_MEDIANFINDER_MEDIANFINDER_H
