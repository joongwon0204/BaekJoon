// https://www.acmicpc.net/problem/17143
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

class Shark {
public:
    int r, c, s, d, z;
    int R, C;

    Shark(int r_, int c_, int s_, int d_, int z_, int R_, int C_)
        : r(r_), c(c_), s(s_), d(d_), z(z_), R(R_), C(C_) {}

    bool isBiggerThan(Shark& other) {
        return z > other.z;
    }

    void move() {
        if (d == 1) {
            if (c == 1)
        } else if (d == 2) {

        } else if (d == 3) {

        } else if (d == 4) {

        }
    }
};

int main() {
    init();

    int R, C, m;
    cin >> R >> C >> m;

    vector<vector<int>> ocean(R,vector<int>(C));
    vector<Shark> sharks;

    for (int i = 0; i < m; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        Shark shark(--r,--c,s,d,z,R,C);
        sharks.push_back(shark);
        ocean[r][c] = z;
    }

}