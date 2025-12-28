// https://www.acmicpc.net/problem/9466
#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<char> visited(n+1, 0);

    function<void(int)> dfs = [&](int u){
        visited[u] = 1;
        for (int v : G[u]) if (!visited[v]) dfs(v);
    };

    for (int i = 1; i <= n; i++) if (!visited[i]) dfs(i);


    //


    vector<char> visited(n+1, 0);
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (int v : G[u]) {
            if (!visited[v]) st.push(v);
        }
    }
}