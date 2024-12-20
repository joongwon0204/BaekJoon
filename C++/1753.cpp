// https://www.acmicpc.net/problem/1753
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int INF = 12345678;

void dijkstra(int s, vector<vector<pair<int, int>>>& graph,  vector<int>& distance) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[s] = 0;
    pq.push({0, s});

    int next_dist;
    while (!pq.empty()) {
        auto [cur_dist, cur] = pq.top();
        pq.pop();

        if (cur_dist > distance[cur]) continue;

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

    int n, e, s;
    cin >> n >> e >> s;

    int u, v, w;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < e; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<int> distance(n + 1, INF);
    
    dijkstra(s, graph, distance);

    int d;
    for (int i = 1; i <= n; i++) {
        d = distance[i];
        if (d == INF) {
            cout << "INF\n";
        } else {
            cout << d << '\n';
        }
    }
}