// https://www.acmicpc.net/problem/17626
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int num[50001] = {0};
    int minCount = 10;
    int i, j;
    for (i = 1; i*i < 50000; i++) {
        num[i] = 1;
    }

    for (i = 1; i < 50001; i++) {
        minCount = 10;
        for (j = 1; j*j <= i; j++) {
            minCount = min(minCount, num[i-j*j]);
        }
        num[i] = minCount + 1;
    }

    int n;
    cin >> n;
    cout << num[n];
}