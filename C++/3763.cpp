// https://www.acmicpc.net/problem/3763
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
    int bi = x / 4 * 4, bj = y / 4 * 4;

    for (int i = 0; i < 16; i++) {
        if (i != x) {
            if (B[i][y] == n) return false;
        }
        if (i != y) {
            if (B[x][i] == n) return false;
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (bi+i == x && bj+j == y) continue;
            if (B[bi+i][bj+j] == n) return false;
        }
    }

    return true;
}

bool bt(Board& B, vector<int>& emptys, int p) {
    if (p == emptys.size()) {
        string abc = "-ABCDEFGHIJKLMNOP";
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                cout << abc[B[i][j]];
            }
            cout << (i == 15 ? "" : "\n");
        }
        return true;
    }

    int x = emptys[p] / 16, y = emptys[p] % 16;

    for (int n = 1; n <= 16; n++) {
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

    Board B(16, vector<int>(16, 0));
    
    for (int i = 0; i < 16; i++) {
        string row;
        cin >> row;
        for (int j=0;j<16;j++){
            int t;
            if (row[j] == '-') t = 0;
            else t = row[j]-'A'+1;
            B[i][j] = t;
            if (t == 0) emptys.push_back(i*16 + j);
        }
    }

    bt(B,emptys,0);
}