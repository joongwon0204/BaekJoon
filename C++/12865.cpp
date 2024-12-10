// https://www.acmicpc.net/problem/12865
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    //input
    int n, k;
    cin >> n >> k;
    
    int i, j;
    vector<pair<int, int>> wnv;
    vector<vector<int>> cache(n + 1, vector<int>(k + 1, 0));
    for (i = 0; i < n; i++) {
        int temp_w, temp_v;
        cin >> temp_w >> temp_v;
        wnv.push_back({temp_w, temp_v});
    }

    for (i = 1; i <= n; i++) {
        for (j = 0; j <= k; j++) {
            if (wnv[i-1].first <= j) {
                cache[i][j] = max(cache[i-1][j], cache[i-1][j - wnv[i - 1].first] + wnv[i - 1].second);
            } else {
                cache[i][j] = cache[i-1][j];
            }
        }
    }

    cout << cache[n][k];
}