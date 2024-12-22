// https://www.acmicpc.net/problem/1509
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

bool is_pel(string str) {
    int n = str.size(), s = 0, e = n - 1;

    while (s < e) {
        if (str[s] == str[e]) {
            s++;
            e--;
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    init();

    string ss;
    cin >> ss;

    int n = ss.size();

    vector<vector<int>> pel_lengths(n);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (is_pel(ss.substr(i, j))) {
                pel_lengths[i].push_back(j);
            }
        }
    }

    vector<int> cache(n, 0);

    cache[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        int min_sep = 10000;
        for (auto& pel_length: pel_lengths[i]) {
            if (i + pel_length == n) {
                min_sep = 1;
            } else {
                min_sep = min(min_sep, cache[i + pel_length] + 1);
            }
        }
        cache[i] = min_sep;
    }

    cout << cache[0];
}