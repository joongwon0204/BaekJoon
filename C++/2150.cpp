// https://www.acmicpc.net/problem/2150
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> G(v+1);
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    vector<char> visited(v+1, 0);

    function<void(int)> dfs = [&](int u){
        visited[u] = 1;
        for (int v : G[u]) if (!visited[v]) dfs(v);
    };

    for (int i = 1; i <= n; i++) if (!visited[i]) dfs(i);


    //


    vector<char> visited(n+1, 0);
    stack<int> st;
    st.push(1);
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (int v : G[u]) {
            if (!visited[v]) st.push(v);
        }
    }

}
