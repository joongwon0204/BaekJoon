// https://www.acmicpc.net/problem/1647
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using Graph = vector<vector<pair<int, int>>>;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

class Edge {   
public:
    int u;
    int v;
    int cost;
    Edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
};

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
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main() {
    init();

    int n, m;
    cin >> n >> m;

    if (n == 2) {cout << 0; return 0;}

    vector<Edge> edges = vector<Edge>();

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(Edge(a,b,c));
    }

    sort(edges.begin(), edges.end(),
    [](const Edge& a, const Edge& b) {
        return a.cost < b.cost;
    });


    DSU dsu(n);
    long long ans = 0;
    
    int i = 0;
    for (const auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            ans += e.cost;
            if (++i == n - 2) break;
        }
    }

    cout << ans;

}