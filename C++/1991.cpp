// https://www.acmicpc.net/problem/1991
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

void preorder(char cur, map<char, pair<char, char>>& children) {
    char left, right;
    left = children[cur].first;
    right = children[cur].second;

    cout << cur;
    if (left != '.') { preorder(left, children); }
    if (right != '.') { preorder(right, children); }
}

void inorder(char cur, map<char, pair<char, char>>& children) {
    char left, right;
    left = children[cur].first;
    right = children[cur].second;

    if (left != '.') { inorder(left, children); }
    cout << cur;
    if (right != '.') { inorder(right, children); }
}

void postorder(char cur, map<char, pair<char, char>>& children) {
    char left, right;
    left = children[cur].first;
    right = children[cur].second;

    if (left != '.') { postorder(left, children); }
    if (right != '.') { postorder(right, children); }
    cout << cur;
}

int main() {
    init();

    int n;
    cin >> n;

    map<char, pair<char, char>> children;
    char root, left, right;
    for (int i = 0; i < n; i++) {
        cin >> root >> left >> right;
        children[root] = make_pair(left, right);
    }

    preorder('A',children);
    cout << '\n';
    inorder('A',children);
    cout << '\n';
    postorder('A',children);
    cout << '\n';
}