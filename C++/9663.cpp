// https://www.acmicpc.net/problem/9663
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int queen(vector<int>& x, vector<int>& rising_sum, vector<int>& falling_dif, int N) {
    int row_index = x.size();
    if (row_index == N) { return 1; }

    int ret = 0;

    for (int i = 0; i < N; i++) {
        if (count(x.begin(), x.end(), i) == 0 &&
            count(rising_sum.begin(), rising_sum.end(), i + row_index) == 0 &&
            count(falling_dif.begin(), falling_dif.end(), i - row_index) == 0 ) {
                x.push_back(i);
                rising_sum.push_back(i + row_index);
                falling_dif.push_back(i - row_index);
                ret += queen(x,rising_sum,falling_dif, N);
                x.pop_back();
                rising_sum.pop_back();
                falling_dif.pop_back();
        }
    }

    return ret;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> x;
    vector<int> rising_sum;
    vector<int> falling_dif;

    cout << queen(x, rising_sum, falling_dif, N);
}