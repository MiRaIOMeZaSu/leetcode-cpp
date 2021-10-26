//
// Created by timeC on 2021/5/3.
//

#ifndef INC_820_MINIMUMLENGTHENCODING_SOLUTION_H
#define INC_820_MINIMUMLENGTHENCODING_SOLUTION_H

#include <vector>

using namespace std;

struct _TreeNode {
    char ch;
    bool isEnd;
    vector<_TreeNode *> next{26};

    _TreeNode() : isEnd(false) {};

    _TreeNode(char char1) : ch(char1), isEnd(false) {};
};

class Solution {
private:
    int ret = 0;
    int totalCount = 0;
public:
    int minimumLengthEncoding(vector<string> &words) {
        // 字典树?
        // 以尾为头
        struct _TreeNode *root = new _TreeNode();
        for (int i = 0; i < words.size(); i++) {
            struct _TreeNode *curr = root;
            for (int j = words[i].length() - 1; j >= 0; j--) {
                if (curr->next[words[i][j] - 'a'] == nullptr) {
                    curr->next[words[i][j] - 'a'] = new _TreeNode(words[i][j]);
                }
                curr = curr->next[words[i][j] - 'a'];
            }
            curr->isEnd = true;
        }
        // 开始遍历
        solve(root, 0);
        return ret + totalCount;
    }

    void solve(_TreeNode *root, int level) {
        int subCount = 0;
        for (int i = 0; i < 26; i++) {
            if (root->next[i] != nullptr) {
                solve(root->next[i], level + 1);
                subCount++;
            }
        }
        if (subCount == 0 && root->isEnd) {
            ret += level;
            totalCount++;
        }
    }
};

#endif //INC_820_MINIMUMLENGTHENCODING_SOLUTION_H
