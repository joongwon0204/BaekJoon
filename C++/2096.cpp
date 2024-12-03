// https://www.acmicpc.net/problem/2096
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int score[N+1][3];
    score[0][0] = 0;
    score[0][1] = 0;
    score[0][2] = 0;

    for (int i = 1; i <= N; i++) {
        cin >> score[i][0] >> score[i][1] >> score[i][2];
    }

    int max_score[2][3];
    max_score[0][0] = 0;
    max_score[0][1] = 0;
    max_score[0][2] = 0;
    for (int i = 1; i <= N; i++) {
        max_score[1][0] = score[i][0] + max(max_score[0][0], max_score[0][1]);
        max_score[1][1] = score[i][1] + max(max(max_score[0][0], max_score[0][1]), max_score[0][2]);
        max_score[1][2] = score[i][2] + max(max_score[0][1], max_score[0][2]);
        max_score[0][0] = max_score[1][0];
        max_score[0][1] = max_score[1][1];
        max_score[0][2] = max_score[1][2];
    }


    int min_score[2][3];
    min_score[0][0] = 0;
    min_score[0][1] = 0;
    min_score[0][2] = 0;
    for (int i = 1; i <= N; i++) {
        min_score[1][0] = score[i][0] + min(min_score[0][0], min_score[0][1]);
        min_score[1][1] = score[i][1] + min(min(min_score[0][0], min_score[0][1]), min_score[0][2]);
        min_score[1][2] = score[i][2] + min(min_score[0][1], min_score[0][2]);
        min_score[0][0] = min_score[1][0];
        min_score[0][1] = min_score[1][1];
        min_score[0][2] = min_score[1][2];
    }

    cout << max(max(max_score[0][0], max_score[0][1]), max_score[0][2]) << " " << min(min(min_score[0][0], min_score[0][1]), min_score[0][2]);

}