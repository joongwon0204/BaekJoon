// https://www.acmicpc.net/problem/16236
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<pair<int, int>> moves = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

int bfs(int n, vector<int>& shark, vector<vector<int>>& water) {
    vector<vector<int>> visited(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    vector<vector<int>> fishes;
    q.push({shark[0], shark[1]});
    visited[shark[0]][shark[1]] = true;
    int q_size, new_y, new_x, new_w, size = shark[2], ret = 0;

    bool can_eat = false;

    pair<int, int> cur;
    while (!q.empty()) {
        q_size = q.size();
        fishes = {};
        while (q_size--) {
            auto [y, x] = q.front();
            q.pop();

            for (auto& move: moves) {
                new_y = y + move.first;
                new_x = x + move.second;

                if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= n || visited[new_y][new_x]) continue;

                new_w = water[new_y][new_x];

                if (new_w == 0 || new_w == size) {
                    q.push({new_y, new_x});
                } else if (new_w < size) {
                    can_eat = true;
                    fishes.push_back({new_y, new_x, new_w, shark[3] + 1});
                } 

                visited[new_y][new_x] = true;
            }
        }

        ret++;

        if (can_eat) {
            sort(fishes.begin(), fishes.end());
            vector<int> fish_eaten = fishes[0];
            shark = {fish_eaten[0], fish_eaten[1], (size == fish_eaten[3] ? size + 1 : size), (size == fish_eaten[3] ? 0 : fish_eaten[3])};
            water[fish_eaten[0]][fish_eaten[1]] = 0;
            return ret;
        }

    }
    return 0;
}


int main() {
    init();

    int n, temp, ans = 0;
    cin >> n;
    vector<vector<int>> water(n, vector<int>(n, 0));

    vector<int> shark;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            if (temp == 9) {
                shark = {i, j, 2, 0};
                water[i][j] = 0;
            } else {
                water[i][j] = temp;
            }
        }
    }

    int time = bfs(n, shark, water);
    while (time) {
        ans += time;
        time = bfs(n, shark, water);
    }

    cout << ans;

}