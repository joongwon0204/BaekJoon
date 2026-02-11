// https://www.acmicpc.net/problem/9466
#include <iostream>
#include <vector>

using namespace std;

long long fast_pow(long long a, long long e) {
    long long r = 1;
    while (e > 0) {
        if (e & 1) r = r * a; // 오버플로 가능
        a = a * a;
        e >>= 1;
    }
    return r;
}