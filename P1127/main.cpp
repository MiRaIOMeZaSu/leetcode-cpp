#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    int V;
    cin >> V;
    vector<string> list;
    map<char, vector<string>> head;
    map<char, vector<string>> tail;
    map<string ,vector<string>> in;
    set<string> notVisit;
    for (int i = 0; i < V; i++) {
        string temp;
        cin >> temp;
        head[temp[0]].push_back(temp);
        tail[temp[temp.length() - 1]].push_back(temp);
        list.push_back(temp);
        notVisit.insert(temp);
    }
    // 直接寻找所有的路径?
    string ret = "";
    string end = "";
    for (int i = 0; i < V; i++) {
        if (!tail.count(list[i][0]) || (tail[list[i][0]].size() == 1 && list[i][0] == list[i][list[i].size() - 1])) {
            end = list[i];
            ret += end;
            notVisit.erase(list[i]);
            break;
        }
    }
    if (ret.length() != 0) {

    }
    return 0;
}
