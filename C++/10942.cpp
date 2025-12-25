// https://www.acmicpc.net/problem/10942
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int N;
    cin >> N;

    vector<int> seq = vector<int>(1);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        seq.push_back(a);
    }

    vector<vector<int>> isPal = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i < N; i++) {
        isPal[i][i] = 1;
        if (seq[i] == seq[i + 1]) isPal[i][i + 1] = 1;
    }
    isPal[N][N] = 1;

    for (int l = 3; l <= N; l++) {
        for (int i = 1; i <= N - l + 1; i++) {
            int j = i + l - 1;
            if (isPal[i + 1][j - 1] == 1 && seq[i] == seq[j]) isPal[i][j] = 1;
        }
    }


    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;

        cout << isPal[s][e] << (i == M - 1 ? "" : "\n");
    }
}