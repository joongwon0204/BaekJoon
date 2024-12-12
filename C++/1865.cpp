// https://www.acmicpc.net/problem/1865
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int t;
    cin >> t;

    int n, m ,w;
    vector<int> min_times;
    vector<vector<int>> edges;
    int u, v, time;
    for (int ti = 0; ti < t; ti++) {
        cin >> n >> m >> w;

        min_times.assign(n, 100000000);
        min_times[0] = 0;

        for (int i = 0; i < m; i++) {
            cin >> u >> v >> time;
            edges.push_back({u - 1, v - 1, time});
            edges.push_back({v - 1, u - 1, time});
        }
        for (int i = 0; i < w; i++) {
            cin >> u >> v >> time;
            edges.push_back({u - 1, v - 1, -time});
        }


        for (int i = 0; i < m + w - 1; i++) {
            for (auto& edge: edges) {
                u = edge[0];
                v = edge[1];
                time = edge[2];

                if (min_times[u] != 100000000 && min_times[v] > min_times[u] + time) {
                    min_times[v] = min_times[u] + time;
                }
            }
        }

        string ans = "NO";
        for (auto& edge: edges) {
            u = edge[0];
            v = edge[1];
            time = edge[2];

            if (min_times[u] != 100000000 && min_times[v] > min_times[u] + time) {
                ans = "YES";
                break;
            }
        }
        cout << ans << '\n';
    }
}