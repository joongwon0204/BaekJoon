// https://www.acmicpc.net/problem/1918
#include <iostream>
#include <stack>
#include <vector>
#include <stack>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int priority(char c) {
    if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    else return -1; // )
}

int main() {
    init();
    
    string str;
    cin >> str;

    stack<char> sk;

    for (auto c: str) {
        if (c >= 'A' && c <= 'Z') {
            cout << c;
        } else if (c == '(') {
            sk.push(c);
        } else if (c == ')' && !sk.empty()) {
            char t = sk.top();
            while (t != '(') {
                cout << t;
                sk.pop();
                t = sk.top();
            }
            sk.pop();
        } else {
            while (!sk.empty() && sk.top() != '(' && priority(sk.top()) >= priority(c)) {
                cout << sk.top();
                sk.pop();
            }
            sk.push(c);
        }
    }
    while (!sk.empty()) {
        cout << sk.top();
        sk.pop();
    }
}