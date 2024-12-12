// https://www.acmicpc.net/problem/15666
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(const int& m, int last_i, vector<int>& nums, vector<int>& comb) {
    int n = nums.size(), cur_length = comb.size();
    if (cur_length == m) {
        for (int i = 0; i < m; i++) {
            cout << comb[i] << (i == m - 1 ? '\n' : ' ');
        }
        return;
    }

    for (int i = last_i; i < n; i++) {
        comb.push_back(nums[i]);
        solve(m, i, nums, comb);
        comb.pop_back();
    }
}


int main() {
    init();

    int n, m, temp;
    cin >> n >> m;

    set<int> nums_set;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums_set.insert(temp);
    }

    vector<int> nums;
    for (auto& num: nums_set) {
        nums.push_back(num);
    }

    vector<int> comb;
    solve(m, 0, nums, comb);
}