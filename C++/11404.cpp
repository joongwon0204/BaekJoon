// https://www.acmicpc.net/problem/11404
#include <iostream>
#include <string>
#include <vector>


using namespace std;
using Graph = vector<vector<int>>;
const int INF = 100000 * 101;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int n, e;
    cin >> n >> e;

    Graph G(n + 1, vector<int>(n + 1, INF));
    //Graph P(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        G[i][i] = 0;
    }
    for (int _ = 0; _ < e; _++) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a][b] = min(w, G[a][b]);
        //P[a][b] = a;
    }

    for (int k = 1; k <= n; k++) {
        Graph TG(n + 1, vector<int>(n + 1, INF));
        //Graph TP(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int newPath = min(INF, G[i][k] + G[k][j]);
                if (G[i][j] > newPath) {
                    TG[i][j] = newPath;
                    //TP[i][j] = P[k][j];
                } else {
                    TG[i][j] = G[i][j];
                    //TP[i][j] = P[i][j];
                }
            }
        }
        G = TG;
        //P = TP;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (G[i][j] == INF ? 0 : G[i][j]) << (j == n ? (i == n ? "" : "\n") : " ");
        }
    }
}
