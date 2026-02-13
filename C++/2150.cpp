// https://www.acmicpc.net/problem/2150
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> G(v+1),GT(v+1);
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        GT[b].push_back(a);
    }


    vector<char> visited(v+1, 0);
    vector<int> ids(v+1,0);
    vector<pair<int,int>> finish(v+1); // finish time, index
    int time = 0;
    int id = 0;

    function<void(int, vector<vector<int>>&)> dfs = [&](int u, vector<vector<int>>& graph){
        time++;
        visited[u] = 1;
        for (int v : graph[u]) if (!visited[v]) {
            dfs(v, graph);
        }
        time++;
        finish[u] = {time, u};
    };

    function<void(int, vector<vector<int>>&)> dfs2 = [&](int u, vector<vector<int>>& graph){
        visited[u] = 1;
        ids[u] = id;
        for (int v : graph[u]) if (!visited[v]) {
            dfs2(v, graph);
        }
    };

    for (int i = 1; i <= v; i++) if (!visited[i]) {
        dfs(i,G);
    }

    sort(finish.begin()+1, finish.end(), greater<pair<int,int>>());
    
    visited = vector<char>(v+1,0);
    for (int i = 1; i <= v; i++) if (!visited[finish[i].second]) {
        dfs2(finish[i].second,GT);
        id++;
    }
    
    cout << id << '\n';

    vector<vector<int>> ans(id);
    for (int i = 1; i <= v; i++) {
        ans[ids[i]].push_back(i);
    }

    for (int i = 0; i < id; i++) {
        sort(ans[i].begin(), ans[i].end());
    }

    sort(ans.begin(), ans.end(), [](const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    });

    for (int i = 0; i < id; i++) {
        for (int x : ans[i]) cout << x << ' ';
        cout << -1 << (i == id-1 ? "" : "\n");
    }
}
