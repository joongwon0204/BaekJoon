// https://www.acmicpc.net/problem/15681
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;
using Graph = vector<vector<int>>;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int n, r, q;
    cin >> n >> r >> q;
    Graph G = Graph(n + 1, vector<int>());

    for (int _ = 0; _ < n - 1; _++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> sizes = vector<int>(n + 1, 0), parents = vector<int>(n + 1, 0);
    vector<bool> visited = vector<bool>(n + 1, false);
    vector<int> st;

    st.push_back(r);
    parents[r] = 0;
    visited[r] = true;
    while(!st.empty()) {
        int cur = st.back();
        bool flag = true;
        for (auto i : G[cur]) {
            if (!visited[i]) {
                st.push_back(i);
                visited[i] = true;
                parents[i] = cur;
                flag = false;
            }
        }
        if (flag) {
            st.pop_back();
            sizes[cur]++;
            sizes[parents[cur]] += sizes[cur];
        }
    }

    for (int _ = 0; _ < q; _++) {
        int subr;
        cin >> subr;
        cout << sizes[subr] << (_ == q - 1 ? "" : "\n");
    }
}
