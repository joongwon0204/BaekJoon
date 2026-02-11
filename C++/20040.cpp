// https://www.acmicpc.net/problem/20040
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
    vector<int> p, sz;
    DSU(int n) : p(n+1), sz(n+1, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return true;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return false;
    }
};


int main() {
    init();

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    bool hasCycle = false;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (dsu.unite(a, b)) {
            cout << i;
            hasCycle = true;
            break;
        }
    }
    if (!hasCycle) cout << 0;
}