// https://www.acmicpc.net/problem/9935
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    vector<char> stk;
    string str, explode;
    cin >> str >> explode;
    int explodeLen = explode.length();
    for (char c: str) {
        stk.push_back(c);
        if (stk.size() >= explodeLen) {
            bool flag = true;
            for (int i = 0; i < explodeLen; i++) {
                if (stk[stk.size() - explodeLen + i] != explode[i]) flag = false;
            }

            if (flag) {
                for (int _ = 0; _ < explodeLen; _++) {
                    stk.pop_back();
                }
            }
        }
        
    }

    if (stk.size() == 0) {
        cout << "FRULA";
    } else {
        for (char c: stk) {
            cout << c;
        }
    }
}