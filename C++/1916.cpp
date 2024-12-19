// https://www.acmicpc.net/problem/1916
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> buses(n + 1);
    vector<int> distance(n + 1, 100000001);
    int u, v, t;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> t;
        buses[u].push_back(make_pair(v, t));
    }

    int s, e;
    cin >> s >> e;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pair<int, int> cur;
    pq.push({0, s});
    distance[s] = 0;
    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();

        if (cur.first > distance[cur.second]) continue;

        for (auto& bus: buses[cur.second]) {
            if (distance[bus.first] > distance[cur.second] + bus.second) {
                distance[bus.first] = distance[cur.second] + bus.second;
                pq.push({distance[bus.first], bus.first});
            }
        }
    }

    cout << distance[e];
}