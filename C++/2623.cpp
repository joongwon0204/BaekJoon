// https://www.acmicpc.net/problem/2623
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
        int s, u, v;
        cin >> s >> u;
        for (int j = 1; j < s; j++) {
            cin >> v;
            G[u].push_back(v);
            u = v;
        }
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

    vector<int> order(N+1), result(N);

    for (int i = 0; i < N; i++) {
        int u = tpl.top(); tpl.pop();
        order[u] = i;
        result[i] = u;
    }

    bool flag = true;
    for (int c : result) {
        if (!flag) break;
        int co = order[c];
        for (int n : G[c]) {
            int no = order[n];
            if (co > no) { flag = false; break; }
        }
    }

    if (flag) {
        for (int i = 0; i < N; i++) {
            cout << result[i] << (i==N - 1 ? "" : "\n");
        }
    } else cout << 0;
}