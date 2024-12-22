// https://www.acmicpc.net/problem/2467
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

pair<int, int> binary_s(int x, int n, vector<long long>& liq) {
    long long cur_x, cur_m, cur_sum, min_sum = 2000000001;
    int m, s = x + 1, e = n;

    cur_x = liq[x];

    while (s <= e) {
        m = (s + e) / 2;
        cur_m = liq[m];
        cur_sum = cur_x + cur_m;

        if (cur_sum == 0) return {x, m};

        if (abs(cur_sum) < min_sum) {
            min_sum = abs(cur_sum);
            n = m;
        }

        if (cur_sum > 0) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }

    return {x, n};
}


int main() {
    init();

    int n;
    cin >> n;

    int s, e;
    long long temp, min_sum = 2000000001;
    vector<long long> liq;
    for (int i = 0; i < n; i++) { 
        cin >> temp;
        liq.push_back(temp);
    }


    for (int i = 0; i < n - 1; i++) {
        auto [cur_s, cur_e] = binary_s(i, n - 1, liq);

        if (abs(liq[cur_s] + liq[cur_e]) < min_sum) {
            s = cur_s;
            e = cur_e;
            min_sum = abs(liq[cur_s] + liq[cur_e]);
        }
    }

    cout << liq[s] << ' ' << liq[e];
}