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
    Graph C(8, vector<long long>(8, 0));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
            }
        }
    }
    return C;
}


int main() {
    init();

    int n;
    cin >> n;
    Graph G(8, vector<long long>(8, 0));
    G[0][1] = 1;
    G[0][2] = 1;

    G[1][0] = 1;
    G[1][2] = 1;
    G[1][3] = 1;

    G[2][0] = 1;
    G[2][1] = 1;
    G[2][3] = 1;
    G[2][4] = 1;

    G[3][1] = 1;
    G[3][2] = 1;
    G[3][4] = 1;
    G[3][5] = 1;

    G[4][2] = 1;
    G[4][3] = 1;
    G[4][5] = 1;
    G[4][6] = 1;

    G[5][3] = 1;
    G[5][4] = 1;
    G[5][7] = 1;

    G[6][4] = 1;
    G[6][7] = 1;

    G[7][5] = 1;
    G[7][6] = 1;

    Graph D = matPow(G, n);
    cout << D[0][0];
}