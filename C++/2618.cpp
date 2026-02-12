// https://www.acmicpc.net/problem/2618
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

using Point = pair<int, int>;
const int INF = 1000*1000;

int dist(Point a, Point b, int n, int x, int s) {
    if (x == 0) {
        if (s == 1) {
            return abs(b.first) + abs(b.second) - 2;
        } else {
            return abs(n-b.first) + abs(n-b.second);
        }
    }
    return abs(a.first-b.first) + abs(a.second-b.second);
}

int main() {
    init();

    int n, w;   
    cin >> n >> w;

    vector<Point> ps(w+1);
    for (int i = 1; i <= w; i++) {
        cin >> ps[i].first >> ps[i].second;
    }

    vector<vector<int>> dp(w+1,vector<int>(w+1, INF)), rs(w+1,vector<int>(w+1));
    dp[1][0] = ps[1].first + ps[1].second - 2; dp[0][1] = 2*n - (ps[1].first + ps[1].second);
    rs[1][0] = 1; rs[0][1] = 2;

    for (int k = 2; k <= w; k++) {
        int d1 = dist(ps[k-1],ps[k],n,k-1,1), d2 = dist(ps[k-1],ps[k],n,k-1,2);
        for (int a = 0; a < k - 1; a++) {
            dp[k][a] = dp[k - 1][a] + d1;
            dp[a][k] = dp[a][k - 1] + d2;
            rs[k][a] = k-1;
            rs[a][k] = k-1;
        }

        for (int a = 0; a < k - 1; a++) {
            int d3 = dp[a][k-1] + dist(ps[a],ps[k],n,a,1);
            int d4 = dp[k-1][a] + dist(ps[a],ps[k],n,a,2);
            if (dp[k][k-1] > d3) {
                dp[k][k-1] = d3;
                rs[k][k-1] = a;
            }
            if (dp[k-1][k] > d4) {
                dp[k-1][k] = d4;
                rs[k-1][k] = a;
            }

        }
    }

    int lastPol;
    for (int i = 0; i < w; i++) {
        if (dp[i][w] < dp[w][i]) {
            if (dp[w][w] > dp[i][w]) {
                dp[w][w] = dp[i][w];
                rs[w][w] = i;
                lastPol = 1;
            }
        } else {
            if (dp[w][w] > dp[w][i]) {
                dp[w][w] = dp[w][i];
                rs[w][w] = i;
                lastPol = 2;
            }
        }
    }
    vector<int> bt;
    
    cout << dp[w][w];

    int a = w, b = w;
    if (lastPol == 1) {
        a = rs[a][b];
    } else {
        b = rs[a][b];
    }

    for (int k = w; k >= 1; k--) {
        if (a == k) {
            bt.push_back(1);
            a = rs[a][b];
        } else {
            bt.push_back(2);
            b = rs[a][b];
        }
    }

    for (int i = w - 1; i >= 0; i--) {
        cout << '\n' << bt[i];
    }
}