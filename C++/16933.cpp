// https://www.acmicpc.net/problem/16933
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

int bfs(int n, int m, int k, vector<vector<int>>& base, int (&visited)[1000][1000][11][2]) {
    int new_y, new_x, size, ret = 2;
    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, 0, 0});
    visited[0][0][0][0] = 1;

    while (!q.empty()) {
        auto [y, x, broken, night] = q.front();
        q.pop();

        if (y == n - 1 && x == m - 1) { return visited[y][x][broken][night]; }

        for (auto& move: moves) {
            new_y = move.first + y;
            new_x = move.second + x;
            
            if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= m) continue;

            if (base[new_y][new_x] == 0 && visited[new_y][new_x][broken][1-night] == 0) {
                q.push({new_y, new_x, broken, 1-night});
                visited[new_y][new_x][broken][1-night] = visited[y][x][broken][night] + 1;
            } else if (base[new_y][new_x] == 1 && broken < k && visited[y][x][broken][1-night] == 0 && night == 1) {
                q.push({y, x, broken,1-night});
                visited[y][x][broken][1-night] = visited[y][x][broken][night] + 1;
            } else if (base[new_y][new_x] == 1 && broken < k && visited[new_y][new_x][broken+1][1-night] == 0 && night == 0) {
                q.push({new_y, new_x, broken+1,1-night});
                visited[new_y][new_x][broken+1][1-night] = visited[y][x][broken][night] + 1;
            }
        }
    }

    return -1;
}

int main() {
    init();

    int n, m, k, ans = 1234567;
    string temp;
    cin >> n >> m >> k;

    vector<vector<int>> base(n, vector<int>(m, 0));
    static int visited[1000][1000][11][2];
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = 0; j < m; j++) {   
            base[i][j] = temp[j] - '0';
        }
    }

    
    cout << bfs(n, m, k, base, visited);
}