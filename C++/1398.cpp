// https://www.acmicpc.net/problem/1398
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

bool isPow100(long long n) {
    while(true) {
        if (n > 100) {
            n /= 100;
        } else {
            if (n % 100 == 0) return true;
            else return false;
        }
    }
}

bool isPow10(long long n) {
    while(true) {
        if (n > 10) {
            n /= 10;
        } else {
            if (n % 10 == 0) return true;
            else return false;
        }
    }
}
int main() {
    init();

    int T;
    cin >> T;

    vector<long long> dp()


    for (int i = 0; i < T; i++) {
        long long n;
        cin >> n;

        long long coin = 1000000000000000;

        long long ans = 0;
        while(n) {
            long long d = n / coin;
            if (d > 0) n -= d*coin;
            ans += d;

            if (isPow100(coin)) coin /= 4;
            else if (isPow10(coin)) coin /= 10;
            else coin = coin * 2 / 5;
        }

        cout << ans << (i != T-1 ? "\n" : "");
    }

}