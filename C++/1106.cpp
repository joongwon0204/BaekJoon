// https://www.acmicpc.net/problem/1106
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

    int c, n;
    cin >> c >> n;

    vector<pair<int, int>> wvs; 
    wvs.push_back(make_pair(0,0));
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        wvs.push_back(make_pair(w,v));
    }

    vector<vector<int>> C;
    C.push_back(vector<int>(n + 1, 0));

    int d = 1;
    
    bool flag = true;
    while(flag) {
        C.push_back(vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            if (d < wvs[i].first) {
                C[d][i] = C[d][i - 1];
            } else {
                C[d][i] = max(C[d][i - 1], C[d - wvs[i].first][i] + wvs[i].second);
                if (C[d][i] >= c) flag = false;
            }
        }
        d++;
    }

    cout << --d;
}