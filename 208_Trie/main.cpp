#include <iostream>
#include "Trie.h"

using namespace std;

int main() {
    Trie *obj = new Trie();
    obj->insert("apple");
    bool param_2 = obj->search("apple");
    bool param_3 = obj->startsWith("app");
    cout << param_2 << " " << param_3 << endl;
    return 0;
}
