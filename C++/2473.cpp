// https://www.acmicpc.net/problem/2473
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

pair<long long, int> binary_s(long long mix, int x, int e, vector<long long>& liq) {
    long long cur_sum, min_sum = 3000000001;
    int min_liq,m, s = x + 1;

    while (s <= e) {
        m = (s + e) / 2;

        cur_sum = liq[m] + mix;

        if (abs(cur_sum) < min_sum) {
            min_sum = abs(cur_sum);
            min_liq = m;
        }

        if (cur_sum == 0) {
            return {cur_sum, m};
        }

        if (cur_sum < 0) {
            s = m + 1;
        } else {
            e = m - 1;
        }
    }

    return {min_sum, min_liq};
}

int main() {
    init();

    int n;
    cin >> n;

    long long temp;
    vector<long long> liq;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        liq.push_back(temp);
    }

    sort(liq.begin(), liq.end());


    long long min_sum = 3000000001;
    vector<int> ans(3);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            auto [cur_sum, cur_liq] = binary_s(liq[i] + liq[j], j, n - 1, liq);

            if (cur_sum < min_sum) {
                min_sum = cur_sum;
                ans = {i, j, cur_liq};
            
                if (cur_sum == 0) break;
            }

        }
    }

    cout << liq[ans[0]] << ' ' << liq[ans[1]] << ' ' << liq[ans[2]];
}