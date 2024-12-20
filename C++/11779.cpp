// https://www.acmicpc.net/problem/11779
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int dijkstra(int s, int e, int n, vector<vector<pair<int, int>>>& graph, vector<int>& parent) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n + 1, 100000001);
    

    distance[s] = 0;
    pq.push({0, s});

    int next_dist;

    while (!pq.empty()) {
        auto [cur_dist, cur] = pq.top();
        pq.pop();

        if (cur_dist > distance[cur]) continue;

        if (cur == e) {
            return cur_dist;
        }

        for (auto& [next, weight]: graph[cur]) {
            next_dist = cur_dist + weight;
            if (distance[next] > next_dist) {
                distance[next] = next_dist;
                parent[next] = cur;
                pq.push({next_dist, next});
            }
        }
    }

    return -1;
}

int main() {
    init();

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> parent(n + 1);

    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int s, e;
    cin >> s >> e;

    int cost = dijkstra(s, e, n, graph, parent);
    cout << cost << '\n';

    int cur = e;
    vector<int> path;
    while (cur != s) {
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(s);

    cout << path.size() << '\n';
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << ' ';
    }

}