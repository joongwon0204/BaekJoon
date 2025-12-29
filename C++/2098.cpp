// https://www.acmicpc.net/problem/2098
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

const int INF = 1000000000;

int main() {
    init();
    
    int N;
    cin >> N;

    vector<vector<int>> G(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> G[i][j];
        }
    }

    vector<vector<int>> dp(1 << N, vector<int>(N, INF));
    dp[1][0] = 0;
    for (int mask = 0; mask <= (1 << N) - 1; mask++) {
        for (int i = 0; i < N; i++) {
            if (!(mask & (1 << i)) || dp[mask][i] == INF) continue;

            for (int j = 0; j < N; j++) {
                if (mask & (1 << j) || G[i][j] == 0) continue;
                dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + G[i][j]);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < N; i++) {
        if (G[i][0] == 0) continue;
        ans = min(ans, dp[(1 << N) - 1][i] + G[i][0]);
    }

    cout << ans;
}