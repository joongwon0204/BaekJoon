// https://www.acmicpc.net/problem/1620
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cctype>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> pn;
    unordered_map<int, string> np;
    string temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        pn[temp] = i;
        np[i] = temp;
    }

    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (isdigit(temp[0])) {
            cout << np[stoi(temp)] << '\n';
        } else {
            cout << pn[temp] << '\n';
        }
    }
}