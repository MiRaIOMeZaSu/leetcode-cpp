//
// Created by timeC on 2021/5/12.
//

#ifndef INC_1334_FINDTHECITY_SOLUTION_H
#define INC_1334_FINDTHECITY_SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
        // 路径遍历
        // 有向图
        // 先建立领接表
        vector<vector<vector<int>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].emplace_back(edges[i]);
            vector<int> temp{edges[i][1],edges[i][0],edges[i][2]};
            graph[edges[i][1]].emplace_back(temp);
        }
        int minId = 0;
        int minCityCount = INT_MAX;
        for (int i = 0; i < n; i++) {
            // 以编号为i的点为起点开始遍历
            // 存在回环的情况如何?
            queue<pair<int, int>> nextCities;
            nextCities.push(make_pair(i, 0));
            unordered_map<int, int> visited;
            while (!nextCities.empty()) {
                pair<int, int> pivot = nextCities.front();
                nextCities.pop();
                int id = pivot.first;
                int val = pivot.second;
                visited.insert(pivot);
                for (int j = 0; j < graph[id].size(); j++) {
                    int distance = graph[id][j][2] + val;
                    int toId = graph[id][j][1];
                    if (distance <= distanceThreshold) {
                        pair<int, int> city = make_pair(toId, distance);
                        if (!visited.count(toId)) {
                            visited.insert(city);
                            nextCities.push(city);
                        } else if (visited.count(toId) && visited[toId] > distance) {
                            visited[toId] = distance;
                            nextCities.push(city);
                        }
                    }
                }
            }
            if (visited.size() - 1 <= minCityCount) {
                minCityCount = visited.size() - 1;
                minId = i;
            }
        }
        return minId;
    }
};


#endif //INC_1334_FINDTHECITY_SOLUTION_H
