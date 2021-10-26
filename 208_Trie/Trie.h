//
// Created by timeC on 2021/4/14.
//

#ifndef INC_208_TRIE_TRIE_H
#define INC_208_TRIE_TRIE_H

#include <vector>
#include <unordered_map>

using namespace std;

struct _TreeNode {
    char val = ' ';
    unordered_map<char, _TreeNode *> *next;
    bool isEnd;

    _TreeNode() : val(' '), isEnd(false), next(new unordered_map<char, _TreeNode *>) {}

    _TreeNode(char x) : val(x), isEnd(false), next(new unordered_map<char, _TreeNode *>) {}
};

class Trie {
public:
    /** Initialize your data structure here. */
    _TreeNode *root;

    Trie() {
        // 初始化一颗树
        root = new _TreeNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        // 先查找再插入
        _TreeNode *curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->next->count(word[i])) {
                curr->next->insert(make_pair(word[i], new _TreeNode(word[i])));
            }
            curr = curr->next->at(word[i]);
        }
        curr->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        // 查找
        _TreeNode *curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->next->count(word[i])) {
                return false;
            }
            curr = curr->next->at(word[i]);
        }
        return curr->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        // 查找匹配
        _TreeNode *curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!curr->next->count(prefix[i])) {
                return false;
            }
            curr = curr->next->at(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

#endif //INC_208_TRIE_TRIE_H
