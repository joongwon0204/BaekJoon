#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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


class Edge {   
public:
    int u;
    int v;
    int cost;
    Edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
};
