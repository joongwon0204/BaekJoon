// https://www.acmicpc.net/problem/20303
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

struct DSU {
    vector<int> p, sz, candy;
    DSU(int n) : p(n+1), sz(n+1, 1), candy(n+1){
        iota(p.begin(), p.end(), 0);
        for (int i = 1; i <= n; i++) {
            int c;
            cin >> c;
            candy[i] = c;
        }
    }
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        candy[a] += candy[b];
        return true;
    }
    pair<int,int> getInfo(int i) {
        return make_pair(candy[i], sz[i]);
    }
};

int main() {
    init();

    int N, M, K;
    cin >> N >> M >> K;

    DSU friends(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        friends.unite(u,v);
    }

    vector<bool> visited(N + 1);
    vector<pair<int, int>> vw(1);
    for (int i = 1; i <= N; i++) {
        int c = friends.find(i);
        if (!visited[c]) {
            vw.push_back(friends.getInfo(c));
            visited[c] = true;
        }
    }
    int n = vw.size() - 1;
    vector<vector<int>> dp(K, vector<int>(n + 1));

    for (int j = 1; j <= n; j++) {
        dp[0][j] = 0;
    }

    for (int w = 1; w < K; w++) {
        for (int j = 1; j <= n; j++) {
            if (vw[j].second > w) dp[w][j] = dp[w][j-1];
            else {
                dp[w][j] = max(dp[w-vw[j].second][j-1] + vw[j].first, dp[w][j-1]);
            }
        }
    }
    cout << dp[K - 1][n];
}