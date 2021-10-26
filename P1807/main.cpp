#include <iostream>
#include <string.h>
#include <set>
#include <queue>

using namespace std;

set<int> graph[1501];
int weight[1501][1501];
int V, E;
int vl[1501];

int getMax(int a) {
    int maxV = -1;
    int temp;
    if (graph[a].empty()) {
        return 0;
    }
    for (set<int>::iterator it = graph[a].begin(); it != graph[a].end();) {
        temp = weight[*it][a] + vl[*it];
        maxV = maxV < temp ? temp : maxV;
        it++;
    }
    return maxV;
}

int main() {
    // 对于求关键路径,使用邻接表
    cin >> V >> E;
    short in[V + 1];
    memset(in, 0, sizeof(short) * (V + 1));
    int a, b, w;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> w;
        if (!graph[b].count(a)) {
            graph[b].insert(a);
            in[b]++;
            weight[a][b] = w;
        }
        weight[a][b] = weight[a][b] < w ? w : weight[a][b];
    }
    vl[V] = -1;
    if (in[V] == 0) {
        cout << vl[V] << endl;
        return 0;
    }
    queue<short> zeroIn;
    for (int i = 2; i <= V; i++) {
        if (in[i] == 0) {
            zeroIn.push(i);
        }
    }
    while (!zeroIn.empty()) {
        short pivot = zeroIn.front();
        zeroIn.pop();
        for (int i = 2; i <= V; i++) {
            if (graph[i].count(pivot)) {
                in[i]--;
                graph[i].erase(pivot);
                if (in[i] == 0 && i != 1) {
                    zeroIn.push(i);
                }
            }
        }
    }
    // 因为其他的入度为零的点阻碍了1前进,应该不断删除除1以外的其他入度为零的点

    // 进行拓扑排序
    zeroIn.push(1);
    while (!zeroIn.empty()) {
        short pivot = zeroIn.front();
        zeroIn.pop();
        vl[pivot] = getMax(pivot);
        if (pivot == V) {
            break;
        }
        for (int i = 1; i <= V; i++) {
            if (graph[i].count(pivot)) {
                in[i]--;
                if (in[i] == 0) {
                    zeroIn.push(i);
                }
            }
        }
    }
    cout << vl[V] << endl;
    return 0;
}
