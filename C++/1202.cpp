// https://www.acmicpc.net/problem/1202
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}


int main() {
    init();

    int N, K;
    cin >> N >> K;

    vector<pair<int,int>> WV;
    for (int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;
        WV.push_back(make_pair(w,v));
    }

    vector<int> bags;
    for (int i = 0; i < K; i++) {
        int c;
        cin >> c;
        bags.push_back(c);
    }

    sort(bags.begin(), bags.end());
    sort(WV.begin(), WV.end());

    long long ans = 0;
    priority_queue<int> pq;
    int j = 0;
    for (int i = 0; i < K; i++) {
        while(j < N && WV[j].first <= bags[i]) {
            pq.push(WV[j].second);
            j++;
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
}