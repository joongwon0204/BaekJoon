// https://www.acmicpc.net/problem/9466
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <functional>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;

        vector<vector<int>> G(n+1), GT(n+1);
        for (int i = 1; i <= n; i++) {
            int t;
            cin >> t;
            G[i].push_back(t);
            GT[t].push_back(i);
        }

        vector<int> order;
        vector<int> visited(n+1, 0);

        function<void(int)> dfs = [&](int u){
            visited[u] = 1;
            for (int v : G[u]) if (!visited[v]) dfs(v);
            order.push_back(u);
        };

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) dfs(i);
        }

        vector<int> visited2(n+1, -1);

        function<void(int, int)> dfs2 = [&](int u, int i){
            visited2[u] = i;
            for (int v : GT[u]) if (visited2[v] == -1) dfs2(v, i);
        };

        for (int i = n - 1; i >= 0; i--) {
            int j = order[i];
            if (visited2[j] == -1) dfs2(j, j);
        }

        int ans = 0;
        vector<int> counter(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int id = visited2[i];
            counter[id]++;
            if (counter[id] == 1) {
                if (G[i][0] != i) {
                    ans++;
                }
            } else if (counter[id] == 2) {
                ans--;
            }
        }

        cout << ans << (t == T - 1 ? "" : "\n");
    }
}