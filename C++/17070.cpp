// https://www.acmicpc.net/problem/17070
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

int move(int x, int y, int direction, int& n, vector<vector<int>>& is_wall, vector<vector<vector<int>>>& cache) {
    int ret = 0;
    //cache 처리
    int cache_data = cache[y][x][direction];
    if (cache_data != -1) { return cache_data; }

    int new_x = x + 1;
    int new_y = y + 1;
    //가로
    if (direction <= 1 && x < n - 1 && !is_wall[y][new_x]) {
        ret += move(new_x, y, 0, n, is_wall, cache);
    }
    //대각선
    if (x < n - 1 && y < n - 1 && !is_wall[new_y][new_x] && !is_wall[y][new_x] && !is_wall[new_y][x]) {
        ret += move(new_x, new_y, 1, n, is_wall, cache);
    }
    //세로
    if (direction >= 1 && y < n - 1 && !is_wall[new_y][x]) {
        ret += move(x, new_y, 2, n, is_wall, cache);
    }

    cache[y][x][direction] = ret;
    return ret;
}


int main() {
    init();

    int n;
    cin >> n;

    vector<vector<int>> room(n, vector<int>(n, 0));
    vector<vector<vector<int>>> cache(n, vector<vector<int>>(n, vector<int>(3, -1))); // 0 가로, 1 대각선, 2세로
    cache[n - 1][n - 1][0] = 1;
    cache[n - 1][n - 1][1] = 1;
    cache[n - 1][n - 1][2] = 1;

    int buffer;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> buffer;
            room[i][j] = buffer;
        }
    }

    cout << move(1, 0, 0, n, room, cache);
}