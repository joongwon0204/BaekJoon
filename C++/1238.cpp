// https://www.acmicpc.net/problem/1238
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

void dijkstra(int s, int n, vector<vector<pair<int, int>>>& graph, vector<int>& cache) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n + 1, 100000000);

    distance[s] = 0;
    pq.push({0, s});

    int next_dist;

    while (!pq.empty()) {
        auto [cur_dist, cur] = pq.top();
        pq.pop();

        if (cur_dist > distance[cur]) continue;

        cache[cur] += cur_dist;

        for (auto& [next, weight]: graph[cur]) {
            next_dist = cur_dist + weight;
            if (distance[next] > next_dist) {
                distance[next] = next_dist;
                pq.push({next_dist, next});
            }
        }
    }
}

int main() {
    init();

    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<pair<int, int>>> come(n + 1);
    vector<vector<pair<int, int>>> go(n + 1);

    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        come[u].push_back({v, w});
        go[v].push_back({u, w});
    }
    vector<int> cache(n + 1, 0);

    dijkstra(x, n, come, cache);
    dijkstra(x, n, go, cache);

    int ans = 0;
    for (auto& dist: cache) {
        ans = max(ans, dist);
    }

    cout << ans;
}