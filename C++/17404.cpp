// https://www.acmicpc.net/problem/17404
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const int INF = 1000001;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int N;
    cin >> N;

    vector<vector<int>> color = vector<vector<int>>(N + 1, vector<int>(3));
    
    int r, g, b;
    for (int i = 1; i < N; i++) {
        cin >> r >> g >> b;
        color[i][0] = r;
        color[i][1] = g;
        color[i][2] = b;
    }
    cin >> r >> g >> b;
    color[N][0] = color[0][0] = r;
    color[N][1] = color[0][1] = g;
    color[N][2] = color[0][2] = b;

    vector<vector<int>> cost = vector<vector<int>>(N + 1, vector<int>(3, INF));

    int ans = INF;
    for (int fc = 0; fc < 3; fc++) {
        cost[1][fc] = color[1][fc];
        cost[1][(fc+1)%3] = INF;
        cost[1][(fc+2)%3] = INF;
        for (int i = 2; i <= N; i++) {
            for (int c = 0; c < 3; c++) {
                cost[i][c] = color[i][c] + min(cost[i - 1][(c + 1)%3], cost[i - 1][(c + 2)%3]);
            }
        }

        for (int c = 0; c < 3; c++) {
            if (fc == c) continue;
            ans = min(ans, cost[N][c]);
        }
    }

    cout << ans;
}