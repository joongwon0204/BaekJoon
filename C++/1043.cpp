// https://www.acmicpc.net/problem/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int n, m, temp;
    cin >> n >> m;

    int count;
    queue<int> knows;
    cin >> count;
    for (int i = 0; i < count; i++) {
        cin >> temp;
        knows.push(temp);
    }

    vector<vector<int>> people(m); //[파티] -> 사람들
    vector<vector<int>> parties(n + 1); //[사람] -> 파티들
    for (int i = 0; i < m; i++) {
        cin >> count;
        for (int j = 0; j < count; j++) {
            cin >> temp;
            people[i].push_back(temp);
            parties[temp].push_back(i);
        }
    }

    set<int> cant_lies;
    vector<bool> visited(n + 1, false);
    
    if (!knows.empty()) {
        visited[knows.front()] = true;
        while (!knows.empty()) {
            int know = knows.front();
            knows.pop();

            for (auto& party: parties[know]) {
                cant_lies.insert(party);

                for (auto& person: people[party]) {

                    if (!visited[person]) {
                        knows.push(person);
                        visited[person] = true;
                    }
                }
            }
        }
    }
    
    cout << m - cant_lies.size();
}