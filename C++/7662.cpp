// https://www.acmicpc.net/problem/7662
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int t, k;
    cin >> t;

    for (int j = 0; j < t; j++) {
        cin >> k;
        
        char command;
        int num;
        multiset<int> s;
        for (int i = 0; i < k; i++) {
            cin >> command >> num;

            if (command == 'I') {
                s.insert(num);
            } else {
                if (s.empty()) {
                    continue;
                } else if (num == -1) {
                    s.erase(s.begin());
                } else {
                    s.erase(prev(s.end()));
                }
            }
        }

        if (s.empty()) {
            cout << "EMPTY" << '\n'; 
        } else { 
            cout << *prev(s.end()) << ' ' << *s.begin() << '\n';
        }
    }
}