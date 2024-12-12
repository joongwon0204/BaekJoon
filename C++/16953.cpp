// https://www.acmicpc.net/problem/16953
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

long long bfs(int a, int b, vector<long long>& visited) {
    queue<long long> q;
    visited.push_back(a);
    q.push(a);

    int cur, size, ret = 1;
    vector<long long> nexts;
    while (!q.empty()) {
        size = q.size();
        while (size--) {
            cur = q.front();
            q.pop();
            if (cur == b) { return ret; }

            nexts = {cur * 2, cur * 10 + 1};
            for (auto& next: nexts) {
                if (next > b || count(visited.begin(), visited.end(), next) != 0) { continue; }

                q.push(next);
                visited.push_back(next);
            }
        }
        ret++;
    }

    return -1;
}

int main() {
    init();

    long long a, b;
    cin >> a >> b;

    vector<long long> visited;

    cout << bfs(a, b, visited) << '\n';
}