// https://www.acmicpc.net/problem/30804
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int fruits[N];
    int i, e;
    for (i = 0; i < N; i++) {
        cin >> fruits[i];
    }

    //i이상 e이하
    int cur, f = -1, s = -1, maxCount = -1;
    int lastNum = -1, lastIndex = -1;
    for (i = 0; i < N; i++) {
        if (N-i <= maxCount) { break; }
        f = fruits[i];
        s = -1;
        lastNum = f;
        lastIndex = i;

        for (e = i; e < N; e++) {
            cur = fruits[e];

            if (cur != f && cur != s) {
                if (s == -1) {
                    s = cur;
                    lastNum = s;
                    lastIndex = e;
                } else {
                    maxCount = max(maxCount, e - i);
                    i = lastIndex - 1;
                    break;
                }
            } else if (e == N-1) {
                maxCount = max(maxCount, e - i + 1);
            } else if (cur != lastNum) {
                lastNum = cur;
                lastIndex = e;
            }
        }
    }



    cout << (maxCount == -1 ? N : maxCount);
}