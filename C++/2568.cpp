// https://www.acmicpc.net/problem/2568
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
    
    vector<pair<int,int>> seq(N);
    for (int i = 0; i < N; i++) {
        int a,b;
        cin >> a >> b;
        seq[i] = {a,b};
    }

    sort(seq.begin(), seq.end());


    vector<int> tails;
    vector<int> pos(N);

    for (int i = 0; i < N; i++) {
        int x = seq[i].second;
        auto it = lower_bound(tails.begin(), tails.end(), x);
        int p = it - tails.begin();
        pos[i] = p;

        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }

    int l = tails.size();
    cout << N - l;

    vector<int> ans;

    int cur = l - 1;
    for (int i = N - 1; i >= 0; i--) {
        if (pos[i] == cur) {
            ans.push_back(seq[i].first);
            cur--;
            if (cur < 0) break;
        }
    }

    int comp = 0;

    for (int i = l-1; i >= 0; i--) {
        if (comp >= N) break;
        while (seq[comp].first != ans[i]) {
            cout << '\n' << seq[comp++].first;
        }
        comp++;
    }
    while (comp < N) cout << '\n' << seq[comp++].first;
}