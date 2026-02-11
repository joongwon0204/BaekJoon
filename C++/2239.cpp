// https://www.acmicpc.net/problem/2239
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

using Board = vector<vector<int> >;

bool fit(Board& B, int x, int y, int n) {
    int bi = x / 3 * 3, bj = y / 3 * 3;

    for (int i = 0; i < 9; i++) {
        if (i != x) {
            if (B[i][y] == n) return false;
        }
        if (i != y) {
            if (B[x][i] == n) return false;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (bi+i == x && bj+j == y) continue;
            if (B[bi+i][bj+j] == n) return false;
        }
    }

    return true;
}

bool bt(Board& B, vector<int>& emptys, int p) {
    if (p == emptys.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << B[i][j];
            }
            cout << (i == 8 ? "" : "\n");
        }
        return true;
    }

    int x = emptys[p] / 9, y = emptys[p] % 9;

    for (int n = 1; n <= 9; n++) {
        B[x][y] = n;
        if (fit(B,x,y,n) && bt(B,emptys,p+1)) {
            return true;
        }
        B[x][y] = 0;
    }

    return false;
}


int main() {
    init();
    vector<int> emptys;

    Board B(9, vector<int>(9, 0));
    
    for (int i = 0; i < 9; i++) {
        string row;
        cin >> row;
        for (int j=0;j<9;j++){
            int t = row[j]-'0';
            B[i][j] = t;
            if (t == 0) emptys.push_back(i*9 + j);
        }
    }

    bt(B,emptys,0);
}