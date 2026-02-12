// https://www.acmicpc.net/problem/18185
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    int d, ans = 0;
    for (int i = 0; i < n; i++) {
        if (i+2 < n) {
            if (i+3 != n || A[i+1] > A[i+2]) {
                d = min(A[i], A[i+1]-A[i+2]);
                if (d > 0) {
                    A[i] -= d; A[i+1] -= d;
                    ans += d*5;
                }
            } 
            d = min(min(A[i],A[i+1]),A[i+2]);
            if (d > 0) {
                A[i] -= d; A[i+1] -= d; A[i+2] -= d;
                ans += d*7;
            }
            

        }
        if (i+1 < n) {
            d = min(A[i],A[i+1]);
            if (d > 0) {
                A[i] -= d; A[i+1] -= d;
                ans += d*5;
            }
        }
        ans += A[i]*3;
    }

    cout << ans;
}