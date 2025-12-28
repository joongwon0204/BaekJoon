// https://www.acmicpc.net/problem/1562
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

const int MOD = 1000000000;

int main() {
    init();
    
    int N;
    cin >> N;

    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(10, vector<int>(1 << 10)));

    for (int i = 1; i <= 9; i++) dp[1][i][1 << i] = 1;

    for (int l = 2; l <= N; l++) {
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j < 1 << 10; j++) {
                if (i < 9) {
                    dp[l][i + 1][j|(1 << (i+1))] += dp[l-1][i][j] % MOD;
                    dp[l][i + 1][j|(1 << (i+1))] %= MOD;
                }
                if (i > 0) {
                    dp[l][i - 1][j|(1 << (i-1))] += dp[l-1][i][j] % MOD;
                    dp[l][i - 1][j|(1 << (i-1))] %= MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans += dp[N][i][(1 << 10) - 1];;
        ans %= MOD;
    }

    cout << ans;
}