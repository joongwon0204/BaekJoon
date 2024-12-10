// https://www.acmicpc.net/problem/1764
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

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> ds;
    string temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        ds[temp] = 1;
    }

    vector<string> dbs;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (ds[temp] == 1) {
            dbs.push_back(temp);
        }
    }

    sort(dbs.begin(), dbs.end());
    cout << dbs.size() << '\n';
    for (auto& db: dbs) {
        cout << db << '\n';
    }
}