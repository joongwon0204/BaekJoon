// https://www.acmicpc.net/problem/2638
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool will_melt(int y, int x, vector<vector<bool>>& is_cheese, vector<vector<bool>>& visited) {
    int new_y, new_x, count = 0;

    for (auto& move: moves) {
        new_y = y + move.first;
        new_x = x + move.second;
        if (!is_cheese[new_y][new_x] && visited[new_y][new_x]) {
            count++;
        }
    }

    return count >= 2;
}


bool bfs(const int n, const int m, vector<vector<bool>>& is_cheese) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<pair<int, int>> cheeses, melting_cheeses;

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    int new_y, new_x;
    bool ret = false;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (auto& move: moves) {
            new_y = y + move.first;
            new_x = x + move.second;

            if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= m) continue;

            if (!visited[new_y][new_x]) {

                visited[new_y][new_x] = true;

                if (is_cheese[new_y][new_x]) {
                    cheeses.push_back({new_y, new_x});
                } else {
                    q.push({new_y, new_x});
                }
            }
        }
    }

    for (auto [y, x]: cheeses) {
        if (will_melt(y, x, is_cheese, visited)) {
            melting_cheeses.push_back({y, x});
            ret = true;
        }
    }

    for (auto [y, x]: melting_cheeses) {
        is_cheese[y][x] = false;
    }

    return ret;
}

int main() {
    init();

    int n, m, temp, ans = 0;
    cin >> n >> m;

    vector<vector<bool>> is_cheese(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            if (temp == 1) {
                is_cheese[i][j] = true;
            }
        }
    }

    while (bfs(n, m, is_cheese)) {
        ans++;
    }

    cout << ans;
}