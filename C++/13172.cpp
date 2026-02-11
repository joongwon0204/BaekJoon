// https://www.acmicpc.net/problem/13172
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

long long mod = 1000000007;

long long fast_pow(long long a, long long e) {
    long long r = 1;
    while (e > 0) {
        if (e & 1) r = r * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return r;
}

int main() {
    int M;
    cin >> M;

    long long ans = 0;

    for (int i = 0; i < M; i++) {
        long long n, s;
        cin >> n >> s;
        long long g = gcd(n,s);
        n /= g;
        s /= g;

        ans += (s * fast_pow(n, mod-2)) % mod;
        ans %= mod;
    }

    cout << ans;
}