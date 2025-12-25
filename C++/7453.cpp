// https://www.acmicpc.net/problem/7453
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

// 범위가 [s, e)에서 탐색, s로 초기화, lower는 목표값중 가장 작은 i, upper는 목표값중 가장 큰 i + 1
int binary_s(long long x, vector<long long>& cd) {
    int l, h, m, s = 0, e = cd.size();
    long long cur;

    while (s < e) {
        m = (s + e) / 2;
        cur = cd[m];

        if (cur >= x) {
            e = m;
        } else {
            s = m + 1;
        }
    }
    l = s;

    s = 0, e = cd.size();
    while (s < e) {
        m = (s + e) / 2;
        cur = cd[m];

        if (cur > x) {
            e = m;
        } else {
            s = m + 1;
        }
    }
    h = s;

    return max(0, h - l);
}

int main() {
    init();

    int n;
    long long ta, tb, tc, td;

    cin >> n;

    vector<long long> a, b, c, d, ab, cd;
    for (int i = 0; i < n; i++) {
        cin >> ta >> tb >> tc >> td;
        a.push_back(ta);
        b.push_back(tb);
        c.push_back(tc);
        d.push_back(td);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    long long ans = 0;
    for (auto& x: ab) {
        ans += binary_s(-x, cd);
    }

    cout << ans;
}