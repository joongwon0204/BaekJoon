// https://www.acmicpc.net/problem/9328
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int h, w;
        cin >> h >> w;

        vector<vector<char>> M(h+2, vector<char>(w+2, '.'));

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> M[i][j];
            }
        }


        string keys;
        cin >> keys;
        vector<bool> isAble(26, false);
        if (keys != "0") {
            for (char k: keys) {
                isAble[k-'a'] = true;
            }
        }

        int ans;
        bool flag = true;

        while(true) {
            ans = 0;
            vector<vector<bool>> visited(h+2, vector<bool>(w+2,false));
            queue<pair<int,int>> q;
            q.push(make_pair(0,0));
            visited[0][0] = true;

            while(!q.empty() && flag) {
                pair<int,int> xy = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = xy.first + dx[i], ny = xy.second + dy[i];
                    if (nx < 0 || nx > h+1 || ny < 0 || ny > w+1) continue;
                    if (visited[nx][ny]) continue;
                    visited[nx][ny] = true;

                    int next = M[nx][ny];
                    pair<int,int> nextPair = make_pair(nx, ny);
                    if (next == '*') continue;
                    else if (next == '.') q.push(nextPair);
                    else if (next == '$') { q.push(nextPair); ans++; }
                    else if (next >= 'a' && next <= 'z') {
                        if (isAble[next-'a']) q.push(nextPair);
                        else { isAble[next-'a'] = true; flag = false; break; }
                    } else {
                        if (isAble[next-'A']) q.push(nextPair);
                        else continue;
                    }
                }
            }

            if (flag) break;
            flag = true;
        }

        cout << ans << (t==T-1 ? "" : "\n");
    }
}