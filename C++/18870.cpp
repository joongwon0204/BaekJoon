// https://www.acmicpc.net/problem/18870
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int n, temp;
    cin >> n;

    set<int> num_set;
    vector<int> num_vector;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        num_set.insert(temp);
        num_vector.push_back(temp);
    }

    int order = 0;
    unordered_map<int, int> comp_num;
    for (auto it = num_set.begin(); it != num_set.end(); it++) {
        comp_num[*it] = order++;
    }

    for (auto& num: num_vector) {
        cout << comp_num[num] << ' ';
    }
}