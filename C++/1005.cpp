// https://www.acmicpc.net/problem/1005
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

const int MOD = 1000000000;

int main() {
    init();
    
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, K;
        cin >> N >> K;

        vector<int> times(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> times[i];
        }

        vector<vector<int>> G(N+1), GT(N+1);
        for (int i = 0; i < K; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            GT[v].push_back(u);
        }

        int W;
        cin >> W;


        vector<bool> visited(N+1, 0);
        stack<int> tpl;

        function<void(int)> dfs = [&](int u){
            visited[u] = 1;
            for (int v : G[u]) if (!visited[v]) dfs(v);
            tpl.push(u);
        };

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        for (int i = 1; i <= N; i++) {
            int tp = 0, u = tpl.top(); tpl.pop();
            for (int v : GT[u]) tp = max(tp, times[v]);
            times[u] += tp;
        }

        cout << times[W] << (t == T - 1 ? "" : "\n");
    }
}