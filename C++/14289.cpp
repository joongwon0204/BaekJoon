// https://www.acmicpc.net/problem/12850
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

long long mod = 1000000007;

using Graph = vector<vector<long long>>;

Graph matPow(Graph& G, long long n);
Graph matMul(Graph& A, Graph& B);


Graph matPow(Graph& G, long long n) {
    if (n == 0) return Graph(1,vector<long long>(1,1));
    if (n == 1) return G;

    Graph g = matPow(G, n/2);
    Graph gPow = matMul(g,g);
    if (n % 2 == 0) return gPow;
    return matMul(G, gPow);
}

Graph matMul(Graph& A, Graph& B) {
    int n = A.size();
    Graph C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
            }
        }
    }
    return C;
}


int main() {
    init();

    int n, m;
    cin >> n >> m;
    Graph G(n, vector<long long>(n, 0));

    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        a--; b--;
        G[a][b] = G[b][a] = 1;
    }

    long long d;
    cin >> d;
    
    Graph D = matPow(G, d);
    cout << D[0][0];
}