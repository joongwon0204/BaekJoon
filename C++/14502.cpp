// https://www.acmicpc.net/problem/14502
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int min_v = 1234567;

vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(int n, int m, queue<pair<int, int>> q, vector<vector<int>>& base, vector<vector<int>> visited) {
    pair<int, int> cur;
    int new_y, new_x, ret = 0;

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        ret++;

        for (auto& move: moves) {
            new_y = move.first + cur.first;
            new_x = move.second + cur.second;

            if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= m) continue;
            if (base[new_y][new_x] == 0 && !visited[new_y][new_x]) {
                q.push(make_pair(new_y, new_x));
                visited[new_y][new_x] = 1;
            }
        }
    }

    min_v = min(min_v, ret);
}

int main() {
    init();

    int n, m, temp, wall_count = 3;
    cin >> n >> m;

    vector<vector<int>> base(n, vector<int>(m, 0)), visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            if (temp == 2) { 
                q.push(make_pair(i,j));
                visited[i][j] = 1;
            } else if (temp == 1) {
                wall_count++;
            }
            base[i][j] = temp;
        }
    }

    vector<vector<int>> new_base = base;
    for (int i = 0; i < n * m - 2; i++) {
        if (base[i/m][i%m] != 0) continue;

        for (int j = i + 1; j < n * m - 1; j++) {
            if (base[j/m][j%m] != 0) continue;

            for (int k = j + 1; k < n * m; k++) {
                if (base[k/m][k%m] != 0) continue;

                new_base[i/m][i%m] = 1;
                new_base[j/m][j%m] = 1;
                new_base[k/m][k%m] = 1;
            
                bfs(n, m, q, new_base, visited);

                new_base[i/m][i%m] = 0;
                new_base[j/m][j%m] = 0;
                new_base[k/m][k%m] = 0;
            }
        }
    }

    cout << n * m - wall_count - min_v;
}