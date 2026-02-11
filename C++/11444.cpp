// https://www.acmicpc.net/problem/11444
#include <iostream>
#include <vector>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

long long mod = 1000000007;

pair<long long, long long> f(long long n) {
    if (n == 0) return {0, 1};

    auto [a, b] = f(n / 2);

    long long a2 = a * ((2*b - a + mod) % mod) % mod;
    long long b2 = (a * a % mod + b * b % mod) % mod;

    if (n % 2 == 0) return make_pair(a2, b2);
    return make_pair(b2, (a2 + b2) % mod);
}

int main() {
    init();

    long long n;
    cin >> n;

    cout << f(n).first;
}