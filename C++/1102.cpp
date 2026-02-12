// https://www.acmicpc.net/problem/1102
#include <iostream>
#include <string>
#include <vector>
#include <cmath>


using namespace std;
using Graph = vector<vector<int>>;
const int INF = -1 + (1 << 31);

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int n;
    cin >> n;

    Graph G(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }

    string on;
    cin >> on;
    
    vector<int> dp((1 << n), INF);

    int startBit = 0, startCount = 0;
    for (int i = 0; i < n; i++) {
        startCount += on[i] == 'Y' ? 1 : 0;
        startBit += ((on[i] == 'Y' ? 1 : 0) << i);
    }
    dp[startBit] = 0;

    vector<int> reachables;
    reachables.push_back(startBit);

    int p;
    cin >> p;

    vector<bool> done((1 << n), false);

    for (int s = startCount; s < p; s++) {
        if (reachables.size() == 0) {cout << -1; return 0;}

        vector<int> temp;
        
        for (auto bit: reachables) {
            if (done[bit]) continue;

            for (int i = 0; i < n; i++) {
                if (bit & (1 << i)) continue;

                int nbit = bit | (1 << i);

                int minCost = INF;
                for (int j = 0; j < n; j++) {
                    if (!(bit & (1 << j))|| i == j) continue;
                    minCost = min(minCost, G[j][i]);
                }
                if (minCost == INF) continue;

                temp.push_back(nbit);
                dp[nbit] = min(dp[nbit], dp[bit] + minCost);
            }

            done[bit] = true;
        }
        reachables = temp;
    }


    int ans = INF;
    for (auto bit: reachables) {
        ans = min(ans, dp[bit]);
    }

    cout << ans;
}