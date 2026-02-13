// https://www.acmicpc.net/problem/1377
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

void swap(vector<int>& A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int main() {
    init();
    
    int N;
    cin >> N;

    vector<pair<int,int>> A(N);
    for (int i = 0; i < N; i++) {
        A[i].second = i;
        cin >> A[i].first;
    }

    sort(A.begin(), A.end());

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, A[i].second - i);
    }
    cout << ++ans;
}