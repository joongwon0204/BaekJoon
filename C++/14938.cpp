// https://www.acmicpc.net/problem/14938
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int dijkstra(int s, int n, int m, vector<vector<pair<int, int>>>& graph, vector<int>& item) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n + 1, 100000000);

    pq.push({0, s});
    distance[s] = 0;

    int next_dist, ret = 0;
    while (!pq.empty()) {
        auto [cur_dist, cur] = pq.top();
        pq.pop();

        if (distance[cur] < cur_dist) continue;
        if (distance[cur] <= m) {
            ret += item[cur];
        } else { break; }

        for (auto& [next, weight]: graph[cur]) {
            next_dist = cur_dist + weight;

            if (distance[next] > next_dist) {
                distance[next] = next_dist;
                pq.push({next_dist, next});
            }
        }
    }

    return ret;
}

int main() {
    init();

    int n, m, r, temp;
    cin >> n >> m >> r;

    vector<int> item(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        item[i] = temp;
    }

    vector<vector<pair<int, int>>> graph(n + 1);
    
    int a, b, l;
    for (int i = 0; i < r; i++) {
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
        graph[b].push_back({a, l});
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dijkstra(i, n, m, graph, item));
    }

    cout << ans;
}