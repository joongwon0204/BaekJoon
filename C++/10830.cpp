// https://www.acmicpc.net/problem/10830
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;
using Mat = vector<vector<int>>;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

Mat mul(const Mat& a, const Mat& b, int n);

int main() {
    init();

    int n, tmp;
    long long b;
    cin >> n >> b;

    Mat mat(n, vector<int>(n));
    Mat res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        res[i][i] = 1;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            mat[i][j] = tmp;
        }
    }
    
    while (b > 0) {
        if (b % 2 != 0) {
            res = mul(res, mat, n);
        }
        mat = mul(mat, mat, n);
        b /= 2;
    }


    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            cout << res[i][j] << " ";
        }
        cout << res[i][n - 1] << "\n";
    }
}

Mat mul(const Mat& a, const Mat& b, int n) {
    Mat res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= 1000;
            }
        }
    }
    return res;
}