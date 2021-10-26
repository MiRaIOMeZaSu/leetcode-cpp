#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<int> graph[], int start, unordered_set<int> &visited, vector<int> &queue) {
    if (visited.count(start)) {
        return;
    } else {
        visited.insert(start);
        queue.push_back(start);
    }
    for (int i = 0; i < graph[start].size(); i++) {
        DFS(graph, graph[start][i], visited, queue);
    }
}

void BFS(vector<int> graph[], int start, unordered_set<int> &visited, vector<int> &queue) {
    vector<int> level;
    vector<int> base;
    base.push_back(start);
    while (base.size() != 0) {
        for (int i = 0; i < base.size(); i++) {
            if(visited.count(base[i])){
                continue;
            }else{
                visited.insert(base[i]);
                queue.push_back(base[i]);
            }
            for (int j = 0; j < graph[base[i]].size(); j++) {
                level.push_back(graph[base[i]][j]);
            }
        }
        base = level;
        level.clear();
    }
}

int main() {
    int V, E;
    // 此图有size个点,
    cin >> V;
    cin >> E;
    vector<int> graph[V];
    int in, out;
    cin >> in;
    cin >> out;
    graph[in].push_back(out);
    int start = in;
    for (int i = 0; i < E - 1; i++) {
        cin >> in;
        cin >> out;
        graph[in].push_back(out);
    }
    for (int i = 0; i < V; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    // 深度优先
    unordered_set<int> visited;
    vector<int> queue;
    DFS(graph, start, visited, queue);
    for (int i = 0; i < queue.size(); i++) {
        cout << queue[i] << " ";
    }
    visited.clear();
    queue.clear();
    cout << endl;
    BFS(graph, start, visited, queue);
    for (int i = 0; i < queue.size(); i++) {
        cout << queue[i] << " ";
    }
    return 0;
}
