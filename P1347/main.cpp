#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    // 使用拓扑排序
    set<int> in[26];
    set<int> list;
    set<int> out[26];
    queue<int> zeroIn;
    int inCount[26];
    vector<int> q;
    for (int i = 0; i < E; i++) {
        char temp, a, b;
        list.insert(a - 'A');
        list.insert(b - 'A');
        cin >> a >> temp >> b;
        in[a - 'A'].insert(b - 'A');
        out[b - 'A'].insert(a - 'A');
    }
    for (set<int>::iterator it = list.begin(); it != list.end(); ++it) {
        if (in[*it].empty()) {
            zeroIn.push(*it);
        }
    }
    if (zeroIn.size() > 1) {
        cout << "Sorted sequence cannot be determined." << endl;
        return 0;
    }
    while (!zeroIn.empty()) {
        int pivot = zeroIn.front();
        zeroIn.pop();
        q.push_back(pivot);
        for (set<int>::iterator it = out[pivot].begin(); it != out[pivot].end(); ++it) {
            in[*it].erase(pivot);
            if (in[*it].empty()) {
                zeroIn.push(*it);
                if (zeroIn.size() > 1) {
                    cout << "Sorted sequence cannot be determined." << endl;
                    return 0;
                }
            }
        }
    }
    if (q.size() < V) {
        cout << "Inconsistency found after x relations." << endl;
        return 0;
    }

    return 0;
}
