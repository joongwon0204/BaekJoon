// https://www.acmicpc.net/problem/2342
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const int INF = 100000 * 10;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    vector<int> seq;
    int x;
    while(cin >> x && x != 0){
        seq.push_back(x);
    }

    vector<vector<int>> move = vector<vector<int>>(5,vector<int>(5));
    
    for (int i = 0; i <= 4; i++) {
        move[i][i] = 1;
    }
    for (int i = 1; i <= 4; i++) {
        move[0][i] = 2;
    }
    for (int i = 1; i <= 4; i++) {
        int op = (i+1)%4 + 1;
        int n1 = i%4 + 1, n2 = (i+2)%4 + 1;
        move[i][op] = 4;
        move[i][n1] = move[i][n2] = 3;
        move[i][i] = 1;
    }
    int n = seq.size();
    vector<vector<vector<int>>> cost = vector<vector<vector<int>>>(n+1, vector<vector<int>>(5,vector<int>(5, INF)));
    cost[0][0][0] = 0;
    for (int l = 1; l <= n; l++) {
        for (int i = 0; i <= 4; i++) {
            for (int j = 0; j <= 4; j++) {
                int cur = seq[l - 1];
                cost[l][i][cur] = min(cost[l][i][cur], 
                    cost[l - 1][i][j] + move[j][cur]);
                cost[l][cur][j] = min(cost[l][cur][j], 
                    cost[l - 1][i][j] + move[i][cur]);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 4; j++) {
            ans = min(ans, cost[n][i][j]);
        }
    }

    cout << ans;
}