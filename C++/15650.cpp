// https://www.acmicpc.net/problem/15650
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


void solve(int& n, int& m, int last_num, string& comb) {
    int cur_length = comb.size();
    if (cur_length == m) {
        for (int i = 0; i < m; i++) {
            cout << comb[i] << (i == m - 1 ? '\n' : ' ');
        }
        return;
    }

    for (int i = last_num + 1; i <= n; i++) {
        comb.push_back('0' + i);
        solve(n, m, i, comb);
        comb.pop_back();
    }
    return;
}


int main() {
    int n, m;
    cin >> n >> m;

    string comb = "";
    solve(n, m, 0, comb);
}