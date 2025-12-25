// https://www.acmicpc.net/problem/9252
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

    string A, B;
    cin >> A >> B;
    int a = A.length(), b = B.length();

    const int NONE = 0, LEFT = 1, UP = 2, DGNL = 3;
    vector<vector<int>> maxl = vector<vector<int>>(a + 1, vector<int>(b + 1, 0));
    vector<vector<int>> move = vector<vector<int>>(a + 1, vector<int>(b + 1, NONE));
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (A[i - 1] == B[j - 1]) {
                move[i][j] = DGNL;
                maxl[i][j] = maxl[i - 1][j - 1] + 1;
            } else if (maxl[i - 1][j] > maxl[i][j - 1]) {
                move[i][j] = LEFT;
                maxl[i][j] = maxl[i - 1][j];
            } else {
                move[i][j] = UP;
                maxl[i][j] = maxl[i][j - 1];
            }
        }
    }

    cout << maxl[a][b];
    if (maxl[a][b] != 0) {
        vector<char> LCS;
        int x = a, y = b;
        while(x != 0 && y != 0) {
            if (move[x][y] == DGNL) {
                x--; y--;
                LCS.push_back(A[x]);
            } else if (move[x][y] == LEFT) {
                x--;
            } else {
                y--;
            }
        }
        cout << "\n";
        for (int i = LCS.size() - 1; i >= 0; i--) {
            cout << LCS[i];
        }
    }
}