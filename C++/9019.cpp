// https://www.acmicpc.net/problem/9019
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int D(int n) {
    return n * 2 % 10000;
}

int S(int n) {
    return (n==0 ? 9999 : n-1);
}

int L(int n) {
    return ((10 * n) % 10000) + (n / 1000);
}

int R(int n) {
    return (n / 10) + ((n % 10) * 1000);
}

string bfs(int a, int b) {
    if (a==b) { return ""; }
    string command[10000];
    bool visited[10000];
    for (int i = 0; i < 10000; i++) { command[i] = ""; visited[i] = false; }

    queue<int> q;

    q.push(a);
    visited[a] = 1;
    command[a] = "";

    vector <pair<int(*)(int), char>> operations = {{D, 'D'}, {S, 'S'}, {L, 'L'}, {R, 'R'}};

    while (!q.empty()) {
        int cur_num = q.front();
        q.pop();

        for (auto& op: operations) {
            int new_num = op.first(cur_num);

            if (!visited[new_num]) {
                command[new_num] = command[cur_num] + op.second;
                if (new_num == b) { return command[new_num]; }

                q.push(new_num);
                visited[new_num] = true;
            }
        }
    }
    return "";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int T;
    cin >> T;

    int a, b;
    for (int i = 0; i < T; i++) {
        cin >> a >> b;

        cout << bfs(a, b) << '\n';
    }
}