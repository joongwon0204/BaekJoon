// https://www.acmicpc.net/problem/1916
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int n, m;
    cin >> n >> m;

    vector<int> cities(n);
    iota(cities.begin(), cities.end(), 1);

    vector<vector<pair<int, int>>> buses(n+1);
    int u, v, t;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> t;
        buses[u].push_back(make_pair(v,t));
    }

    int s, e;
    cin >> s >> e;
}