// https://www.acmicpc.net/problem/16946
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(int n, int m, int i, int j, int id, vector<vector<int>>& base, vector<vector<int>>& visited, vector<vector<int>>& counter) {
    int new_y, new_x, size, ret = 2;
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = id;
    vector<pair<int,int>> positions;
    positions.push_back({i,j});

    int counts = 1;
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (auto& move: moves) {
            new_y = move.first + y;
            new_x = move.second + x;
            
            if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= m) continue;

            if (base[new_y][new_x] == 0 && visited[new_y][new_x]== 0) {
                q.push({new_y, new_x});
                positions.push_back({new_y, new_x});
                visited[new_y][new_x] = id;
                counts++;
            }
        }
    }

    counts %= 10;
    for (auto& p: positions) {
        counter[p.first][p.second] = counts;
    }
}

int main() {
    init();

    int n, m, ans;
    string temp;
    cin >> n >> m;

    vector<vector<int>> base(n, vector<int>(m, 0));
    vector<vector<int>> counter(n, vector<int>(m, 0));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = 0; j < m; j++) {   
            base[i][j] = temp[j] - '0';
        }
    }

    int id = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {   
            if (base[i][j] == 1 || visited[i][j]) continue;
            else bfs(n, m, i, j, id++, base, visited, counter);
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {   
            if (base[i][j] == 0) cout << 0;
            else {
                int counts = 1;
                int new_y, new_x;
                vector<int> ids;
                for (auto& move: moves) {
                    new_y = move.first + i;
                    new_x = move.second + j;
                    
                    if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= m) continue;

                    bool able = true;
                    for (auto& id: ids) {
                        if (id == visited[new_y][new_x]) able = false;
                    }
                    if (able) {
                        counts += counter[new_y][new_x];
                        ids.push_back(visited[new_y][new_x]);
                    }
                }

                cout << counts % 10;
            }
        }
        cout << (i == n-1 ? "" : "\n");
    }
}