// https://www.acmicpc.net/problem/11049
#include <iostream>
#include <string>
#include <vector>


using namespace std;
const long INF = (1 << 31) - 1;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int n;
    cin >> n;

    vector<int> shape;
    
    int r, c;
    for (int i = 0; i < n - 1; i++) {
        cin >> r >> c;
        shape.push_back(r);
    }
    cin >> r >> c;
    shape.push_back(r);
    shape.push_back(c);

    vector<vector<int>> cost = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++) {
        cost[i][i] = 0;
    }
    
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;

            for (int k = i; k < j; k++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k+1][j] + shape[i-1]*shape[k]*shape[j]);
            }
        }
    }
    cout << cost[1][n];
}