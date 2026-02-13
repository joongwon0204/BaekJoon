// https://www.acmicpc.net/problem/2887
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

using Point = pair<int, int>;
const int mod = 1000007;

int main() {
    init();

    int n, m, c;
    cin >> n >> m >> c;

    vector<Point> games;
    games.push_back({1,1});
    for (int i = 1; i <= c; i++) {
        games.push_back({0,0});
        cin >> games[i].first >> games[i].second;
    }
    games.push_back({n,m});

    vector<vector<int>> dp(n+1,vector<int>(m+1));

    for (int k = 1)
}