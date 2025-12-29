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

int main() {
    init();

    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N+1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }

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
        cout << u << (i == N ? "" : " ");
    }
}