// https://www.acmicpc.net/problem/3780
#include <iostream>
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
    DSU(int n) : p(n+1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        //if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        return true;
    }

};

int main() {
    init();

    int T;
    cin >> T;

    for (int _ = 0; _ < T; _++) {
        int n;
        cin >> n;
        DSU dsu(n);

        bool formatter = false;
        while(true) {
            char op;
            cin >> op;
            if (op == 'O') break;
            else if (op =='E') {
                if (formatter) { cout << '\n'; }
                else formatter = true;

                int i;
                cin >> i;
                cout << (dsu.find(i) - i) % 1000;
            } else {
                if (formatter) { cout << '\n'; }
                else formatter = true;

                int i, j;
                cin >> i >> j;
                dsu.unite(i,j);
            }
        } 
    }

    
}