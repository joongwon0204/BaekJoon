// https://www.acmicpc.net/problem/1700
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int n, k;
    cin >> n >> k;

    vector<int> seq(k);
    for (int i = 0; i < k; i++) {
        cin >> seq[i];
    }
    
    vector<int> mt(n);
    int cap = 0, ans = 0;

    for (int i = 0; i < k; i++) {
        bool able = false;
        for (int j = 0; j < n; j++) {
            if (seq[i] == mt[j]) able = true;
        }
        if (able) continue;

        if (cap < n) { cap++; mt[cap] = seq[k]; continue; }
        
        int maxD = 0, maxMt = -1;
        for (int j = 0; j < n; j++) {
            if (maxD < mt[j]) {
                maxD = mt[j];
                maxMt = -1;
            }
        }
        
        ans++;
        mt[maxMt] = maxD;
    }

    cout << ans;
}