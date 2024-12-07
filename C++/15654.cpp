// https://www.acmicpc.net/problem/15654
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


void solve(vector<pair<int, bool>>& nums, int& m, vector<int>& comb) {
    int cur_length = comb.size();
    int n = nums.size();

    if (cur_length == m) {
        for (int i = 0; i < m; i++) {
            cout << comb[i] << (i == m - 1 ? '\n' : ' ');
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (nums[i].second) { continue; }

        int next_num = nums[i].first;
        comb.push_back(next_num);
        nums[i].second = true;
        solve(nums, m, comb);
        comb.pop_back();
        nums[i].second = false;
    }
    return;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, bool>> nums;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        nums.push_back(make_pair(temp, false));
    }
    sort(nums.begin(), nums.end());

    vector<int> comb = {};
    solve(nums, m, comb);
}