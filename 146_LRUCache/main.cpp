#include <iostream>

#include "LRUCache.h"

using namespace std;

int main() {
    int capacity = 2;
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(2, 1); // 缓存是 {1=1}
    lRUCache->put(1, 1); // 缓存是 {1=1, 2=2}
    lRUCache->put(2, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lRUCache->put(4, 1); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache->get(1) << endl;    // 返回 1
    cout << lRUCache->get(2) << endl;    // 返回 -1 (未找到)
//
//    cout << lRUCache->get(1) << endl;    // 返回 -1 (未找到)
//    cout << lRUCache->get(3) << endl;    // 返回 3
//    cout << lRUCache->get(4) << endl;    // 返回 4

//    LRUCache* obj = new LRUCache(capacity);
//    int param_1 = obj->get(2);
//    obj->put(1,1);
    return 0;
}
