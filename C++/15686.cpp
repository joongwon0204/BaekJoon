// https://www.acmicpc.net/problem/15686
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int min_d = 1234567;

void solve(int prev_c, int left, vector<bool>& selected, const int& c, const int& h, const vector<vector<int>>& ds) {
    if (left == 0) {
        int temp, cur_d = 0;
        for (int i = 0; i < h; i++) {
            temp = 1234567;
            for (int j = 0; j < c; j++) {
                if (!selected[j]) { continue; }
                temp = min(temp, ds[j][i]);
            }
            cur_d += temp;
        }
        min_d = min(min_d, cur_d);
        return;
    }

    for (int i = prev_c + 1; i < c - left + 1; i++) {
        selected[i] = true;
        solve(i, left - 1, selected, c, h, ds);
        selected[i] = false;
    }
}


int main() {
    init();

    int n, m, temp;
    cin >> n >> m;
    vector<pair<int, int>> houses;
    vector<pair<int, int>> chickens;
    pair<int, int> house, chicken;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            if (temp == 1) {
                houses.push_back(make_pair(i,j));
            } else if (temp == 2) {
                chickens.push_back(make_pair(i,j));
            }
        }
    }

    int h = houses.size(), c = chickens.size();

    vector<vector<int>> ds(c, vector<int>(h, 0));
    for (int i = 0; i < c; i++) {
        chicken = chickens[i];
        for (int j = 0; j < h; j++) {
            house = houses[j];
            ds[i][j] = abs(chicken.first - house.first) + abs(chicken.second - house.second);
        }
    }

    vector<bool> selected(c, false);
    solve(-1, m, selected, c, h, ds);

    cout << min_d;

}