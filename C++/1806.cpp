// https://www.acmicpc.net/problem/1806
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int N;
    long S;
    cin >> N >> S;

    vector<long> seq;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        seq.push_back(a);
    }

    int s = 0, f = 0, ans = N + 1;
    long sum = 0;
    
    while(true) {
        if (sum >= S) {
            ans = min(ans, f - s);
            sum -= seq[s++];
        } else {
            if (f == N) break;
            sum += seq[f++];
        }
    }

    cout << (ans == N + 1 ? 0 : ans);
}
