// https://www.acmicpc.net/problem/11725
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

void bfs(int n, vector<int>& visited, vector<int>& root, const vector<vector<int>>& connected_vertex) {
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    int cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        
        for (auto& vertex: connected_vertex[cur]) {
            if (visited[vertex]) { continue; }
            q.push(vertex);
            root[vertex] = cur;
            visited[vertex] = cur;
        }
        
    }
}

int main() {
    init();

    int n;
    cin >> n;

    vector<int> visited(n + 1, 0), root(n + 1, 0);
    vector<vector<int>> connected_vertex(n + 1, vector<int>());

    int t1, t2;
    for (int i = 0; i < n - 1; i++) {
        cin >> t1 >> t2;
        connected_vertex[t1].push_back(t2);
        connected_vertex[t2].push_back(t1);
    }

    bfs(n, visited, root, connected_vertex);

    for (int i = 2; i <= n; i++) {
        cout << root[i] << '\n';
    }
}

