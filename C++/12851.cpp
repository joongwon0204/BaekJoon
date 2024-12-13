// https://www.acmicpc.net/problem/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

pair<int, int> bfs(int n, int k) {
    unordered_map<int, int> visited;
    queue<int> q;
    q.push(n);
    visited[n] = 1;

    int size, cur, max_p = k * 2 - n, ret_time = 0, ret_path = 0;
    bool is_found = false;
    vector<int> nexts;
    vector<int> temp_visits;

    while (!q.empty() && !is_found) {
        size = q.size();

        while (size--) {
            cur = q.front();
            q.pop();

            nexts.clear();
            if (cur > 0) { nexts.push_back(cur - 1); }
            if (cur <= k) { nexts.push_back(cur + 1); }
            if (cur * 2 <= max_p) { nexts.push_back(cur * 2); }

            for (auto& next: nexts) {
                if (next == k) {
                    is_found = true;
                    ret_path++;
                    continue;
                } else if (!visited[next] || visited[next] == ret_time + 1) {
                    q.push(next);
                    visited[next] = ret_time + 1;
                }
            }
        }
        ret_time++;
    }

    return make_pair(ret_time, ret_path);
}

int main() {
    init();

    int n, k;
    cin >> n >> k;

    pair<int, int> ans = bfs(n, k);
    if (n != k) {cout << ans.first << '\n' << ans.second; }
    else { cout << "0\n1"; }
}