// https://www.acmicpc.net/problem/9251
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

    string a, b;
    cin >> a >> b;

    int la = a.size(), lb = b.size();
    vector<vector<int>> cache(la + 1, vector<int>(lb + 1, 0));

    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
            if (a[i - 1] == b[j - 1]) {
                cache[i][j] = cache[i - 1][j - 1] + 1;
            } else {
                cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
            }
        }
    }

    cout << cache[la][lb];
}