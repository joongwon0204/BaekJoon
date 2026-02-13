// https://www.acmicpc.net/problem/12014
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N, K;
        cin >> N >> K;

        vector<int> seq(N);
        for (int i = 0; i < N; i++) {
            cin >> seq[i];
        }

        vector<int> tails;
        for (int x : seq) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) tails.push_back(x);
            else *it = x;
        }

        cout << "Case #" << t << '\n' << (tails.size() >= K);
        cout << (t == T ? "" : "\n");
    }
}