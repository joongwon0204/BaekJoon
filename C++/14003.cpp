// https://www.acmicpc.net/problem/14003
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
    
    int N;
    cin >> N;

    vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        cin >> seq[i];
    }

    vector<int> tails;
    vector<int> pos(N);

    for (int i = 0; i < N; i++) {
        int x = seq[i];
        auto it = lower_bound(tails.begin(), tails.end(), x);
        int p = it - tails.begin();
        pos[i] = p;

        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }

    int l = tails.size();
    cout << l << '\n';

    vector<int> ans;

    int cur = l - 1;
    for (int i = N - 1; i >= 0; i--) {
        if (pos[i] == cur) {
            ans.push_back(seq[i]);
            cur--;
            if (cur < 0) break;
        }
    }

    for (int i = l - 1; i >= 0; i--) {
        cout << ans[i] << (i == 0 ? "" : " ");
    }
}