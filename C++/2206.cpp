// https://www.acmicpc.net/problem/2206
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(int n, int m, vector<vector<int>>& base, vector<vector<vector<int>>>& visited) {
    int new_y, new_x, size, ret = 2;
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1;

    while (!q.empty()) {
        auto [y, x, broken] = q.front();
        q.pop();

        if (y == n - 1 && x == m - 1) { return visited[y][x][broken]; }

        for (auto& move: moves) {
            new_y = move.first + y;
            new_x = move.second + x;
            
            if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= m) continue;

            if (base[new_y][new_x] == 0 && visited[new_y][new_x][broken] == 0) {
                q.push({new_y, new_x, broken});
                visited[new_y][new_x][broken] = visited[y][x][broken] + 1;
            } else if (base[new_y][new_x] == 1 && broken == 0 && visited[new_y][new_x][1] == 0) {
                q.push({new_y, new_x, 1});
                visited[new_y][new_x][1] = visited[y][x][broken] + 1;
            }
        }
    }

    return -1;
}

int main() {
    init();

    int n, m, ans = 1234567;
    string temp;
    cin >> n >> m;

    vector<vector<int>> base(n, vector<int>(m, 0));
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(2, 0)));
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = 0; j < m; j++) {   
            base[i][j] = temp[j] - '0';
        }
    }

    
    cout << bfs(n, m, base, visited);
}