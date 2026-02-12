// https://www.acmicpc.net/problem/18186
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int n;
    long long b, c;
    cin >> n >> b >> c;

    vector<long long> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    if (b > c){
        long long d, ans = 0;
        for (int i = 0; i < n; i++) {
            if (i+2 < n) {
                if (i+3 != n || A[i+1] > A[i+2]) {
                    d = min(A[i], A[i+1]-A[i+2]);
                    if (d > 0) {
                        A[i] -= d; A[i+1] -= d;
                        ans += d*(b+c);
                    }
                } 
                d = min(min(A[i],A[i+1]),A[i+2]);
                if (d > 0) {
                    A[i] -= d; A[i+1] -= d; A[i+2] -= d;
                    ans += d*(b+c+c);
                }
                

            }
            if (i+1 < n) {
                d = min(A[i],A[i+1]);
                if (d > 0) {
                    A[i] -= d; A[i+1] -= d;
                    ans += d*(b+c);
                }
            }
            ans += A[i]*b;
        }

        cout << ans;
    } else {
        cout << accumulate(A.begin(), A.end(), 0LL) * b;
    }
}