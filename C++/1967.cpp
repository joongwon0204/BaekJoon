// https://www.acmicpc.net/problem/1967
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

void dfs(int cur, vector<int>& distance, map<int, vector<pair<int, int>>>& connected_time) {

    for (auto& next: connected_time[cur]) {
        if (distance[next.first] != -1) { continue; }

        distance[next.first] = distance[cur] + next.second;
        dfs(next.first, distance, connected_time);
    }
}

int main() {
    init();

    int v, t1, t2, t3;
    cin >> v;

    vector<int> distance(v + 1, -1);
    distance[1] = 0;
    map<int, vector<pair<int, int>>> connected_time;

    for (int i = 0; i < v - 1; i++) {
        cin >> t1 >> t2 >> t3;
        connected_time[t1].push_back(make_pair(t2,t3));
        connected_time[t2].push_back(make_pair(t1,t3));
    }

    dfs(1, distance, connected_time);

    int max_d = -1, max_i;
    for (int i = 1; i <= v; i++) {
        if (max_d < distance[i]) {
            max_d = distance[i];
            max_i = i;
        }
        distance[i] = -1;
    }

    distance[max_i] = 0;
    dfs(max_i, distance, connected_time);

    for (int i = 1; i <= v; i++) {
        max_d = max(max_d, distance[i]);
    }
    
    cout << max_d;
}