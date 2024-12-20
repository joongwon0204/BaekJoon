// https://www.acmicpc.net/problem/1504
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int dijkstra(int s, int e, int n, vector<vector<int>>& graph) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n + 1, 100000000);

    distance[s] = 0;
    pq.push({0, s});
    int next_dist;

    while (!pq.empty()) {
        auto [dist, cur] = pq.top();
        pq.pop();

        if (cur == e) {
            return dist;
        }

        if (dist > distance[cur]) continue;

        for (int i = 1; i <= n; i++) {
            next_dist = graph[cur][i];
            if (!next_dist) continue;

            if (distance[i] > dist + next_dist) {
                distance[i] = dist + next_dist;
                pq.push({distance[i], i});
            }
        }
    }

    return 100000000;
}


int main() {
    init();

    int n, e, u, v, d, v1, v2;
    cin >> n >> e;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < e; i++) {
        cin >> u >> v >> d;
        graph[u][v] = d;
        graph[v][u] = d;
    }

    cin >> v1 >> v2;

    int stov1, stov2, v1tov2, v1toe, v2toe, ans;

    stov1 = dijkstra(1, v1, n, graph);
    stov2 = dijkstra(1, v2, n, graph);
    v1tov2 = dijkstra(v1, v2, n, graph);
    v1toe = dijkstra(v1, n, n, graph);
    v2toe = dijkstra(v2, n, n, graph);

    ans = min(stov1 + v2toe, stov2 + v1toe) + v1tov2;

    if (ans >= 100000000) {
        cout << -1;
    } else {
        cout << ans;
    }
}