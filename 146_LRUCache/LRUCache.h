//
// Created by timeC on 2021/3/10.
//

#ifndef INC_146_LRUCACHE_LRUCACHE_H
#define INC_146_LRUCACHE_LRUCACHE_H

#include <unordered_map>

using namespace std;

struct DuLNode {
    // 此为链表结点
    int key = 0;
    int val = 0;
    DuLNode *next;
    DuLNode *prev;

    void set_next(DuLNode *n) {
        next = n;
    }

    void set_prev(DuLNode *n) {
        prev = n;
    }
    // DuLNode(int x, int y) : key(x), val(y), next(NULL), prev(NULL) {}
    // DuLNode(int x, int y) {
    // this->key = x;
    // this->val = y;
    // }
};

class LRUCache {

private:
    unordered_map<int, DuLNode *> cache;
    DuLNode *head = new DuLNode();
    DuLNode *tail = new DuLNode();
    int capacity;
public:
    LRUCache(int capacity) {
        // 初始化构造函数
        // 通过哈希双链表实现
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.count(key)) {
            // 更新
            if (cache.size() > 0) {
                DuLNode *temp = cache[key]->prev;

                temp->set_next(cache[key]->next);
                cache[key]->next->set_prev(temp);
                // 插入尾部
                cache[key]->set_prev(tail->prev);
                tail->prev->set_next(cache[key]);

                tail->set_prev(cache[key]);
                cache[key]->set_next(tail);
            }
            return cache[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            cache[key]->val = value;
            DuLNode *temp = cache[key]->prev;

            temp->set_next(cache[key]->next);
            cache[key]->next->set_prev(temp);
            // 插入尾部
            cache[key]->set_prev(tail->prev);
            tail->prev->set_next(cache[key]);

            tail->set_prev(cache[key]);
            cache[key]->set_next(tail);
        } else {
            // DuLNode *n = new DuLNode(key, value);
            DuLNode *n = new DuLNode();
            n->key = key;
            n->val = value;
            if (cache.size() == capacity) {
                // 移除队首
                int toDel = head->next->key;
                DuLNode *temp = head->next->next;
                temp->set_prev(head);
                // delete head->next;
                head->set_next(temp);
//                cache[toDel].next =NULL;
//                cache[toDel].prev =NULL;
                cache.erase(toDel);
            }
            n->set_prev(tail->prev);
            tail->prev->set_next(n);

            tail->set_prev(n);
            n->set_next(tail);
            /*
            if (tail->prev->prev != NULL && tail->prev->prev != head) {
                tail->prev->prev->next = n;
                n->prev = tail->prev->prev;
                tail->prev = n;
                n->next = tail;
            } else if(tail->prev->prev == NULL){
                head->next = n;
                tail->prev = n;
                n->next = tail;
                n->prev = head;
            }
            else {
                n->prev = tail->prev;
                tail->prev->next = n;
                tail->prev = n;
                n->next = tail;
            }
             */
            cache.insert(make_pair(key, n));
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif // INC_146_LRUCACHE_LRUCACHE_H
