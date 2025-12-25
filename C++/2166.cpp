// https://www.acmicpc.net/problem/2166
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int n;
    cin >> n;

    vector<pair<long long, long long>> xy;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        xy.push_back(make_pair(a,b));
    }
    xy.push_back(xy[0]);

    long long area = 0;

    for (int i = 0; i < n; i++) {
        area += xy[i].first * xy[i+1].second - xy[i+1].first * xy[i].second;
    }

    long double uarea = fabsl((long double)area) / 2.0;
    cout << fixed << setprecision(1) << uarea;
}